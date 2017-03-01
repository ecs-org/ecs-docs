## Configure Appliance

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

### on an installed but unconfigured appliance

+ enter installed but empty appliance
+ make a new env.yml: `env-create.sh domainname.domain ~/domainname.domain/`
+ edit settings in ~/domainname.domain/env.yml , see comments inside file
+ optional, package env into different formats
    +  `env-package.sh --requirements; env-package.sh ~/domainname.domain/env.yml`

+ print out ~/domainname.domain/env.yml.pdf
+ transfer and keep ~/domainname.domain/domainname.env.date_time.tar.gz.gpg

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
See the progress of the preperation by browsing to https://domainname.domain  
After the appliance is ready and shows the login screen, login via ssh to create
the first internal office user, with a corresponding client certificate.

```
# create first internal office user (f=female, m=male)
create-internal-user.sh useremail@domain.name "First Name" "Second Name" "f" 

# create and send matching client certificate
create-client-cert.sh useremail@domain.name cert_name [daysvalid]

# Communicate certificate transport password over a secure channel
```
