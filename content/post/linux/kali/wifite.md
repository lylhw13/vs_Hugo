---
title: "Wifite"
date: 2019-07-21T09:51:35+08:00
draft: true
---

## install hashcat
```sh
git clone https://github.com/hashcat/hashcat.git
cd hashcat
git submodule init
git submodule update
make
make install
```
## install hcxtools
```sh
apt-get install libcurl4-openssl-dev libssl-dev zlib1g-dev libpcap-dev
git clone https://github.com/ZerBea/hcxtools
cd hcxtools
make
make install
```

## install hcxdumptppl
```sh
git clone https://github.com/ZerBea/hcxdumptool
cd hcxdumptool
make
make install
```

