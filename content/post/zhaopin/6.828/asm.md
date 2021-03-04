---
title: "Asm"
date: 2020-10-31T17:51:58+08:00
draft: true
---

MBR: main boot sector 主引导扇区
VRAM: Video RAM 显存
LBA: Logical Block Address 逻辑块地址
ICH: I/O Controller Hub 输入输出控制设备集中器
VHD: Virtaul Hard Disk 虚拟硬盘
CHS: Cylinder Head Sector 柱面 磁头 扇区

目的操作数必须用方括号围起来，以表明它是一个地址，处理器应该用这个地址再次访问内存

任何指令都不支持在两个内存单元之间直接进行操作。

一个有效的主引导扇区，其最后两个字节的数据必须是0x55 和 0xAA。

小端序
```
dw 0xaa55
```

现代处理器在加电启动时，段寄存器CS的内容为0xF000，指令指针寄存器 IP 的内容为 0xFFF0，这就使得处理器地址线的低20位同样是 0xFFFF0。

```
movsb DS:SI, ES:DI
movsw DS:SI, ES:DI
```
cld，DF方向标志位清零，代表正向传送，由低到高；
sld，DF方向标志位置1，代表逆向传送，由高到低

可以在任何带有内存操作数的指令中使用BX，SI 或者 DI 提供偏移地址。

cbw convert byte to word
cwd convert word to double-word

$ 代表当前行的汇编地址
$$ 是NASM编译器提供的一个标记，代表当前汇编节（段）的其实汇编地址

Bochs 虚拟机用于调试

偏移地址在前，段地址在后
