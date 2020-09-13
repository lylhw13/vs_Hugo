---
title: "Gdb"
date: 2020-08-13T11:11:11+08:00
draft: true
---

gcc: GNU C      Compiler
g++: GNU C++ Compiler

如果使用gcc 编译 c++，会出现大量的 `undefined reference to `信息，用g++ 就不会出现这种问题

.c      C 源程序，必须进行预处理，must be preprocessed

.cc
.C      // 大写的C
.cp
.cxx 
.cpp
.c++    都属于C++源程序，必须进行预处理

.h      C, C++ 的头文件

.hh
.H
.hpp
.hxx
.h++    C++的头文件

.i      不应该预处理的C文件，也就是预处理后的 C 文件
.ii     不应该预处理的C++文件，也就是预处理后的 C++文件

.s      Assembler code 汇编代码

.S      // 大写
.sx      汇编代码，必须进行预处理

其他后缀名的文件被传递给连接器(linker).通常包括:
.o      目标文件(Object file)
.a      归档库文件(Archive file)


# gcc/g++ 常用编译选项
```gcc
-c          // 将 .cpp 文件 编译成 .o 但是不进行链接
-g          // 在目标文件中添加调试信息，用于 基于gdb的调试器
-o          // 指定生成文件的名字

-S          // 生成汇编文件

-I<dir>     // 指定头文件路径, include-paths
-L<dir>     // 指定库文件路径, library-path
-l<libName> // 指定特定的库文件
-Wall       // 显示所有警告信息

-v          // 显示编译步骤, verbose mode

-w          // 不显示任何警告信息 (不建议), inhibit all waring messages

-std=       // 决定使用版本，只支持 c 或 c++，比如 'c11', 'c++11'
```


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
continue	// 从这里继续执行
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
set (expression)	                    // 设置变量，同上
```

## Misc Commands
```gdb
RETURN	        // 单击RETURN 键，重复执行上一个命令
backtrace	    // 查看栈信息，print backtarce of all stack frames, or innermost COUNT frames
bt	            // Alias for backtrace
attach pid	    // Attach to an already-running process by its PID
info registers	    // 罗列出整型寄存器的内容
info all-registers	// 罗列出所有寄存器的内容
info locals         // 可以得到当前栈帧中所有局部变量的值列表

```

```gdb
break function
break line_number
break filename:line_number
break filename:function

break break_args if (condition)
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