## Maintenance

### Reconfigure a running Appliance

+ edit /app/env.yml
+ optional, build new env package:
    + first time requisites install, call `env-package.sh --requirements`
    + build new env package call `env-package.sh /app/env.yml`
+ activate changes into current environment, call `env-update.sh`
+ restart and apply new environment: `systemctl start appliance-update`

### Start, Stop & Update Appliance

+ Start appliance: `systemctl start appliance`
+ Stop appliance: `systemctl stop appliance`
+ Update Appliance (appliance and ecs): `systemctl start appliance-update`

#### Recover from failed state

if the appliance.service enters fail state, it creates a file named
"/run/appliance_failed".

After resolving the issue, remove this file using `rm /run/appliance_failed`
before running the service again using `systemctl restart appliance`.

### Desaster Recovery from backup

+ install a new unconfigured appliance as described in chapter install
+ copy old saved env.yml to new target machine at /app/env.yml
+ reboot new target machine, appliance will configure but stop because of empty database
+ ssh into new target machine, execute `recover-from-backup.sh --yes-i-am-sure`

### Howto

All snippets expect root.

+ enter a running ecs container
    for most ecs commands it is not important to which instance (web,worker) 
    you connect to, "ecs_ecs.web_1" is used in examples

    + image = ecs, mocca, pdfas, memcached, redis
    + ecs .startcommand = web, worker, beat, smtpd

    + as root `docker exec -it ecs_image[.startcommand]_1 /bin/bash`
        + eg. `docker exec -it ecs_ecs.web_1 /bin/bash`
    + shell as app user with activated environment
        + `docker exec -it ecs_ecs.web_1 /start run /bin/bash`
    + manualy create a celery task:
        + `docker exec -it ecs_ecs.web_1 /start run celery --serializer=pickle -A ecs call ecs.integration.tasks.clearsessions`
    + celery events console
        + `docker exec -it ecs_ecs.web_1 /start run /bin/bash -c "TERM=screen celery -A ecs events"`
    + enter a django shell_plus as app user in a running container
        + `docker exec -it ecs_ecs.web_1 /start run ./manage.py shell_plus`

+ make all workflow graphs (with activated environment)

```
./manage.py workflow_dot core.submission | dot -Tpng -osubmission.png
./manage.py workflow_dot notifications.notification | dot -Tpng -onotification.png
./manage.py workflow_dot votes.vote | dot -Tpng -ovote.png
```

+ generate ECX-Format Documentation (with activated environment)

```
./manage.py ecx_format -t html -o ecx-format.html
./manage.py ecx_format -t pdf -o ecx-format.pdf
```

+ manual run letsencrypt client (do not call as root): `gosu app dehydrated --help`

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
    + `cd /app/appliance; gosu app git pull; salt-call state.highstate pillar='{"appliance":{"enabled":true}}'; rm /var/www/html/503.html`

+ get cummulative cpu,mem,net,disk statistics of container:
    + `docker stats $(docker ps|grep -v "NAMES"|awk '{ print $NF }'|tr "\n" " ")`

+ read details of a container in yaml:
    + `docker inspect 1b17069fe3ba | python -c 'import sys, yaml, json; yaml.safe_dump(json.load(sys.stdin), sys.stdout, default_flow_style=False)' | less`

+ activate /run/active-env.yml in current shell of appliance vm:
    + `. /usr/local/share/appliance/env.include; ENV_YML=/run/active-env.yml userdata_to_env ecs,appliance`
    + to also set *GIT_SOURCE defaults: `. /usr/local/share/appliance/appliance.include` 

+ untested:
    +  `docker-compose -f /app/etc/ecs/docker-compose.yml run --no-deps ecs.web run ./manage.py shell_plus`
    + most spent time in high.state:
        + `journalctl -u appliance-update | grep -B 5 -E "Duration: [0-9]{3,5}\."`
        + `journalctl -u appliance-update | grep "ID:" -A6 | grep -E "(ID:|Function:|Duration:)" | sed -r "s/.*(ID:|Function:|Duration)(.*)/\1 \2/g" | paste -s -d '  \n'  - | sed -r "s/ID: +([^ ]+) Function: +([^ ]+) Duration : ([^ ]+ ms)/\3 \2 \1/g" |sort -n`

### Logging

Container:
+ all container log to stdout and stderr
+ docker has the logs of every container available
    + look at a log stream using eg. `docker logs ecs_ecs.web_1`
+ journald will get the container logs via the appliance.service which calls docker-compose
    + this includes backend nginx, uwsgi, beat, worker, smtpd, redis, memcached, pdfas, mocca
    + to follow use `journalctl -u appliance -f`

Host:
+ (nearly) all logging is going through journald
+ follow whole journal: `journalctl -f`
+ only follow service, eg. prepare-appliance: `journalctl -u prepare-appliance -f`
+ follow frontend nginx: `journalctl -u nginx -f`
+ search for salt-call output: `journalctl $(which salt-call)`

### Alerting

if ECS_SETTINGS_SENTRY_DSN and APPLIANCE_SENTRY_DSN is defined,
the appliance will report the following items to sentry:

+ python exceptions in web, worker, beat, smtpd
+ salt-call exceptions and state returns with error states
+ systemd service exceptions where appliance-failed is triggered,
    or appliance_failed, appliance_exit, sentry_entry is called
+ internal mails to root, eg. prometheus alerts, smartmond

### Metrics

+ if APPLIANCE_METRIC_EXPORTER is set, metrics are exported from the subsystems
    + export metrics of: 
        frontend nginx, redis, memcached, uwsgi, cadvisor,
        process details(uwsgi, postgres, nginx, celery), 
        prometheus node(diskstats, entropy, filefd, filesystem, hwmon, loadavg,
            mdadm, meminfo, netdev, netstat, stat, textfile, time, uname, vmstat)
    + additional service metrics from: appliance-backup, appliance-update
+ if APPLIANCE_METRIC_SERVER is set, these exported metrics are collected and 
    stored by a prometheus server and alerts are issued using email to root
    using the prometheus alert server
    + there are alerts for: NodeRebootsTooOften, NodeFilesystemFree, NodeMemoryUsageHigh, NodeLoadHigh
    + the prometheus gui is at [http://172.17.0.1:9090](http://172.17.0.1:9090)
    + the prometheus alert gui is at [http://172.17.0.1:9093](http://172.17.0.1:9093)
+ if APPLIANCE_METRIC_GUI is set, start a grafana server for displaying the collected metrics
    + grafana is available at [http://localhost:3000](http://localhost:3000)
+ if APPLIANCE_METRIC_PGHERO is set, a pghero instance for postgres inspection
    + pghero is avaiable at [http://localhost:5081](http://localhost:5081)

Use ssh port forwarding to access these ports, eg. for 172.17.0.1:9090 use "ssh root@hostname -L 9090:172.17.0.1:9090"
