---
title: "Commands"
date: 2019-07-17T21:06:27+08:00
draft: true
---


## To disable monitor mode and go back to managed mode
  ```sh
  sudo airmon-ng stop wlan0mon
  ```

lspci: command not found


## check Raspberry support interface modes
iw - show / manipulate wireless devices and their configuration

```sh
$ cat /proc/device-tree/model
Raspberry Pi 3 Model B Plus Rev 1.3
$ iw list | grep "Supported interface modes" -A 7
	Supported interface modes:
		 * IBSS
		 * managed
		 * AP
		 * monitor
		 * P2P-client
		 * P2P-GO
		 * P2P-device
```