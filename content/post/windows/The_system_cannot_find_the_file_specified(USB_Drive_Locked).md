---
title: "The system cannot find the file specified(USB Drive Locked)"
date: 2018-10-26T16:30:31+08:00
draft: false
tags: ["USB", "windows"]
categories: ["Windows"]
---

System: Windows

Refer to youtube videos [The system cannot find the file specified (USB Drive Locked)](https://www.youtube.com/watch?v=09ifDFp5SmM).

```
> diskpart                  # start DiskPart
> list disk    
> select disk 1             # disk 1 is the usb flash
> clean
DiskPart has encountered an error: The device is not ready.
See the System Event log for more information.
> list disk
> select disk 1             # re-select the disk
> clean                     # re-clean
DiskPart succeeded in cleaning the disk.
> list disk 
> select disk 1
> create partition primary
DiskPart succeeded in creating the specified partition.
> select partition 1
Partition 1 is now the selected partition.
> active
Diskpart marked the current partition as active.
> format fs=fat32 quick
Diskpart successfuly formatted the volume.
```
