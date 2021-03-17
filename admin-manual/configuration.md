## Configure Appliance

The Appliance is configured using a yaml configuration file
which can be placed in one of the following locations:

+ local file at `/app/env.yml` (no-cloud config)
+ a attached drive with label cidata (cloud-init: no-cloud)
+ a attached drive with label config-2 (cloud-init: openstack)
+ aws-ec2 meta-data server (amazon elastic computing cloud)
+ gce meta-data server (google compute engine)

It will be copied to `/run/active-env.yml` (ramdisk) on each appliance startup.

**warning**: Do **not** reuse an already existing configuration for a different domain/instance, **always** create a new configuration, to not leak secrets between domains.

### Create a new Configuration

on an installed but unconfigured appliance:

+ enter installed but empty appliance
+ make a new env.yml: `env-create.sh *domainname.domain* /app/env.yml`
+ edit settings in "/app/env.yml", see comments inside file
+ Optional: package env into different formats
    + `env-package.sh --requirements; env-package.sh /app/env.yml`
    + see `env-package.sh` for more options
    + transfer, print out "/app/env.yml.pdf" and store in a safe place.
+ save an encrypted copy of env.yml in a safe place.
+ **Important**: The **env.yml contains all needed secrets** for a working appliance and is **the only relevant piece of information** if you want to recover from backup in case of a storage failure.
+ **Warning**: Only use ascii charset in env.yml, saltstack expects yaml in ascii charset

for offline environment creation, using your local machine:

+ have saltstack installed (minion does not need to run)
+ `git clone https://github.com/ecs-org/ecs-appliance  ~/path-to-project/ecs-appliance`
+ use env-create.sh and env-package.sh like explained below,
    but add ~/path-to-project/ecs-appliance/salt/common/ to the callpath.
+ copy ~/*domainname.domain*/env.yml to appliance machine at /app/env.yml

```
ssh root@target.vm.ip '/bin/bash -c "mkdir -p /app/"'
scp env.yml root@target.vm.ip:/app/env.yml
```

for a development server:

+ run `cp /app/appliance/salt/pillar/default-env.sls /app/env.yml` and edit settings in "/app/env.yml".

### Modify Configuration

Any applied change in the config file will reconfigure the appliance on the next appliance restart run to the new values found in the configuration.

Eg. if you want to change your backup target to a different location,
just change the value and restart the appliance, it will detect and configure
all needed changes to the environment.

See the comments in the configuration for different possibilities for the appliance configuration.

"gpg_secret", "base64_secret", "rsa_secret" are placeholder which will be generated with the corresponding data on environment creation using `env-create.sh`. see `salt/appliance/env-template.yml` for details on the creation procedure.

```
#cloud-config
# XXX keep the "#cloud-config" line first and unchanged, software expects this header

ssh_authorized_keys:
  # # you can put your ssh keys here, this is also used by cloud-init
  # - "ssh-rsa and some long glibberish somebody@somewhere"
ssh_deprecated_keys:
  # # you can copy deprecated keys here,
  # # state.highstate will remove these keys from allowed login,
  # # additionaly this section serves as log of past access keys
  # - "ssh-rsa and some long glibberish somebody@somewhere"
disable_root: false
# disable_root set to false for cloud-init compatibility, appliance expects root to be usable

appliance:
  # # standby: default false, if set appliance will not activate
  # standby: true
  domain: {{ domain }}
  allowed_hosts: {{ domain }}
  ssl:
    letsencrypt:
      enabled: true
    # # client_certs_mandatory, default false, if true, always need a client certificate
    # client_certs_mandatory: true
    client_certs_mandatory: false
    # # key: if set ssl key for https host will be used, default empty
    # key: filename-key.pem
    # # cert: if set ssl key for https host will be used, default empty
    # cert: filename-cert.pem
  # # sentry:dsn set to your sentry url, may be the same as ecs:settings:SENTRY_DSN
  # sentry:
  #   dsn: 'https://url'
  # metric:
  #   exporter: false
  #   server: false
  #   gui: false
  #   pghero: false
  # git:
  #   # default see appliance.include
  #   branch: master
  #   source: git_url
  # extra:  # write out extra files on appliance configure
  #   files:
  #     - path: /path/of/filename
  #       contents: |
  #           # Your content here
  #       owner: user:group
  #       permissions: "0600"
  #   packages: # include extra packages at state.highstate
  #     - qrcode
  #   # states: # string to be executed as a salststack sls at state.highstate
  #   # # warning: syntax and execution errors will break initial deployment and appliance-update
  #   states: |
  #       testing:
  #         pkg.installed:
  #           - name: curl
  # # update:oncalendar: # set a different update timer than default: "*-*-* 06:30:00"
  # # update:automatic: # default to true, to disable automatic update set to false
  # # XXX: do not update in the time between 00:30 and 06:30 because backup runs at this time
  # update:
  #   automatic: true
  #   oncalendar: Sun *-*-* 06:30:00
  storage:
    # # setup: optional, will be executed by appliance.storage.setup if volatile or data can not be found
    # setup: |
    # proxy_cache: true
    # # default false, if true 10 additional GB diskspace are used
    # # for operating polipo, a http proxy cache
    ignore: # default false, if true: will not look for ecs-volatile or ecs-data filesystem
      volatile: true
      data: true
  dkim:
    key: |
{{ rsa_secret()|indent(8,True) }}
  backup:
    url: file:///volatile/ecs-backup-test/
    # options: "string of options directly passed to duplicity"
    # # mount default empty, script will mount & unmount source to target on backup run
    # mount:
    #   type: "cifs"
    #   source: "//1.2.3.4/datavolume"
    #   target: "/mnt/appliance-backup-mount"
    #   options: "user=username,pass=password"
    # # options are passed to mount via "-o"
    encrypt: |
{{ gpg_secret('ecs_backup')|indent(8,True) }}

ecs:
  # git: # default see appliance.include
  #   branch: stable
  #   source: git_url
  userswitcher:
    enabled: false
    # set userswitcher to enabled on a test instance to change to different users
  settings: |
      DOMAIN = '{{ domain }}'
      ABSOLUTE_URL_PREFIX = 'https://{}'.format(DOMAIN)
      ALLOWED_HOSTS = [DOMAIN, ]
      PDFAS_SERVICE = ABSOLUTE_URL_PREFIX+ '/pdf-as-web/'
      # use PDFAS_SERVICE = "mock:" for mock signing
      SECURE_PROXY_SSL = True
      ECS_REQUIRE_CLIENT_CERTS = True
      DEBUG = False
      # SENTRY_DSN = 'https://url' # set to sentry url if available
      ETHICS_COMMISSION_UUID = 'ecececececececececececececececec'
      # set ETHICS_COMMISSION_UUID to the desired UUID of the target commission

      SECRET_KEY = '{{ base64_secret() }}'
      REGISTRATION_SECRET = '{{ base64_secret() }}'
      PASSWORD_RESET_SECRET = '{{ base64_secret() }}'

      EMAIL_BACKEND = 'django.core.mail.backends.console.EmailBackend'
      EMAIL_BACKEND_UNFILTERED = 'django.core.mail.backends.smtp.EmailBackend'
      EMAIL_UNFILTERED_DOMAINS = () # = ('example.com',)
      EMAIL_UNFILTERED_INDIVIDUALS = () # = ('ada@example.org', 'tom@example.com')

      SMTPD_CONFIG['listen_addr'] = ('0.0.0.0', 8025)
      SMTPD_CONFIG['domain'] = DOMAIN

      # EMAIL_BACKEND_UNFILTERED will be used for
      #  User registration & invitation, password reset, send client certificate,
      #  and all mails to domains in EMAIL_UNFILTERED_DOMAINS and user
      #  listed in EMAIL_UNFILTERED_INDIVIDUALS will be sent via
      #  EMAIL_BACKEND_UNFILTERED. All other mail will be sent via EMAIL_BACKEND.
      #
      # Backend to use to NOT sent email but log email to console:
      #   django.core.mail.backends.console.EmailBackend
      #
      # Backend to use to send via EMAIL_* smtp settings:
      #   django.core.mail.backends.smtp.EmailBackend
      #

  vault_encrypt: |
{{ gpg_secret('ecs_mediaserver')|indent(6,True) }}

  vault_sign: |
{{ gpg_secret('ecs_authority')|indent(6,True) }}

```

### Selecting the Ethics Commission UUID

```
| 23d805c6b5f14d8b9196a12005fd2961 | Ethikkommission der Medizinischen Universität Wien
| 7b51f38bde8a4161a0dc34647fc7e654 | Ethikkommission Krankenhaus Barmh.Brüder - Wien
| 85dc386061584fbe8549ce4e4d828fbd | Ethikkommission der Stadt Wien gemäß KAG, AMG und MPG
| d6a22c635a584521b107481ac18318f6 | Ethikkommission Forschungsinstitut des Wiener Roten Kreuzes
| 55ae93ec9df04d6abfc8d233ec5ccf8e | Nicht verwenden: Ethikkommission Krankenhaus Barmh.Schwestern - Wien
| 7cd6d52120b3474ba502931b9f60a5f3 | Ethikkommission Confraternität-Priv.Klin. Josefstadt und Priv.Klin. Döbling
| 7df9ebaf15434709b09c3def9a6c8769 | Ethikkommission St.Anna Kinderspital
| f122f144616541d391fde2dcc761aff4 | Ethikkommission Österreichische Arbeitsgemeinschaft für Klinische Pharmakologie
| 25b6744780434a3f96a1e43b405d3848 | Ethikkommission Privatkrankenanstalt Rudolfinerhaus
| d542994ced34403db841786a1c1ab892 | Ethikkommission Rheuma-Zentrum Wien-Oberlaa
| 5615dfbaf8c8445d960d1e2cd9c00dc3 | Nicht verwenden: Ethikkommission Krankenhaus des Göttlichen Heilandes
| 4d3a2d5f138940f293ee87fe6ec1d5b2 | Ethikkommission Evangelisches Krankenhaus
| 8d2950e3a0294f68bde647a54df6d823 | Ethikkommission der Allgemeinen Unfallversicherungsanstalt
| 9f6b509e716e413f865d95bdd630e9bc | Ethikkommission Immunologische Tagesklinik
| b17f32f604fa4452b5ff3a2baa9e0704 | Ethikkommission des Landes Niederösterreich
| 6688ce16a3b84d42b1531389e6039891 | Ethikkommission Krankenhaus Elisabethinen
| e4dcd05a31ad475ca72dea7b84ef030e | Ethikkommission der Medizinischen Fakultät der JKU
| e269491bb9c040aaad6a5f11df343f38 | Ethikkommission Krankenhaus Barmh.Brüder - Linz
| 1cca34032077445d95dabf7802fade28 | Ethikkommission Krankenhaus Barmh.Schwestern - Linz
| 39cbb589ef044d27bceb6ee5ac796ae7 | Ethikkommission für das Bundesland Salzburg
| 280414583b894c809a9baa8134d7fe4b | Ethikkommission der Medizinischen Universität Innsbruck
| 183881da8200493aa7edd8bebeea75b9 | Ethikkommission des Landes Vorarlberg
| 95821eba88f34b2195f96e747d7f6b16 | Ethikkommission des Landes Burgenland gemäß KAG, AMG und MPG
| 6e7cfab5f8cd40df83c9de4fac9bb20f | Ethikkommission des Landes Steiermark gemäß AMG und MPG
| 75b5a9714f354a5b842aa01029148036 | Ethikkommission Krankenhaus Barmh.Brüder - Graz
| 9287fb0878b94f9f9d90b5582d1cefca | Ethikkommission Krankenhaus Barmh.Brüder - Eggenberg
| e17ee744e4e840778f316cf3f79de6b4 | Ethikkommission der Medizinischen Universität Graz
| ec9f179a52a04a7aa52446232c3fd4bd | Ethikkommission des Landes Kärnten
| c890205dcb7543c8a76bf324512c5f81 | Nicht verwenden: Ethikkommission des Krankenhaus St. Josef
| dc1b115d9809461ba3ea9450b079ddd6 | Kommission für Scientific Integrity und Ethik der Karl Landsteiner Privatuniversität
| 50dba0126a0746dc8802e6c0e0199dad | Ethik-Kommission der Vinzenz Gruppe Wien
```


### Automatic Update Setup

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

+ Backup is done using duplicity, see [Duplicity Manual](http://duplicity.nongnu.org/duplicity.1.html) and [duply](http://duply.net/wiki/index.php/Duply-documentation)
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

#### Extra Configuration needed for scp/sftp backup (ssh)

if appliance:backup:url is using either scp or sftp (preferred):

+ add ssh host entry in /root/.ssh/known_hosts for duplicity to connect to the ssh server
+ create this entry by executing: `duply /root/.duply/appliance-backup status`
+ add this key to env.yml as extra:state:
```
appliance:
  extra:
    states: |
        sftp_server_hostkey_into_known_hosts:
          file.append:
            - name: /root/.ssh/known_hosts
            - makedirs: true
            - text: |
                [1.2.3.4]:12345 ssh-rsa XXXHOSTKEYXXX
```


### Metrics Collection Setup

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
    + there are alerts for: NodeRebootsTooOften, NodeFilesystemFree, NodeMemoryUsageHigh, NodeLoadHigh, a.o.
        + for a detailed alert list look at the [alert.rules.yml sourcefile](https://github.com/ecs-org/ecs-appliance/blob/master/salt/appliance/metric/alert.rules.yml)
        + to **add custom rules create rules** files in the config yaml using "file:*:contents" with a path of "/app/etc/prometheus-rules.d/*.rules.yml"
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


### First Activation

on the target vm:
```
# create a empty ecs database
sudo -u postgres createdb ecs -T template0  -l de_DE.utf8

# activate env
chmod 0600 /app/env.yml
cp /app/env.yml /run/active-env.yml

# apply new environment settings and start service
systemctl restart appliance
```

While restarting, the appliance configures itself to the new environment.
See the progress of the preperation by browsing to https://*domainname.domain* .

#### First Internal User setup

After the appliance is ready and shows the login screen, login via ssh to create
the first internal office user, with a corresponding client certificate and disable test user.

```
# create first internal office user (f=female, m=male)
create-internal-user.sh useremail@domain.name "First Name" "Second Name" "f"

# create and send matching client certificate
create-client-certificate.sh useremail@domain.name cert_name [daysvalid(default=7)]
# Communicate certificate transport password over a secure channel

# disable test user
cat << EOF | docker exec -i ecs_ecs.web_1 /start run ./manage.py shell
from django.contrib.auth.models import User
User.objects.filter(profile__is_testuser=True).update(is_active=False)
EOF

```

After completing the First User Setup, import the created Client Certificate into a browser and login as Internal User and continue to configure the ECS as described in the [User-Manual, Chapter Commissioning](https://ecs-org.github.io/ecs-docs/user-manual-de/commission/commissioning.html)
