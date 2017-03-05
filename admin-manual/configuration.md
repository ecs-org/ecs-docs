## Configure Appliance

The Applinace is configured using a yaml confiuration file 
which can be placed in one of the following locations:

+ absolute filepath set via environment variable ENV_YML
+ local file at `/app/env.yml`
+ a attached drive with label cidata (cloud-init: no-cloud config)
+ a attached drive with label config-2 (cloud-init: openstack config)
+ aws-ec2 (amazon elastic computing cloud) meta-data server
+ gce (google compute engine) meta-data server

It will be copied to `/run/active-env.yml` (ramdisk) on each appliance startup.

### Create Config

for a development server, run `cp /app/appliance/salt/pillar/default-env.sls /app/env.yml`
and edit settings in /app/env.yml .

for offline environment creation, using your local machine:
+ have saltstack installed (minion does not need to run)
+ `git clone https://github.com/ecs-org/ecs-appliance  ~/path-to-project/ecs-appliance`
+ use env-create.sh and env-package.sh like explained below,
    but add ~/path-to-project/ecs-appliance/salt/common/ to the callpath.
+ copy ~/domainname.domain/env.yml to appliance machine at /app/env.yml

```
ssh root@target.vm.ip '/bin/bash -c "mkdir -p /app/"'
scp env.yml root@target.vm.ip:/app/env.yml
```

on an installed but unconfigured appliance:

+ enter installed but empty appliance
+ make a new env.yml: `env-create.sh domainname.domain ~/domainname.domain/`
+ edit settings in ~/domainname.domain/env.yml , see comments inside file
+ optional, package env into different formats
    +  `env-package.sh --requirements; env-package.sh ~/domainname.domain/env.yml`

+ print out ~/domainname.domain/env.yml.pdf
+ transfer and keep ~/domainname.domain/domainname.env.date_time.tar.gz.gpg

### Modify Config

Any change in the config file will reconfigure the appliance on the next appliance-update run to the new values found in the configuration.
Eg. if you want to change your backup target to a different location,
just change the value and restart the appliance, it will detect and configure 
all needed changes to the environment.

See the comments in the configuration for different possibilities for the appliance configuration.

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
  #       content: |
  #           # Your content here
  #       owner: user:group
  #       permissions: "0600"
  #   states: # include extra states at state.highstate
  #     - qrcode
  #   packages: # include extra packages at state.highstate
  #     - ghostscript
  storage:
    # # setup: optional, will be executed by appliance.storage.setup if volatile or data can not be found
    # setup: |
    # proxy_cache: true
    # # default false, if true 10 additional GB diskspace are used
    # # for operating polipo, a http proxy cache
    ignore: # default false, if true: will not look for ecs-volatile or ecs-data filesystem
      volatile: true
      data: true
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
        a ascii armored GPG Key 
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

      SECRET_KEY = '{{ ssl_secret() }}'
      REGISTRATION_SECRET = '{{ ssl_secret() }}'
      PASSWORD_RESET_SECRET = '{{ ssl_secret() }}'

      EMAIL_BACKEND = 'django.core.mail.backends.console.EmailBackend'
      EMAIL_BACKEND_UNFILTERED = 'django.core.mail.backends.smtp.EmailBackend'
      EMAIL_UNFILTERED_DOMAINS = () # = ('example.com',)

      SMTPD_CONFIG['listen_addr'] = ('0.0.0.0', 8025)
      SMTPD_CONFIG['domain'] = DOMAIN

      # User registration, password reset, send client certificate and mail to
      # receivers at a domain included in EMAIL_UNFILTERED_DOMAINS will be sent via
      # EMAIL_BACKEND_UNFILTERED. All other mail will be sent via EMAIL_BACKEND.
      #
      # Backend to use to NOT sent email but log email to console:
      #   django.core.mail.backends.console.EmailBackend
      #
      # Backend to use to send via EMAIL_* smtp settings:
      #   django.core.mail.backends.smtp.EmailBackend
      #

  vault_encrypt: |
      a ascii armored GPG Key 

  vault_sign: |
      a ascii armored GPG Key 
```

#### Ethics Commission UUID's

```eval_rst
================================  ====================================================================================
23d805c6b5f14d8b9196a12005fd2961  Ethikkommission der Medizinischen Universität Wien
7b51f38bde8a4161a0dc34647fc7e654  Ethikkommission Krankenhaus Barmh.Brüder - Wien
85dc386061584fbe8549ce4e4d828fbd  Ethikkommission der Stadt Wien gemäß KAG, AMG und MPG
d6a22c635a584521b107481ac18318f6  Ethikkommission Forschungsinstitut des Wiener Roten Kreuzes
55ae93ec9df04d6abfc8d233ec5ccf8e  Ethikkommission Krankenhaus Barmh.Schwestern - Wien
7cd6d52120b3474ba502931b9f60a5f3  Ethikkommission Confraternität-Priv.Klin. Josefstadt und Priv.Klin. Döbling
7df9ebaf15434709b09c3def9a6c8769  Ethikkommission St.Anna Kinderspital
f122f144616541d391fde2dcc761aff4  Ethikkommission Österreichische Arbeitsgemeinschaft für Klinische Pharmakologie
25b6744780434a3f96a1e43b405d3848  Ethikkommission Privatkrankenanstalt Rudolfinerhaus
d542994ced34403db841786a1c1ab892  Ethikkommission Rheuma-Zentrum Wien-Oberlaa
5615dfbaf8c8445d960d1e2cd9c00dc3  Ethikkommission Krankenhaus des Göttlichen Heilandes
4d3a2d5f138940f293ee87fe6ec1d5b2  Ethikkommission Evangelisches Krankenhaus
8d2950e3a0294f68bde647a54df6d823  Ethikkommission der Allgemeinen Unfallversicherungsanstalt
9f6b509e716e413f865d95bdd630e9bc  Ethikkommission Immunologische Tagesklinik
b17f32f604fa4452b5ff3a2baa9e0704  Ethikkommission des Landes Niederösterreich
6688ce16a3b84d42b1531389e6039891  Ethikkommission Krankenhaus Elisabethinen
e4dcd05a31ad475ca72dea7b84ef030e  Ethikkommission des Landes Oberösterreich
e269491bb9c040aaad6a5f11df343f38  Ethikkommission Krankenhaus Barmh.Brüder - Linz
1cca34032077445d95dabf7802fade28  Ethikkommission Krankenhaus Barmh.Schwestern - Linz
39cbb589ef044d27bceb6ee5ac796ae7  Ethikkommission für das Bundesland Salzburg
280414583b894c809a9baa8134d7fe4b  Ethikkommission der Medizinischen Universität Innsbruck
183881da8200493aa7edd8bebeea75b9  Ethikkommission des Landes Vorarlberg
95821eba88f34b2195f96e747d7f6b16  Ethikkommission des Landes Burgenland gemäß KAG, AMG und MPG
6e7cfab5f8cd40df83c9de4fac9bb20f  Ethikkommission des Landes Steiermark gemäß AMG und MPG
75b5a9714f354a5b842aa01029148036  Ethikkommission Krankenhaus Barmh.Brüder - Graz
9287fb0878b94f9f9d90b5582d1cefca  Ethikkommission Krankenhaus Barmh.Brüder - Eggenberg
e17ee744e4e840778f316cf3f79de6b4  Ethikkommission der Medizinischen Universität Graz
ec9f179a52a04a7aa52446232c3fd4bd  Ethikkommission des Landes Kärnten
c890205dcb7543c8a76bf324512c5f81  Ethikkommission des Krankenhaus St. Josef
dc1b115d9809461ba3ea9450b079ddd6  Kommission für Scientific Integrity und Ethik der Karl Landsteiner Privatuniversität
================================  ====================================================================================
```

### Activate Config

on the target vm:
```
# create a empty ecs database
sudo -u postgres createdb ecs -T template0  -l de_DE.utf8

# activate env and apply new environment settings
chmod 0600 /app/env.yml
cp /app/env.yml /run/active-env.yml
reboot
```

#### First Internal User setup

After the appliance has rebooted, it configures itself to the new environment.
See the progress of the preperation by browsing to https://domainname.domain .
After the appliance is ready and shows the login screen, login via ssh to create
the first internal office user, with a corresponding client certificate.

```
# create first internal office user (f=female, m=male)
create-internal-user.sh useremail@domain.name "First Name" "Second Name" "f" 

# create and send matching client certificate
create-client-cert.sh useremail@domain.name cert_name [daysvalid]

# Communicate certificate transport password over a secure channel
```