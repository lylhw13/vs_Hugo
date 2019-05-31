---
title: "Vmware"
date: 2019-05-27T16:19:37+08:00
draft: true
---

# Error: Invalid Drive Error when Installing VMware Workstation


解决方法：

1. 在 Search Box 中 regedit, 打开 Registry Editor。
2. 在`Computer\HKEY_LOCAL_MACHINE\SOFTWARE\WOW6432Node\VMware, Inc.\`目录下可以看到所有VMWare的注册信息，修改子目录里面的`InstallPath`为合适的值即可。

类似的方法可以解决VMWare的路径问题。



