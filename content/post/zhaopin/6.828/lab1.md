---
title: "Lab1"
date: 2020-11-19T10:56:04+08:00
draft: true
---

```sh
cd lab
make qemu-gdb
```

```sh
cd lab
make gdb
```

```gdb
 si (Step Instruction)
```

+------------------+  <- 0xFFFFFFFF (4GB)
|      32-bit      |
|  memory mapped   |
|     devices      |
|                  |
/\/\/\/\/\/\/\/\/\/\

/\/\/\/\/\/\/\/\/\/\
|                  |
|      Unused      |
|                  |
+------------------+  <- depends on amount of RAM
|                  |
|                  |
| Extended Memory  |
|                  |
|                  |
+------------------+  <- 0x00100000 (1MB)
|     BIOS ROM     |
+------------------+  <- 0x000F0000 (960KB)
|  16-bit devices, |
|  expansion ROMs  |
+------------------+  <- 0x000C0000 (768KB)
|   VGA Display    |
+------------------+  <- 0x000A0000 (640KB)
|                  |
|    Low Memory    |
|                  |
+------------------+  <- 0x00000000


NASM uses the so-called Intel syntax while GNU uses the AT&T syntax. 

The labs use GNU assembler.

When the BIOS finds a bootable floppy or hard disk, it loads the 512-byte boot sector into memory at physical addresses 0x7c00 through 0x7dff, and then uses a jmp instruction to set the CS:IP to 0000:7c00, passing control to the boot loader. 

The BIOS loads the boot sector into memory starting at address 0x7c00, so this is the boot sector's load address. This is also where the boot sector executes from, so this is also its link address. We set the link address by passing -Ttext 0x7C00 to the linker in boot/Makefrag, so the linker will produce the correct memory addresses in the generated code.

- BIOS 是CPU本身自带的，加电后跳转到  CS:IP to 0000:7c00 执行
- boot loader
- kernel
- software

BOOT UP STEPS
- when the CPU boots it loads the BIOS into memory and executes it. the BIOS intializes devices, sets of the interrupt routines, and reads the first sector of the boot device(e.g., hard-drive) into memory and jumps to it.

the linker records just the address and size of the .bss section

LMA: load memory address 内存装载地址
    The load address of a section is the memory address at which that section should be loaded into memory.

VMA: virtual memory address, link address 虚拟内存地址
    The link address of a section is the memory address from which the section expects to execute.

Typically, the link and load addresses are the same. 

virtual address ("vaddr"), the physical address ("paddr")

The boot loader uses the ELF program headers to decide how to load the sections. 

