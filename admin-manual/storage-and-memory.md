# Choosing the right values for Cores, Memory, Harddisk & Backup

All data size units in this document are 1024 based
    (1 GB = 1024 MB, 1 MB = 1024 KB , 1 KB = 1024 bytes)

+ Minimum Cpu/Memory (without monitoring): 1 Core, 3GB
+ Minimum Cpu/Memory: 2 Cores, 4GB

Core Calculation:
+ 20 Studies per Month: 2 Cores
+ 40 Studies per Month: 2-4 Cores
+ 100-250 Studies per Month: 4-8 Cores

Memory Calculation:
+ 2GB Base + 1GB per Core + Disksize of Database (eg. 2GB)
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
Larger implementations need some refactoring in certain parts of the ecs to be efficient.

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


## Research data

+ EC with ~100 Studies per Month
+ Runtime: ~5 Years (59 month) (15.1.2012 - 15.12.2016 ~ 4 Years, 11 Months)
+ Studies: 5861 in 59 Months, or ~100 (99,339) Studies per Month

### Document Storage
+ Current space used: 97GB (100684328KB)
+ Directories: 69K Directories
+ Files: 296K Files
+ Files per Directory: Peak at 4-6 Files per Directory
+ average 339KB per File
+ average space per study: 17178KB ~ 16,78MB

### Postgres Database
+ compressed migrated production dump: 475MB
+ diskspace used: ~4GB (4074220 KB, 1GB pg_xlog)
