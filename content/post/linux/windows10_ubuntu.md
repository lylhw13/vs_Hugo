---
title: "Windows10 Ubuntu Dual System"
date: 2018-10-27T16:27:29+08:00
draft: false
tags: ["Windows", "Ubuntu", "Linux", "Dual System"]
categories: ["Windows", "Linux"]
---

# 在Acer笔记本上安装ubuntu+Windows双系统

系统配置：

- windows system:   Windows10 home
- PC:   Acer-Aspire-4750
- Linux system: Ubuntu16.04LTS

安装方法参考[win10 ,ubuntu双系统安装避坑指南](https://segmentfault.com/a/1190000014523888)

这里采用的分区方案：

挂载点 | 格式类型 | 大小 | 分区类型 | 新分区的位置
--- | --- | --- | --- | ---
/boot | ext4 | 300M | 主分区 | 空间起始位置
/ | ext4 | 30G | 逻辑分区 | 空间起始位置
swap | swap | 10G | 逻辑分区 | 空间起始位置
/home | ext4 | 70G | 逻辑分区 | 空间起始位置
注：这里的分区类型，好像并不重要。参考[Ubuntu installation partitioning: Logical or primary?](https://askubuntu.com/questions/121197/ubuntu-installation-partitioning-logical-or-primary)

易忽略点：
在划分分区结束，准备安装前，要将`安装启动引导器的设备`选择为挂载点为`/boot`的设备。

注意问题：

1， 这里没有用EastBCD去重新引导Ubuntu，似乎也能很好的引导系统。

2， 因为笔记本较旧，本身系统的安装方式为BISO模式，安装系统时会出现如下警告：

 >在win10 的基础上使用U盘安装ubuntu双系统的时候，出现问题。机器以uefi模式启动了安装器，但是似乎已经存在使用bios兼容模式的系统。如果继续以uefi模式安装debian，可能非常难以重启进入其他bios模式的系统。如果希望以uefi模式安装且无意再启动现有的系统，此处有强制选项。如果要保持现有系统可启动，不要选择强制uefi安装。

解决方法：
使用UltraISO给U盘刻录ubuntu 系统，刻录成功后，打开U盘，删除EFI文件夹。再进行正常的安装即可。
参考[解决安装ubuntu系统时，出现机器以UEFI模式启动了安装器的问题](https://blog.csdn.net/lx10271129/article/details/77677179)


# 利用ubuntu搭建Time Capsule

- System:   Ubuntu 16.04 LTS 64bit

安装方法参考[用Linux搭建Time Machine – Ubuntu篇(亲测可用)](https://blog.e9china.net/share/yonglinuxdajiantimemachineeeubuntupianqincekeyong.html)

## 安装并配置Netatalk
```sh
sudo apt-get install netatalk
sudo vim /etc/netatalk/AppleVolumes.default
```
用"#"将`～/ “Home Directory”` 这行注释掉，并在最后一行添加希望存放的目录。
这里在最后一行添加：
```sh
/home/hello/TimeCapsule "TimeCapsule" options:tm
```
创建相应目录，并修改权限：
```sh
sudo mkdir /home/hello/TimeCapsule
sudo chmod -R 777 /home/hello/TimeCapsule
```

## 配置Avahi
Ubuntu默认带有Avahi，因此这里不再安装，仅进行配置。

```sh
sudo vim /etc/avahi/services/afpd.service       #创建并打开
```
在`afpd.service`中写入如下内容：
```sh
%h
_afpovertcp._tcp
548
_device-info._tcp
0
model=Xserve
```
## 重启相应服务：
```sh
sudo service netatalk restart
sudo service avahi-daemon restart
```
Linux端配置结束。

## Mac端
在Mac中打开Finder，commande+k打开"Connect to Server", 并在`Server Address`中输入`afp://your.server.ip.address`，点击connect。
然后打开Time Machine，进行相关设置并备份。

Tips：
在Ubuntu输入`ifconfig`，可以查看当前机器ip。