---
title: "Assembly"
date: 2020-09-14T19:11:06+08:00
draft: true
---
一般不区分大小写

Control Registers
    - ZF zero flag 零标志位
    - PF Parity Flag 奇偶标志位
    - SF Sign Flag  符号标志位
    - CF Carry Flag 进位标志位

General-Purpose Registers (GPR) - 16-bit naming conventions
The 8 GPRs are:
1. Accumulator register (AX).           Used in arithmetic operations
2. Base register (BX).                  Used as a pointer to data (located in segment register DS, when in segmented mode).
3. Counter register (CX).               Used in shift/rotate instructions and loops.
4. Data register (DX).                  Used in arithmetic operations and I/O operations.
5. Stack Pointer register (SP).         栈顶指针 Pointer to the top of the stack.
6. Stack Base Pointer register (BP).    栈底指针 Used to point to the base of the stack.
7. Instruction Pointer register (IP)    指令指针寄存器
8. Source Index register (SI).          Used as a pointer to a source in stream operations.
9. Destination Index register (DI).     Used as a pointer to a destination in stream operations.



The 6 Segment Registers are: `S C D E F G`
- Stack Segment (SS). Pointer to the stack.
- Code Segment (CS). Pointer to the code.
- Data Segment (DS). Pointer to the data.
- Extra Segment (ES). Pointer to extra data ('E' stands for 'Extra').
- F Segment (FS). Pointer to more extra data ('F' comes after 'E').
- G Segment (GS). Pointer to still more extra data ('G' comes after 'F').

CS:IP 指向当前的指令

SS:SP 指向栈顶元素
SS:BP 指向栈底元素

BX 默认段是 DS

使用 bx, bp, si, di 进行内存单元寻址，下面格式排列，同一项只能出现一个
[base register] + [index register] + [idata ]

我们可以用 [bx + idata + si] 的方式来访问结构体中的数据。用 bx 定位整个结构体，用 idata 定位结构体中的某一个数据项，用 si 定位数据中的每个元素。汇编也提供了更为贴切的书写方式 [bx].idata, [bx].idata[si]

(...) 表示一个寄存器或一个内存单元中的内容
[...] 表示一个内存单元的偏移地址

# 参数传递的寄存器顺序
如果一个函数有大于6个整型参数，超出6个的部分就要通过栈来传递

di si dx cx r8w r9w

# NASM

- Put the system call number in the EAX register.
- Store the arguments to the system call in the registers EBX, ECX, etc.
- Call the relevant interrupt (80h).
- The result is usually returned in the EAX register.

There are six registers that store the arguments of the system call used. These are the EBX, ECX, EDX, ESI, EDI, and EBP. These registers take the consecutive arguments, starting with the EBX register. If there are more than six arguments, then the memory location of the first argument is stored in the EBX register.

# logical instructions

The first operand in all the cases could be either in register or in memory. The second operand could be either in register/memory or an immediate (constant) value. However, memory-to-memory operations are not possible. These instructions compare or match bits of the operands and set the CF, OF, PF, SF and ZF flags.

CMP destination, source

$ points to the byte after the last character of the string variable msg.


# linux 生成汇编方法
- 直接 gcc 生成
```sh
gcc -Og -S main.c
```

- 使用 gcc 生成连接前的目标文件，使用 objdump 进行反汇编
  ```sh
  gcc -Og -c main.c

  objdump -d main.o
  ```