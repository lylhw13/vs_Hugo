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

# install vmware tools
Refer to [在 Linux 虚拟机中手动安装 VMware Tools](https://docs.vmware.com/cn/VMware-Workstation-Pro/14.0/com.vmware.ws.using.doc/GUID-08BB9465-D40A-4E16-9E15-8C016CC8166F.html) and [VMware Tools for Linux Guests](https://www.vmware.com/support/ws4/doc/new_guest_tools_ws.html#1008207)

1. Mount the virtual CD drive in the guest

    - 一般会自动挂载，使用如下命令查询挂载点。
        ```sh
        mount
        ```
        如果已挂载，结果类似如下：
        `/dev/cdrom on /mnt/cdrom type iso9660 (ro,nosuid,nodev)`
        or
        `/dev/sr0 on /media/cdrom0 type iso9660 (ro,nosuid,nodev,noexec,relatime,nojoliet,check=s,map=n,blocksize=2048,user)`

    - 如果未挂载：
        ```sh
        mkdir /mnt/cdrom
        mount /dev/cdrom /mnt/cdrom
        ```
2. Uncompress the installer
    ```sh
    cd /tmp     # change to working directory
    tar zxf /mnt/cdrom/VMwareTools-5.0.0-<xxxx>.tar.gz
    umount /dev/cdrom   # 挂载点根据你前面查询到的进行相应的调整
    ```
3. Execute vmware-install.pl to install vmware tools.
    ```sh
    cd vmware-tools-distrib
    ./vmware-install.pl
    ```

