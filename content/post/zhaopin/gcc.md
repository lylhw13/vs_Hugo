---
title: "Gcc"
date: 2020-09-14T22:26:02+08:00
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

-Wextra
       This enables some extra warning flags that are not enabled by -Wall.
       (This option used to be called -W.  The older name is still supported, but
       the newer name is more descriptive.)
```