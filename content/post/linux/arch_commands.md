---
title: "Arch_commands"
date: 2018-07-05T16:05:06+08:00
draft: true
tags: ["Arch"]
categories: ["Linux"]
---

# some commands on arch

```sh
journalctl -b -1 -r
```

that will display the logs for your last boot (-b -1), starting at the last messages in the log (-r)

## shutdown

```sh
shutdown -r #重启计算机（和reboot）命令一样
shutdown -h #关闭计算机并关闭电源（常用）
shutdown -f #重启计算机，不进行磁盘检测
shutdown -F #重启计算机并进行磁盘检测
shutdown -c #取消正在执行的关机命令
```