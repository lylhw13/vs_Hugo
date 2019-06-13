---
title: "Some_commands"
date: 2019-05-26T12:31:03+08:00
draft: true
---

# some commands

```sh
uname -- Print operating system name
sysinfo
ps
idletime
route

pwd 
getwd
getlwd

```
# ifconfig
<https://www.computerhope.com/unix/uifconfi.htm>

- eth0 is the first Ethernet interface. (Additional Ethernet interfaces would be named eth1, eth2, etc.) This type of interface is usually a NIC connected to the network by a category 5 cable.
- lo is the loopback interface. This is a special network interface that the system uses to communicate with itself.
- wlan0 is the name of the first wireless network interface on the system. Additional wireless interfaces would be named wlan1, wlan2, etc.

ifconfig can only assign a static IP address to a network interface. If you want to assign a dynamic IP address using DHCP, you should use the dhclient command.

# Shebang (Unix)

#! /bin/sh
