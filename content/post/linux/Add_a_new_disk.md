---
title: "Add_a_new_disk"
date: 2018-12-01T15:03:00+08:00
draft: true
---

# add a new disk to ubuntu

```sh
sudo fdisk -l #查看全部磁盘
sudo fdisk /dev/sdb     #对磁盘进行分区
n       #新增磁盘
w       #写入操作
reboot  

mkfs -t ext4 /dev/sdb4      #格式化分区
mkdir /home/hello/newDir        
sudo mount /dev/sdb4 /home/hello/newDir     #挂载分区

sudo vim /etc/fstab         #修改此文件，在末尾增加如下行，设置开机挂载。
/dev/sdb4 /home/hello/newDir ext4 defaults 0 0
```