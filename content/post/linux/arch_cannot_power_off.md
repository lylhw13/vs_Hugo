---
title: "Arch_cannot_power_off"
date: 2018-07-04T11:26:30+08:00
draft: true
---

# 关于arch无法关机的尝试

## method 1 (not work)

upgrade the system

```sh
pacman -Syu
```

## method 2（not work）

link<https://bbs.archlinux.org/viewtopic.php?id=234329>

adding a shutdown to the hooks:

```sh
vim /etc/mkinitcpio.conf
```

HOOKS=(base udev autodetect modconf block filesystems resume keyboard fsck usr shutdown)

```sh
mkinitcpio -p linux
```