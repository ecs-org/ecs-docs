## Install Appliance

The base of the appliance is Ubuntu Xenial (16.04).

You either need:
+ a standard ubuntu cloud image from [Ubunu Xenial Cloud Images](http://cloud-images.ubuntu.com/xenial/current/)
    + a cloud-init cidata iso volume with your public key 
        + a prebuilt cidata iso with the vagrant user and the insecure vagrant ssh key
            + [vagrant-growroot.iso](https://raw.githubusercontent.com/ecs-org/cidata-seed/master/vagrant-growroot.iso)
        + you can build your own iso using [github.com/ecs-org/cidata-seed](https://github.com/ecs-org/cidata-seed/)
+ an already running empty Ubuntu Xenial and a ssh key to login
    + eg. if your rootserver hoster has a default xenial image
+ a local development machine with vagrant and a hypervisor for vagrant installed.
    + vagrant will setup the base machine for you

### Partitioning

Unless there is a good reason to do otherwise, the partition layout should be the same
as the default xenial cloud & vagrant images layout.

This image consists of a DOS-MBR and partition one taking all the space as the root partition.
The Vagrant version has initrd grow-root support, so p1 will resize to maximum on reboot.

#### custom storage partitions or network attached storage

Add a custom storage:setup object to setup storage partitions.
To have seperate volatile and/or data partitions, 
change storage:ignore:volatile and/or storage:ignore:data to false.
Setup will add mountpoints for /data and /volatile.
The volatile volume must be labeled "ecs-volatile", the data volume "ecs-data".
Use appliance:extra:states and :packages if storage setup needs additional packages installed.
See salt/storage/README.md for further information about storage:setup.


### install via ssh to a empty xenial vm

ssh into target vm:

```
apt-get -y update; apt-get -y install git
git clone https://github.com/ecs-org/ecs-appliance /app/appliance
cd /
mkdir -p /etc/salt
cp /app/appliance/salt/minion /etc/salt/minion
curl -o /tmp/bootstrap_salt.sh -L https://bootstrap.saltstack.com
chmod +x /tmp/bootstrap_salt.sh
/tmp/bootstrap_salt.sh -X
salt-call state.highstate pillar='{"appliance": {"enabled": true}}'
```

### install using vagrant

on your local machine:

```
git clone https://github.com/ecs-org/ecs-appliance ~/ecs-appliance
cd ~/ecs-appliance
vagrant up
```

### upgrade a developer vm

Requirement: you need at least 3gb total memory for the appliance.

on a developer vm:

```
# clone from public repository
git clone https://github.com/ecs-org/ecs-appliance /app/appliance
# install saltstack and start appliance install
curl -o /tmp/bootstrap_salt.sh -L https://bootstrap.saltstack.com
sudo bash -c "mkdir -p /etc/salt; cp /app/appliance/salt/minion /etc/salt/minion; \
    chmod +x /tmp/bootstrap_salt.sh; /tmp/bootstrap_salt.sh -X"
sudo salt-call state.highstate pillar='{"appliance": {"enabled": true}}'
```

if you also want the builder (for building the appliance image) installed:

```
sudo salt-call state.highstate pillar='{"builder": {"enabled": true}, "appliance": {"enabled": true}}'
```

