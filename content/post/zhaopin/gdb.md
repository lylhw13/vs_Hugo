---
title: "Gdb"
date: 2020-08-13T11:11:11+08:00
draft: true
---

# gdb 命令

## starting and quitting
```gdb
gcc -g hello.c -o hello     // 在目标文件中添加调试信息
gdb hello.exe               // 开始debug
help command                // get help
run [arg1] [arg2] [...]     // run the currently loaded program with the given command line arguments
quit                        // 退出 
```

## Breakpoints and Watchpoints
```gdb
break location      // 添加断点
watch expression	// Break when a variable is written to
rwatch expression	// Break when a variable is read from
awatch expression	// Break when a variable is written to or read from
info break          // 显示断点信息
info watch          // 显示观察点信息
clear location	    // Clear a breakpoint from a location
delete num	        // Delete a breakpoint or watchpoint by number
```

## Stepping and Running
```gdb
next	    // 执行下一步
step	    // Step program until it reaches a different source line
stepi	    // 前进一条指令 Step a single assembly instruction
continue	// 继续执行
continue 次数   // 指定忽略断点的次数
CTRL-C	    // 停止运行
finish	    // 执行到当前函数结尾
unit        //执行程序，直到到达当前循环体外的下一行源代码
advance location	// 前进到指定位置
jump location	    // Just like continue, except jump to a particular location first.
```

## Examining and Modifying Variables
```gdb
display expression	    // 在程序每次停下时，显示该变量
info display	        // Show a list of expressions currently being displayed and their numbers
undisplay num	        // Stop showing an expression identified by its number (see info display)
print expression	    // 打印出变量值
printf formatstr expressionlist	        // Do some formatted output with printf() e.g. printf "i = %d, p = %s\n", i, p


set variable expression	                // 设置变量，比如 set variable x=20
set variable 变量 = 表达式
set (expression)	                    // 设置变量，同上
```

## Misc Commands
```gdb
RETURN	        // 单击RETURN 键，重复执行上一个命令
backtrace	    // 查看栈信息，print backtarce of all stack frames, or innermost COUNT frames
bt	            // Alias for backtrace
attach pid	    // Attach to an already-running process by its PID
info registers	    // 罗列出 整型 寄存器的内容
info reg            // 同上

info all-reg        // 列出所有寄存器的内容

p $eax              // 显示寄存器的内容


info locals         // 可以得到当前栈帧中所有局部变量的值列表
```

```gdb
break function
break line_number
break filename:line_number
break filename:function

break break_args if (condition)
```

```gdb
backtrace
bt          # 显示所有栈帧

backtrace N
bt N        # 显示开头的N个栈帧

backtrace -N
bt -N       # 显示最后的N个栈帧

backtrace full
bt full     # 不仅显示backtrace，还显示局部变量，   可以添加 N 选择栈帧
bt full N
bt full -N
```

clear
            Delete any breakpoints at the next instruction to be executed in the selected stack frame (see section Selecting a frame). When the innermost frame is selected, this is a good way to delete a breakpoint where your program just stopped.
clear function
clear filename:function
            //Delete any breakpoints set at entry to the function function.
clear linenum
clear filename:linenum
            //Delete any breakpoints set at or within the code of the specified line.
delete [breakpoints] [range...]
            //Delete the breakpoints, watchpoints, or catchpoints of the breakpoint ranges specified as arguments. If no argument is specified, delete all breakpoints (GDB asks confirmation, unless you have set confirm off). You can abbreviate this command as d.

```gdb
int x[25];
(gdb) p x       // 可以输出整个数组

int *x;
x = (int*) malloc(25 * sizeof(int));
(gdb) p x       // 打印数组地址
(gdb) p *x      // 打印第一个元素

//可以使用下面两种方法
(gdb) p *x@25       //人工数组 (artificial array)

(gdb) p (int [25]) *x       // 强制类型转换
```


Linux 不允许生成 core dump 文件。下面的命令显示，Linux 允许的最大 core dump 文件大小为 0：
```sh
$ ulimit -a | grep core
core file size          (blocks, -c) 0
```
可以通过下面设置，允许 Linux 生成 core dump 文件：
```sh
# 以下命令仅对当前shell有效
$ ulimit -c n           // n 是核心文件的最大大小，以千字节为单位。超过 nKB 的核心文件都不会被编写。
$ ulimit -c unlimited

# 对所有shell有效
# 在 ~/.bashrc 的最后加入： 
ulimit -c unlimited
```
设置完成后再次进行查询，结果如下
```sh
$ ulimit -a | grep core
core file size          (blocks, -c) unlimited
```

# gdb 查看 core 文件

```gdb
gdb [exec_file] [core_file]
gdb -c [core_file] [exec_file]
```


# 软件调试的艺术

段错误涉及访问不具备足够权限的内存
地址错误是提供给处理器的是无效地址。
在很多架构上，要求访问32位量的机器指令要求字对齐，即这个量的内存地址必须是4的倍数。导致试图在奇数号地址上访问具有4字节的数的指针错误可能会引起总线错误。

在调试会话期间，修改代码时永远不要退出GDB，这样就不必费时机来启动，可以保留我们的断点等。


# debug hacks 中文版

程序指针可以写为 $pc, 也可写为 $eip, 两者都可以显示。这是因为Intel IA-32 架构中的程序指针名为 eip
p $pc
p $eip

用x命令可以显示内存的内容。x 这个名字的由来是 eXamining
x/格式 地址
x $pc
x/i $pc

反汇编指令 disassemble, 简写为 disas
```
disassemble                 # 反汇编整个函数
disassemble 程序计数器          # 反汇编程序计数器所在函数的整个函数
disassemble 开始地址 结束地址       # 反汇编从开始地址到结束地址之前的部分
```


attach pid
将进程 attach 到进程ID为pid的进程上
