---
title: "Tcpdump"
date: 2020-09-24T16:11:33+08:00
draft: true
---

关于网络的工具中 -n 参数，都表示不对ip地址进行反解

tcpdump 默认不显示包内容

```tcpdump
-n      # 不对ip地址进行反解 No name resolution
-h      # 版本号
-c num    # 指定抓取的包的数量
-D      # 显示所有的可用网卡  List Interfaces
-i eth0    # 指定抓取的网卡

-r filename     # 指定读入的文件
-w filename     # 指定抓包信息的写入文件，这个文件能直接打开

-v      # verbose 输出更多信息

-A      # 以 ASCII 方式显示数据包的内容
-X      # Hex， 以 16 进制方式显示数据包内容
```

过滤
```sh
host addr   # 发往或发自指定地址的流量
src addr    # 发自指定地址的流量
dst addr    # 发往指定地址的流量
port num    # 指定端口号


IP: host (ip addr)
Source IP: src host (ip addr)
Dest. IP: dst host (ip addr)
port: port 80
MAC address: ether host (mac address)
protocol filters: tcp, udp, icmp, arp, rarp, ip6, (others)
SYN flag: "tcp[tcpflags] & tcp-syn != 0"
RST flag: "tcp[tcpflags] & tcp-rst != 0"
```

```tcpdump
tcpdump -i ens33 -XA
```

nc — arbitrary TCP and UDP connections and listens

tcpdump options used in this video:

Change capture size (ex 96 Bytes): -s96
Max capture size: -s0
save to file capture.pcap: -w capture.pcap -v
Read from a capture file: -r capture.pcap

Output options:
View MAC info: -e
Include hex and ASCII: -XX
ASCII only: -A
max verbosity: -vvv
ignore checksum errors: -K
quiet: -q
timestamp options: -t, -tt, -ttt, etc...