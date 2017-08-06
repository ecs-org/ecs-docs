## Maintenance

### Reconfigure a running Appliance

+ edit /app/env.yml
+ optional, build new env package:
    + first time requisites install, call `env-package.sh --requirements`
    + build new env package call `env-package.sh /app/env.yml`
+ activate changes into current environment, call `env-update.sh`
+ restart and apply new environment: `systemctl restart appliance`

### Start, Stop, Update Appliance

+ Start appliance: `systemctl start appliance`
+ Stop appliance: `systemctl stop appliance`
+ Update Appliance (appliance and ecs): `systemctl start appliance-update`

### Recover from failed state

if the appliance.service enters fail state, it creates a file named
"/run/appliance_failed".

After resolving the issue, remove this file using `rm /run/appliance_failed`
before restarting the service using `systemctl restart appliance`.

If the issue was within the ecs-appliance sourcecode, re-run an appliance update:
```
rm /run/appliance-failed
touch /app/etc/flags/force.update.appliance
systemctl restart appliance-update
```

### Desaster Recovery from backup

+ install a new unconfigured appliance as described in chapter install
+ copy old saved env.yml to new target machine at /app/env.yml
+ reboot new target machine, appliance will configure but stop because of empty database
+ ssh into new target machine, execute `recover-from-backup.sh --yes-i-am-sure`

### Automatic Updates

Updates are scheduled depending appliance:update:oncalendar once per day at 06:30 per default.

Depending the types of updates available the update will take between 1 and 5 minutes in most cases, 5-10 minutes if the ecs container will be rebuild and up to 30 minutes if there are database migrations to be executed.

The following items are updated:
+ appliance source will be updated and executed
+ all system packages are updated, special precautions are taken for docker, postgresql and the kernel including a reboot if needed
+ lets encrypt certificates are updated
+ ecs source will be updated and rebuild
    + the ecs-docs source will be updated
    + the corresponding support container will be updated
    + database migrations will be executed (including a dump before doing so)

**Warning**: Automatic updates are intended to run with Metric and Alert support, so you will get alerts to react and can investigate using the Metric Server to find the root cause. **If you do not make metric recording and alerting, we recommend updating only manual.** To do this, enter "False" under appliance:update:automatic in the file env.yml. For a manual update run call `systemctl start appliance-update`

### Backup Configuration

+ Backup is done using duplicity, see [Duplicity Manual](http://duplicity.nongnu.org/duplicity.1.html)
+ Cycle: Backup is done once per day around 00:30
+ Safety Measures for backup:
  + Database must exist
  + Storage-Vault must not be empty
+ Contents: 
  + /data/ecs-storage-vault: All uploaded and all created documents
  + /data/ecs-pgdump: Current database dump
+ Type, Rotation & Retention:
    + Backup will start with a full backup and do incremental backups afterwards
    + 2 Months after the first full backup a second full backup will be created
    + Rotation: Every Backup (full or incremental) will be purged after 4 Months

### Logging Configuration

Container:
+ all container log to stdout and stderr
+ docker has the logs of every container available
    + look at a log stream using eg. `docker logs ecs_ecs.web_1`
+ journald will get the container logs via the appliance.service which calls docker-compose
    + this includes backend nginx, uwsgi, beat, worker, smtpd, redis, memcached, pdfas, mocca
    + to follow use `journalctl -u appliance -f`

Host:
+ all logging (except postgres) is going through journald
+ follow whole journal: `journalctl -f`
+ only follow service, eg. prepare-appliance: `journalctl -u prepare-appliance -f`
+ follow frontend nginx: `journalctl -u nginx -f`
+ search for salt-call output: `journalctl $(which salt-call)`

### Metrics Collection

+ if `appliance:metric:exporter` is set, metrics are exported from the subsystems
    + export metrics of: 
        frontend nginx, redis, memcached, uwsgi, cadvisor,
        process details(uwsgi, postgres, nginx, celery), 
        prometheus node(diskstats, entropy, filefd, filesystem, hwmon, loadavg,
            mdadm, meminfo, netdev, netstat, stat, textfile, time, uname, vmstat)
    + additional service metrics from: appliance-backup, appliance-update
+ if `appliance:metric:server` is set, these exported metrics are collected and 
    stored by a prometheus server and alerts are issued using email to root
    using the prometheus alert server
    + there are alerts for: NodeRebootsTooOften, NodeFilesystemFree, NodeMemoryUsageHigh, NodeLoadHigh
        + for a detailed alert list look at the [alert.rules sourcefile](https://github.com/ecs-org/ecs-appliance/blob/master/salt/appliance/metric/alert.rules)
    + the prometheus gui is at [http://172.17.0.1:9090](http://172.17.0.1:9090)
    + the prometheus alert gui is at [http://172.17.0.1:9093](http://172.17.0.1:9093)
+ if `appliance:metric:gui` is set, a grafana server is started to display the collected metrics
    + grafana is available at [http://localhost:3000](http://localhost:3000)
+ if `appliance:metric:pghero` is set, start a pghero instance for postgres inspection
    + pghero is avaiable at [http://localhost:5081](http://localhost:5081)

Use ssh port forwarding to access these ports, eg. for 172.17.0.1:9090 use `ssh root@hostname -L 9090:172.17.0.1:9090`

### Alerting Setup

if `ecs:settings["SENTRY_DSN"]` and `appliance:sentry:dsn` are defined,
the appliance will report the following items to sentry:

+ python exceptions in web, worker, beat, smtpd
+ salt-call exceptions and state returns with error states
+ systemd service exceptions where appliance-failed or service-failed is triggered
+ shell calls to appliance.include: appliance_failed, appliance_exit, sentry_entry
+ internal mails to root, eg. prometheus alerts

### Email Challenges

#### Mail send from ECS to Emailserver doing greylisting

Issue:
Emails send from the appliance to a target mailserver that does greylisting will always be delayed. 

Resolution:
To remove those delays, the greylisting whitelist of the target mailserver has to be extended with the domain of the ecs appliance.

Technical Background:
The appliance always uses a new unique email address for each outgoing mail (beside registration) and greylisting always delays the first email from an email address.

### Maintenance commands in a running ecs container
for most ecs commands it is not important to which instance (web,worker) 
you connect to, "ecs_ecs.web_1" is used as example. 

+ image = ecs, mocca, pdfas, memcached, redis
+ ecs.startcommand = web, worker, beat, smtpd
+ as root `docker exec -it ecs_image[.startcommand]_1 /path/to/command`
    + eg. `docker exec -it ecs_ecs.web_1 /bin/bash`


+ shell as app user with activated environment
    + `docker exec -it ecs_ecs.web_1 /start run /bin/bash`
+ manualy create a celery task:
    + `docker exec -it ecs_ecs.web_1 /start run celery --serializer=pickle -A ecs call ecs.integration.tasks.clearsessions`
+ celery events console
    + `docker exec -it ecs_ecs.web_1 /start run /bin/bash -c "TERM=screen celery -A ecs events"`
+ enter a django shell_plus as app user in a running container
    + `docker exec -it ecs_ecs.web_1 /start run ./manage.py shell_plus`

+ generate all workflow graphs

```
docker exec -it ecs_ecs.web_1 /start run /bin/bash
./manage.py workflow_dot core.submission | dot -Tpng -osubmission.png
./manage.py workflow_dot notifications.notification | dot -Tpng -onotification.png
./manage.py workflow_dot votes.vote | dot -Tpng -ovote.png
```

+ generate ECX-Format Documentation

```
docker exec -it ecs_ecs.web_1 /start run /bin/bash
./manage.py ecx_format -t html -o ecx-format.html
./manage.py ecx_format -t pdf -o ecx-format.pdf
```

### Maintenance commands for the appliance host

All snippets expect root.

+ destroy and recreate database:

```
gosu app dropdb ecs
gosu postgres createdb ecs -T template0 -l de_DE.utf8
rm /app/etc/tags/last_running_ecs
systemctl restart appliance
```

+ get latest dump from backup to /root/ecs.pgdump.gz:
    + `duply /root/.duply/appliance-backup fetch ecs-pgdump/ecs.pgdump.gz /root/ecs.pgdump.gz`

+ quick update appliance code:
    + `cd /app/appliance; gosu app git pull; salt-call state.highstate pillar='{"appliance":{"enabled":true}}' 2>&1; rm /var/www/html/503.html`

+ check which system packages are available for update:
    + `/usr/lib/update-notifier/apt-check -p`

+ cleanup last activity stamps for unattended upgrades, so unattended-upgrades will do all activity again
    + `touch /app/etc/flags/force.update.system` before `systemctl start appliance-update`

+ list active systemd timer: `systemctl list-timers --all`

+ display systemd service change: `journalctl -m _PID=1 -f`

+ manual run letsencrypt client (do not call as root): `gosu app dehydrated --help`

+ display revoked certificates serials: 
    + `openssl crl -inform PEM -text -noout -in /app/etc/crl.pem`
  
+ get cummulative cpu,mem,net,disk statistics of container:
    + `docker stats $(docker ps|grep -v "NAMES"|awk '{ print $NF }'|tr "\n" " ")`

+ read details of a container in yaml:
    + `docker inspect 1b17069fe3ba | python -c 'import sys, yaml, json; yaml.safe_dump(json.load(sys.stdin), sys.stdout, default_flow_style=False)' | less`

+ activate /run/active-env.yml in current shell of appliance vm:
    + `. /usr/local/share/appliance/env.include; ENV_YML=/run/active-env.yml userdata_to_env ecs,appliance`
    + to also set *GIT_SOURCE defaults: `. /usr/local/share/appliance/appliance.include` 

+ most time spent in state.highstate:
    + `journalctl -u appliance-update | grep -B 5 -E "Duration: [0-9]{3,5}\."`
    + `journalctl -u appliance-update | grep "ID:" -A6 | grep -E "(ID:|Function:|Duration:)" | sed -r "s/.*(ID:|Function:|Duration)(.*)/\1 \2/g" | paste -s -d '  \n'  - | sed -r "s/ID: +([^ ]+) Function: +([^ ]+) Duration : ([^ ]+ ms)/\3 \2 \1/g" |sort -n`

+ check send emails
    + `for a in sent deferred bounced; do echo "#### $a"; journalctl -u postfix | grep "status=$a" | awk '{print $7}' | sed 's/to=<//g' | sed 's/>,//g' | sort -n; done`

+ ip adress config
    + `ip -o addr show | grep -Ev "veth[0-9a-f]{7}"; default_iface=$(awk '$2 == 00000000 { print $1 }' /proc/net/route); default_ip=$(ip addr show dev "$default_iface" | awk '$1 == "inet" { sub("/.*", "", $2); print $2 }'); echo "Default Interface: $default_iface , Default IP: $default_ip`
  