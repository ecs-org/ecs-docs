## Deploy Appliance

The base of the appliance is Ubuntu Xenial (16.04 LTS).
Installation is done unattended using ssh to login into the machine.

### As a Virtual Machine

You either need:
+ a standard ubuntu cloud image from [Ubunu Xenial Cloud Images](http://cloud-images.ubuntu.com/xenial/current/)
    + a cloud-init cidata iso volume with your public key 
        + use the prebuilt cidata iso with the vagrant user and the insecure vagrant ssh key or password
            + [vagrant-publickey-growroot.iso](https://raw.githubusercontent.com/ecs-org/cidata-seed/master/vagrant-publickey-growroot.iso)
            + [vagrant-password-growroot.iso](https://raw.githubusercontent.com/ecs-org/cidata-seed/master/vagrant-password-growroot.iso)
        + you can build your own seed iso using [github.com/ecs-org/cidata-seed](https://github.com/ecs-org/cidata-seed/)
+ an already running empty Ubuntu Xenial and a ssh key to login
    + eg. if your rootserver hoster has a default xenial image
+ a local development machine with vagrant and a hypervisor for vagrant installed.
    + vagrant will setup the base machine for you


For a virtual machine deployment it is best to stick to the default xenial cloud images layout (flat, first Partition as Root taking all space), unless there is good reason to deviate.

Start the new virtual machine and login via ssh.

### On Hardware or other custom Configurations

Needed:

+ an already running empty Ubuntu Xenial and a ssh key to login
    + eg. if your rootserver hoster has a default xenial image

In a typical root server hosting setup there are two harddisks per machine.
These should be configured as a raid1 (mirroring) setup with lvm on top of it.

Example:
+ Hardware: [Hetzner px61nvme Rootserver](https://www.hetzner.de/de/hosting/produkte_rootserver/px61nvme)  Setup Config:

```
DRIVE1 /dev/nvme1n1
DRIVE2 /dev/nvme0n1
SWRAID 1
SWRAIDLEVEL 1
BOOTLOADER grub
HOSTNAME Ubuntu-1604-xenial-64-minimal
PART /boot ext3 512M
PART lvm vg0 all
LV vg0 root / ext4 300G
IMAGE /root/.oldroot/nfs/install/../images/Ubuntu-1604-xenial-64-minimal.tar.gz
```

### Network attached Storage 

+ The appliance supports two external network attached storage volumes, one for permanent data and one for volatile data. 
+ To have seperate volatile and/or data partitions, change storage:ignore:volatile and/or storage:ignore:data to false.
+ The volatile volume must be labeled "ecs-volatile", the data volume "ecs-data".
+ Setup will add mountpoints for /data and /volatile and mount them on startup.
+ Use appliance:extra:states and :packages if storage setup needs additional packages installed.


### Install via ssh to an empty Xenial VM

ssh into target vm:

```
export DEBIAN_FRONTEND=noninteractive
apt-get -y update && apt-get -y install curl
curl https://raw.githubusercontent.com/ecs-org/ecs-appliance/master/bootstrap-appliance.sh > /tmp/bootstrap.sh
cd /tmp; chmod +x /tmp/bootstrap.sh; /tmp/bootstrap.sh --yes
```

### Testinstall using Vagrant

on your local machine:

```
git clone https://github.com/ecs-org/ecs-appliance ~/ecs-appliance
cd ~/ecs-appliance
vagrant up
```

### Upgrade a developer vm

Requirement: you need at least 3gb total memory for the appliance, 4gb minimum if you want metrics active.

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

