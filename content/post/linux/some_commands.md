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

- `eth0` is the first Ethernet interface. (Additional Ethernet interfaces would be named eth1, eth2, etc.) This type of interface is usually a NIC connected to the network by a category 5 cable.
- `lo` is the loopback interface. This is a special network interface that the system uses to communicate with itself.
- `wlan0` is the name of the first wireless network interface on the system. Additional wireless interfaces would be named wlan1, wlan2, etc.

ifconfig can only assign a static IP address to a network interface. If you want to assign a dynamic IP address using DHCP, you should use the dhclient command.

# Shebang (Unix)

#! /bin/sh

# /dev/null
/dev/null（或称空设备）在类Unix系统中是一个特殊的设备文件，它丢弃一切写入其中的数据（但报告写入操作成功），读取它则会立即得到一个EOF。

# deinstall
Synonyms: uninstall

# ping
[can't ping behind the proxy](https://superuser.com/questions/175428/how-to-ping-when-behind-a-proxy/175441)

ping needs a direct network connection on the IP level to do its work. A proxy works on a higher layer of the TCP/IP network model, where there is no direct access to the IP protocol.

You would need to somehow circumvent the proxy (change firewall settings, use a VPN, ...). Whether this is possible (and allowed) depends on your network configuration, but it's probably not possible.

As a workaround, there are many web-based ping services available (search for "web-based ping"). These will work.

# export 
Linux export命令用于设置或显示环境变量。

在shell中执行程序时，shell会提供一组环境变量。export可新增，修改或删除环境变量，供后续执行的程序使用。

export的效力仅及于该次登陆操作

```sh
export ALL_PROXY=socks5://127.0.0.1:1086
```
写入终端配置的话：
```sh
# for zsh shell
echo export ALL_PROXY=socks5://127.0.0.1:1086 >> ~/.zsh_profile
```

# alias

临时修改：
```sh
alias cdhugo='cd ~/Documents/code/Hugo/vs_Hugo/'
```

永久修改：
```sh
vim ~/.zshrc        
# 在文件末尾添加 alias cdhugo='cd ~/Documents/code/Hugo/vs_Hugo/'
source ~/.zshrc     # activate the .zshrc 
```

# change hostname
Refer to [Linux change my hostname / computer system name](https://www.cyberciti.biz/faq/howto-change-my-hostname-machine-name/)

## step 1: Use hostnamectl to set hostname
```sh
hostnamectl         # query hostname
hostnamectl set-hostname 'some_name'        # set new hostname
```
## step 2: Change hosts as follows
如果不修改此处，会出现 `unable to resolve host` 的错误

```sh
vim /etc/hosts
```

Before:
```txt
127.0.0.1       old_name localhost
```

After:
```txt
127.0.0.1       new_name localhost
```

