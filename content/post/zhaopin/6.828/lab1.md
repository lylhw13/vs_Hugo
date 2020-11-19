---
title: "Lab1"
date: 2020-11-19T10:56:04+08:00
draft: true
---

NASM uses the so-called Intel syntax while GNU uses the AT&T syntax. 

The labs use GNU assembler.

When the BIOS finds a bootable floppy or hard disk, it loads the 512-byte boot sector into memory at physical addresses 0x7c00 through 0x7dff, and then uses a jmp instruction to set the CS:IP to 0000:7c00, passing control to the boot loader. 