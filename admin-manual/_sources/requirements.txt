# Requirements

The ecs software is designed to run as an external available internet web-service, reachable by everyone.

## Hosting Requirements

+ a Virtual Machine on a supported Hypervisor or Hardware sized according to the [Assessment](#cores-memory-harddisk-backup-space-assessment) Chapter
+ a Backup space (for encrypted backup data) accessable by one of 25 supported storage protocols explained under [Backup Storage](#backup-storage)
+ DNS A Record pointing to a fixed public IPV4 address,a MX Record and a reverse PTR Record as described under [DNS Setup](#dns-setup)
+ incoming tcp ports 22,25,80,443,465 of a fixed public IPV4 address and IPV4 and internet connectivity for the vm as described under [Internet Connectivity](#internet-connectivity)
+ Working HTTPS including HTTP-Client Certificate support. See common challenges described under [Security Products](#firewall-endpointprotection-antivirus-security-products)

### Hypervisor

+ The base of the virtual machine is a Ubuntu Xenial (16.04 LTS) 64Bit Standard Cloud Image.
+ The appliance was tested on the following hypervisors: 
  + KVM, XEN, VMware Sphere, HyperV
+ Rollouts to Amazon EC2, Google GCE or Openstack Clouds are not tested but meta data gathering from ec2, gce or openstack compatible meta data services is implemented but probably need some tweaking.
+ Follow the Assessment Chapter for the right sizing of CPU-cores, memory and harddisk.

### Backup Storage 

+ For storing backup data the appliance needs a storage space accessable via one of the 24 duplicity supported storage protocols.
+ In addition to the supported duplicity protocols the appliance has support for **cifs** (windows file sharing attached volumes, including automatic mount and unmount)
+ Tested protocols so far: localfile, ftp, ftpssl, ssh/scp, ssh/sftp, http/webdav, cifs
+ For Details see: [Duplicity Manual - Section URL-Format](http://duplicity.nongnu.org/duplicity.1.html#sect7)
+ Storage at Rest: All backup data is encrypted before it leaves the machine using gpg (GnuPG) and is saved without any prior decryption on the target space.
+ The storage space may be hosted internal or external, using the same provider as the machine hosting or using a different provider. The hosting provider may be a trusted or untrusted third-party.
+ Rotation and Retention is automatic, the backup process is unattended.
+ See [Assessment](#cores-memory-harddisk-backup-space-assessment) for the correct storage space size.

### DNS Setup

+ For Web-Access a dns [sub]domain with a A Entry pointing to the public IPv4 Address is needed
+ For Email Sending and Receiving the following entries are required:
  + a MX Record pointing to the choosen domain name
  + a reverse PTR Record pointing to the domain name
  + a spf TXT Entry, eg. "v=spf1 a mx ptr ~all"
  + a dkim TXT Entry, see the env.yml configuration file for detailed data

**Once you generated a config env.yml, at the top of the file you will find the corresponding DNS Entries (including DKIM TXT key) for pasting into the DNS Server**

**Warning**: For Email functionality the MX Record, reverse PTR Record, SPF TXT Record and the DKIM TXT Record are important to setup. Eg. failing to setup reverse PTR will result in broken email sending, because the target mailserver will think the emails are spam and will bounce messages.

Examples for domains "https://whatever.me" and "https://sub.whatever.me":

```
# Main Domain Example for whatever.me
@  IN A   1.2.3.4
@  IN MX  10 whatever.me
@  IN TXT "v=spf1 a mx ptr ~all"
default._domainkey  IN  TXT  "v=DKIM1; k=rsa; s=email; p=a-long-glibberish-key"
4.3.2.1.in-addr.arpa. IN PTR whatever.me

# Sub domain Example for sub.whatever.me
sub IN A  5.6.7.8
sub IN MX 10 sub.whatever.me
sub IN TXT "v=spf1 a mx ptr ~all"
default._domainkey.sub  IN  TXT  "v=DKIM1; k=rsa; s=email; p=a-long-glibberish-key"
8.7.6.5.in-addr.arpa.  IN PTR sub.whatever.me
```

### Internet Connectivity

+ permanent internet connectivity with a big (>=100Mbit) upload channel
+ an IPv4 address and dns server settings need to be served to the machine by DHCP for automatic configuration
    + this can be **any internal or the public IPv4 Address** if the hosting location needs this, but it must be served by DHCP
    + **Unusable** internal nets are **172.17.X.X and 10.0.3.X**, because these are used by the appliance itself

+ a public IPv4-Address or the incoming TCP ports **22,25,80,443,465 and ICMP/ping** of this address forwarded to the machine
    + port 22 - ssh: ssh publickey authentification is used. this connection is used for installation and optional support
    + port 25,465 - smtp: the incoming email server of the appliance will receive emails from answers of forwarded ecs communication. if the hosting locations policy does not permit this, the ecs will work without it, but loses email answering functionality
    + port 80 - http: the appliance communicates only over https, but needs http for letsencrypt client certificate renewal and for redirecting to the https site
    + port 443 - https: the appliance uses letsencrypt to issue a host certificate and lets internal user administer https client certificates in self-service
      + ICMP/ping - ping: for monitoring the system

### "Firewall"/Endpointprotection/"Antivirus" Security Products:

**Warning**: many security products are known to disturb/break HTTPS Host
Certificate and Client Certificate validation and weaken the transport protocols on the wire. 
See the findings of [the Security Impact of HTTPS Interception](https://jhalderm.com/pub/papers/interception-ndss17.pdf) Paper.

#### Firewall

The appliance does not need a firewall but works as long as the incoming ports
listed are forwarded to the machine and outgoing traffic from the machine is permitted.

#### Host Certificates

The appliance uses LetsEncrypt to issue https/ssl host certificates and also takes care of the renewal of these host certificates. There is no IT-administration task involved in this process.

#### Client Certificates

The ecs appliance uses https client certificates for protection of elevated user rights. 
Https client certificates are issued by the appliance itself and can be done in selfservice as an internal ecs webfrontend user. There is no IT-Administration task involved in this process.

**Warning**: If the hosting location has some mandatory security product, 
you probably need some extra configuration in the security product to fix support for Client Certificates.

**This may also apply to to the pc's of internal ecs desktops.**
Some desktop "antivirus" products may need similar extra configuration to have working https client certificate support. So far there have been findings of Kaspersky and McAfee products to need extra configuration.

## Cores, Memory, Harddisk & Backup Space Assessment

All data size units in this document are 1024 based.
+ 1 GB = 1024 MB, 1 MB = 1024 KB , 1 KB = 1024 bytes

As a guideline, if you have more memory available, add some extra memory.

**Warning**: If you deviate from the example values below, be sure to add the needed memory per core if you add more cores, because many of the appliance processes get scaled to the number of cores.

+ Minimum CPU/Memory: 2 Cores, 4GB

Core Calculation:
+ 20 Studies per Month: 2 Cores
+ 40 Studies per Month: 2-4 Cores
+ 100-250 Studies per Month: 4-8 Cores

Memory Calculation:
+ 2GB Base + 1GB per Core + Disk-size of Database (eg. 2GB)
+ eg. 2 Cores = 4 GB + 1 GB Database= 5GB 
+ eg. 8 Cores = 10 GB + 8 GB Database= 18GB

Storage Calculation (10 Years):
+ System: 5GB
+ Temporary Workspace: 30GB
+ Database: (Studies-per-Month/ 12,5)GB
+ Document-Storage: (120 * Studies-per-Month * 17)MB

Backup Space Calculation (10 Years):
+ Data: 2 (Fullbackups) * max(Document-Storage) + max(Database) + 2 Months delta grow

Limits:
The current ecs implementation can sustain 250 Studies per Month for 10 years.
Larger implementations are possible with some refactoring in certain parts of the ecs.

### 10 Years Calculation

After 10 Years, the values noted will be reached.

#### 100 Studies per Month
```eval_rst
==================  ======  ======================================== 
Items               Size    Calculation
==================  ======  ========================================
Base & Temp         50GB 
Database            8GB     4074220 / 59 * 120
Document-Storage    195GB   100684328 / 59 * 120
Disksize            253GB   52428800 + 8286549 + 204781684
Backup              444GB   2 x 204781684+ 52428800+ 204781684/120*2
recommended Cores   6
recommended Memory  16GB+   2+ 8+ 6
==================  ======  ========================================
```

#### 250 Studies per Month
```eval_rst
==================  ======
Items               Size  
==================  ======
Base & Temp         50GB 
Database            20GB 
Document-Storage    500GB 
Disksize            570GB 
Backup              1332GB
recommended Cores   8 
recommended Memory  30GB+ 
==================  ======
```

#### 40 Studies per Month
```eval_rst
==================  ======
Items               Size  
==================  ======
Base & Temp         50GB 
Database            3,2GB
Document-Storage    78GB 
Disksize            131GB 
Backup              178GB
recommended Cores   4
recommended Memory  9,5GB+
==================  ======
```

#### 20 Studies per Month
```eval_rst
==================  ======
Items               Size  
==================  ======
Base & Temp         50GB 
Database            1,6GB
Document-Storage    40GB 
Disksize            92GB 
Backup              89GB
recommended Cores   2
recommended Memory  6GB+
==================  ======
```

#### Test Instance
```eval_rst
==================  =======
Items               Size  
==================  =======
Disksize            20-40GB
recommended Cores   1-2
recommended Memory  4GB+
==================  =======
```


### Research data

+ EC with ~100 Studies per Month
+ Runtime: ~5 Years (59 month) (15.1.2012 - 15.12.2016 ~ 4 Years, 11 Months)
+ Studies: 5861 in 59 Months, or ~100 (99,339) Studies per Month

Document Storage:
+ Current space used: 97GB (100684328KB)
+ Directories: 69K Directories
+ Files: 296K Files
+ Files per Directory: Peak at 4-6 Files per Directory
+ average 339KB per File
+ average space per study: 17178KB ~ 16,78MB

Postgres Database:
+ compressed migrated production dump: 475MB
+ diskspace used: ~4GB (4074220 KB, 1GB pg_xlog)


## Client Desktop Requirements

+ As a submitter one of the following browsers is needed:
  + Mozilla Firefox
  + Google Chrome
  + Apple Safari
  + Microsoft Edge
  + Microsoft Internetexplorer 11
+ Internal User need:
  + Mozilla Firefox
  + Working HTTPS including HTTP-Client Certificate support. See common challenges described under [Security Products](#firewall-endpointprotection-antivirus-security-products)
+ Signing User need:
  + Mozilla Firefox ESR
  + Sun Java with Firefox Plugin

