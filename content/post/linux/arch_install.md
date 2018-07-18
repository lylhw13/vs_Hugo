---
title: "Arch 安装"
date: 2018-07-01T15:09:30+08:00
draft: true
tags: ["Arch"]
categories: ["linux"]
---
# 使用Arch总结

## reinstall record

参照官方教程时的注意点
1，网络设置环节
2，怎么分区
3，分区规划及设置

my partition strategy

Device | Size | Type | Mount Point
--- | --- | --- | ---
/dev/sda1 | 1G | EFI System | /boot
/dev/sda2 | 50G | Linux filesystem | /
/dev/sda3 | 50G | Linux filesystem | /home
/dev/sda4 | 10G | Linux swap | [SWAP]

After creating the ESP (EFI System Partition), you must format it as FAT32:

```sh
mkfs.fat -F32 /dev/sda1
```

format the Linux filesystem:

```sh
mkfs.ext4 /dev/sda2
mkfs.ext4 /dev/sda3
```

format the swap partition:

```sh
mkswap /dev/sda4
swapon /dev/sda4
```

Mount the file systems:

```sh
mount /dev/sda2 /mnt # mount the file system on the root partition to /mnt

mkdir /mnt/boot
mount /dev/sda1 /mnt/boot

mkdir /mnt/home
mount /dev/sda3 /mnt/home
```

`genfstab` will later detect monuted file systems and swap space.

A swap partition can be created with most GNU/Linux partitioning tools. Swap partitions are typically designated as type 82. Even though it is possible to use any partition type as swap, it is recommended to use type 82 in most cases since systemd will automatically detect it and mount it (see below).

选择镜像源

```sh
vim /etc/pacman.d/mirrorlist
```

将China的镜像源调整最前面，本身China的镜像源默认只有清华的源，可以添加浙大的源:

`Server = http://mirrors.zju.edu.cn/archlinux/$repo/os$arch`。

吐槽一句，虽然感觉距离浙大的源应该更近，但是浙大源并没有清华源的速度好。

安装基本包，这是一个联网下载的过程：

```sh
pacstrap /mnt base base-devel
```

配置Fstab
```sh
genfstab -U /mnt >> /mnt/etc/fstab # Generate an fstab file (use -U or -L to define by UUID or labels, respectively):
cat /mnt/etc/fstab # Check the resulting file in /mnt/etc/fstab afterwards, and edit it in case of errors.
```


## 安装声卡驱动

```sh
pacman -S pulseaudio
```

## 安装Google Chrome

参考[Install Google Chrome on Arch Linux](https://linuxhint.com/install-google-chrome-on-arch-linux/).

## 触摸板设置

参考链接<https://wiki.archlinux.org/index.php/Touchpad_Synaptics>

```sh
pacman -S xf86-input-synaptics
cp /usr/share/X11/xorg.conf.d/40-libinput.conf /etc/X11/xorg.conf.d/
vim /etc/X11/xorg.conf.d/40-libinput.conf
```

修改touchpad的section为：

```conf
Section "InputClass"
    Identifier "libinput touchpad catchall"
    MatchIsTouchpad "on"
    Driver "libinput"
    Option "Tapping" "on"
    Option "VertEdgeScroll" "on"
    Option "VertTwoFingerScroll" "on"
EndSection
```

## Partioning

参考链接<https://wiki.archlinux.org/index.php/partitioning#UEFI.2FGPT_example_layout>

UEFI/GPT example layout

Mount point | Partition | Partition type GUID | Suggested size
---|---|---|---
/boot | /dev/sda1 | C12A7328-F81F-11D2-BA4B-00A0C93EC93B: EFI System Partition | 550 MiB
/ | /dev/sda2 | 4F68BCE3-E8CD-4DB1-96E7-FBCAF984B709: Linux x86-64 root (/) | 23 - 32 GiB
[SWAP] | /dev/sda3 | 0657FD6D-A4AB-43C4-84E5-0933C84B4F4F: Linux swap | More than 512 MiB
/home | /dev/sda4 | 933AC7E1-2EB4-4F13-B844-0E14E2AEF915: Linux /home | Remainder of the device

BIOS/MBR example layout

Mount point | Partition | Partition type ID | Boot flag | Suggested size
---|---|---|---|---
/ | /dev/sda1 | 83: Linux | Yes | 23 - 32 GiB
[SWAP] | /dev/sda2 | 82: Linux swap | No | More than 512 MiB
/home | /dev/sda3 | 83: Linux | No | Remainder of the device

## 安装显卡驱动

参考链接<https://wiki.archlinux.org/index.php/NVIDIA>

`Warning: Avoid installing the NVIDIA driver through the package provided from the NVIDIA website. Installation through pacman allows upgrading the driver together with the rest of the system.`

* If you do not know what graphics card you have, find out by issuing:

    ```sh
    lspci -k | grep -A 2 -E "(VGA|3D)"
    ```

* Determine the necessary driver version for your card by:

    Finding the code name (e.g. 540M ) on [Nouveau wiki's code names page](https://nouveau.freedesktop.org/wiki/CodeNames/).

    The graphics card of Acer 4750 is GeForce GT 540M, it belongs to NVC1(GF108) series.

* Install the appropriate driver for your card:

    For GeForce 400/500 series cards [NVCx and NVDx] from around 2010-2011, install the `nvidia-390xx` or `nvidia-390xx-lts` package.

* Reboot. The nvidia package contains a file which blacklists the nouveau module, so rebooting is necessary.

Once the driver has been installed, continue to [#Configuration](https://wiki.archlinux.org/index.php/NVIDIA#Configuration).

Here I don't config it, for it work well on my pc.

More detail please refer to [#installation](https://wiki.archlinux.org/index.php/NVIDIA#Installation).

## 美化字体

参考[Make your Arch fonts beautiful easily!](https://www.reddit.com/r/archlinux/comments/5r5ep8/make_your_arch_fonts_beautiful_easily/).

* Install some fonts, for example:

    ```sh
    sudo pacman -S ttf-dejavu ttf-liberation noto-fonts
    ```

* Enable font presets by creating symbolic links:

    ```sh
  sudo ln -s /etc/fonts/conf.avail/70-no-bitmaps.conf /etc/fonts/conf.d
  sudo ln -s /etc/fonts/conf.avail/10-sub-pixel-rgb.conf /etc/fonts/conf.d
  sudo ln -s /etc/fonts/conf.avail/11-lcdfilter-default.conf /etc/fonts/conf.d
    ```
*The above will disable embedded bitmap for all fonts, enable sub-pixel RGB rendering, and enable the LCD filter which is designed to reduce colour fringing when subpixel rendering is used.*

* Enable FreeType subpixel hinting mode by editing:

    ```sh
  /etc/profile.d/freetype2.sh
    ```

* Uncomment the desired mode at the end:

    ```sh
  export FREETYPE_PROPERTIES="truetype:interpreter-version=40"
    ```

    *For font consistency, all applications should be set to use the serif, sans-serif, and monospace aliases, which are mapped to particular fonts by fontconfig.*

* Create /etc/fonts/local.conf with following:

    ```xml
  <?xml version="1.0"?>
  <!DOCTYPE fontconfig SYSTEM "fonts.dtd">
  <fontconfig>
      <match>
          <edit mode="prepend" name="family"><string>Noto Sans</string></edit>
      </match>
      <match target="pattern">
          <test qual="any" name="family"><string>serif</string></test>
          <edit name="family" mode="assign" binding="same"><string>Noto Serif</string></edit>
      </match>
      <match target="pattern">
          <test qual="any" name="family"><string>sans-serif</string></test>
          <edit name="family" mode="assign" binding="same"><string>Noto Sans</string></edit>
      </match>
      <match target="pattern">
          <test qual="any" name="family"><string>monospace</string></test>
          <edit name="family" mode="assign" binding="same"><string>Noto Mono</string></edit>
      </match>
  </fontconfig>
    ```

* Set your font settings to match above in your DE system settings.

Note: You can use a font family of your choice, other than Noto fonts.

## 安装中文输入法

参考链接[Fcitx (简体中文)](https://wiki.archlinux.org/index.php/Fcitx_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87)#.E4.B8.AD.E6.96.87)

```sh
pacman -S wqy-microhei #首先安装中文字体
pacman -S fcitx fcitx-libpinyin fcitx-cloudpinyin
```

然后配置，否则的话不能启动中文输入法。

本文对应的情况为非桌面环境，并且是用startx启动的，所以应该在`~/.xinitrc`中加入

```sh
# Fcitx
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=@im=fcitx
```

重新登录后让环境变量生效。

警告: 请不要在 .bashrc 设置这些环境变量。bashrc只应用于交互性 bash 会话的初始化，并不应用于非交互性脚本或 X 会话的初始化

## wifi-menu

新安装的arch，调用`wifi-menu`输出如下的错误。

```sh
# wifi-menu
Scanning for networks... failed
No networks found
```

解决办法：

参考链接<https://bbs.archlinux.org/viewtopic.php?pid=1324810#p1324810>

### step 1

```sh
echo "blacklist acer_wmi" > /etc/modprobe.d/acer.conf
```

Reboot, then unblock all WiFi with:

```sh
rfkill unblock all
```

其中`acer_wmi`，可以根据硬件的不同进行相应调整。可以通过命令`lsmod`显示已经加载到内核中的模块的状态信息，查看有关wmi的信息。

### step 2

```sh
ip link
ip link set wlp3s0 up
```

如果不进行step 1，直接进行step 2操作，会输出如下错误:
`RTNETLINK answers: Operation not possible due to RF-kill`

其中`wlp3s0`可以通过`ip link`查询出来，一般为`wlp`开头。

## Error 1

参考链接<https://forum.xfce.org/viewtopic.php?id=7184>

在xfce 上如果浏览器设置不对，会出现下面的错误对话框： `[Solved] Failed to execute default Web Browser`。

解决办法：
Applications -> Settings -> Xfce 4 setting manager -> Preferred Applications -> Web Browser