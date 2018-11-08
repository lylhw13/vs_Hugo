---
title: "Windows Subsystem for Linux"
date: 2018-10-26T13:29:51+08:00
draft: true
---

### Unable to install files with apt-get: “unable to locate package”

Try running sudo apt-get update before trying to install the package. After installation the system doesn't have an up-to-date package list so you won't be able to find the package.

Once you've done this you should be able to install as normal.

# Fail to start avahi-daemon

```sh
sudo /etc/init.d/dbus start
sudo /etc/init.d/avahi-daemon start
```