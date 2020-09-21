---
title: "Vmware_full_screen"
date: 2020-09-21T19:26:37+08:00
draft: true
---

ubuntu 16.04 全屏解决办法
```sh
sudo apt install open-vm-tools
sudo apt install open-vm*
reboot
```
如果出现错误，点开错误详情，如果是 open-vm-tools-dkms， 则卸载这个软件即可
```sh
sudo apt remove open-vm-tools-dkms
reboot
```