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

### Reviewing the Logs

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

### Desaster Recovery from backup

+ install a new unconfigured appliance as described in chapter install
+ copy old saved env.yml to new target machine at /app/env.yml
+ reboot new target machine, appliance will configure but stop because of empty database
+ ssh into new target machine, execute `recover-from-backup.sh --yes-i-am-sure`

### Searching for and restoring specified files from backup

+ List all files in current backup
```
duply /root/.duply/appliance-backup list
```

+ Restore database dump of last backup run to /root
```
# exclude backup source base directory from requested file path
# eg. requested file is "/data/ecs-pgdump/ecs.pgdump.gz"
# filename should be "ecs-pgudump/ecs.pgdump.gz"
duply /root/.duply/appliance-backup fetch ecs-pgdump/ecs.pgdump.gz /root/ecs.pgdump.gz
```

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

+ send sentry test entry:

    + using bash and ravencat.py
```
. /usr/local/share/appliance/env.include; . /usr/local/share/appliance/appliance.include; ENV_YML=/run/active-env.yml userdata_to_env ecs,appliance; sentry_entry "test" "Test Message $(hostname -f)"
```
    + using a django management command
```
docker exec -it ecs_ecs.web_1 /start run /bin/bash
./manage.py raven test
```

+ most time spent in state.highstate:
    + `journalctl -u appliance-update | grep -B 5 -E "Duration: [0-9]{3,5}\."`
    + `journalctl -u appliance-update | grep "ID:" -A6 | grep -E "(ID:|Function:|Duration:)" | sed -r "s/.*(ID:|Function:|Duration)(.*)/\1 \2/g" | paste -s -d '  \n'  - | sed -r "s/ID: +([^ ]+) Function: +([^ ]+) Duration : ([^ ]+ ms)/\3 \2 \1/g" |sort -n`

+ check send emails from postfix
    + `for a in sent deferred bounced; do echo "#### $a"; journalctl -u postfix | grep "status=$a" | awk '{print $7}' | sed 's/to=<//g' | sed 's/>,//g' | sort -n; done`

+ check for incoming or outgoing smtp from ecs
    + `journalctl -u appliance --since "2019-07-27" | grep -Ei "ecs.(worker_1|smtpd_1).+(Accepted email|Rejected email|Forward |Forwarding|Not forwarding|email raised exception|Invalid message format|Relay access denied)"  | sed -r "s/([^ ]+ [^ ]+ [0-9:]+ ).*ecs.communication.tasks.forward_messages\[[0-9a-f-]+\]:(.*)/\1\2/g" | sed -r "s/([^ ]+ [^ ]+ [0-9:]+ ).+ecs.smtpd_1.+INFO (.*)/\1 \2/g"`

+ ip adress config
    + `ip -o addr show | grep -Ev "veth[0-9a-f]{7}"; default_iface=$(awk '$2 == 00000000 { print $1 }' /proc/net/route); default_ip=$(ip addr show dev "$default_iface" | awk '$1 == "inet" { sub("/.*", "", $2); print $2 }'); echo "Default Interface: $default_iface , Default IP: $default_ip`
