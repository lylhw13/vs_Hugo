---
title: "Kali_for_raspberry_pi"
date: 2019-07-14T09:51:57+08:00
draft: true
---

# 添加更新源
```sh
vim /etc/apt/sources.list
```
复制下面的更新源，并保存。

kaili-rolling版本更新源：
```sh
#中科大
deb http://mirrors.ustc.edu.cn/kali kali-rolling main non-free contrib
deb-src http://mirrors.ustc.edu.cn/kali kali-rolling main non-free contrib

#浙大
deb http://mirrors.zju.edu.cn/kali kali-rolling main contrib non-free
deb-src http://mirrors.zju.edu.cn/kali kali-rolling main contrib non-free

#东软大学
deb http://mirrors.neusoft.edu.cn/kali kali-rolling/main non-free contrib
deb-src http://mirrors.neusoft.edu.cn/kali kali-rolling/main non-free contrib

#重庆大学
deb http://http.kali.org/kali kali-rolling main non-free contrib
deb-src http://http.kali.org/kali kali-rolling main non-free contrib

#官方源
deb http://http.kali.org/kali kali-rolling main non-free contrib
deb-src http://http.kali.org/kali kali-rolling main non-free contrib
```

# kali information

IP: 192.168.0.105

sudo apt autoremove


# Setup A Kali Linux On Raspberry Pi 3 Model B+

Refer to [How To Setup A Kali Linux Hacking Station On Raspberry Pi 3 Model B+](https://online-it.nu/how-to-setup-a-kali-linux-hacking-station-on-raspberry-pi-3-model-b/)

## Step 1: Download and Install Kali Linux Image
- 1.1 Download Kali Linux official Raspberry Pi image
- 1.2 Extract the image from the zip file to a local folder
- 1.3 Use Win32DiskImager our a similar application to load the image on the SD card
- 1.4 Insert the SD card and start the Raspberry Pi

## Step 2: Connect to Kali Linux With SSH
- 2.1 Connect the Raspberry Pi to the LAN
- 2.2 Use your favorite network scanner to get the Raspberry’s IP address
- 2.3 Use Putty to connect to the Kali Linux
- 2.4 Use default credentials root for login and toor for the password

## Step 3: Configure Kali Linux

```sh
sudo passwd root            # change root password

sudo apt-get update -y      # update installed packages with default yes
sudo apt-get upgrade -y     
sudo apt-get dist-upgrade -y        # update dependencied with default yes
```

## Step 4: Enable Auto Login Lightdm

- 4.1 Edit configuration file for lightdm
  ```sh
  sudo vim /etc/lightdm/lightdm.conf
  ```

  Uncomment the below two lines and change the autologin user to be "root"
  ```txt
  autologin-user=root
  autologin-user-timeout=0
  ```
- 4.2 Edit editing the PAM configuration file for lightdm 
  ```sh
  sudo vim /etc/pam.d/lightdm-autologin
  ```

  Comment out the line below:

  Before:
  ```txt
  # Allow access without authentication
  auth      required pam_succeed_if.so user != root quiet_success
  ```
  After:
  ```txt
  # Allow access without authentication
  ## auth      required pam_succeed_if.so user != root quiet_success
  ```
- 4.3 Reboot Kali Linux and Confirm that auto login is successful
  
  ```sh
  sudo reboot
  ```

## Step 5: Setup VNC server

Refer to [Use VNC to Remotely Access Your Raspberry Pi from Other Devices](https://null-byte.wonderhowto.com/how-to/use-vnc-remotely-access-your-raspberry-pi-from-other-devices-0178997/)

```sh
apt-get install tightvncserver

vim /etc/init.d/vncboot     # insert the script below into the blank document
chmod 755 /etc/init.d/vncboot
update-rc.d vncboot defaults

reboot
```

## The content of vncboot
```sh
#!/bin/sh
### BEGIN INIT INFO
# Provides: vncboot
# Required-Start: $remote_fs $syslog
# Required-Stop: $remote_fs $syslog
# Default-Start: 2 3 4 5
# Default-Stop: 0 1 6
# Short-Description: Start VNC Server at boot time
# Description: Start VNC Server at boot time.
### END INIT INFO

USER=root
HOME=/root

export USER HOME

case "$1" in
start)
echo "Starting VNC Server"
#Insert your favoured settings for a VNC session
/usr/bin/vncserver :0 -geometry 1280x800 -depth 16 -pixelformat rgb565
;;

stop)
echo "Stopping VNC Server"
/usr/bin/vncserver -kill :0
;;

*)
echo "Usage: /etc/init.d/vncboot {start|stop}"
exit 1
;;
esac

exit 0
```

## Step 6: Configure WiFi Connection


# Optional Install Full Kali Linux Image
Need a 32 gb SD car
```sh
sudo apt-get install kali-linux-full
```
  



