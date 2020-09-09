---
title: "Gdb"
date: 2020-08-13T11:11:11+08:00
draft: true
---

gcc: GNU C      Compiler
g++: GNU C++ Compiler

如果使用gcc 编译 c++，会出现大量的 `undefined reference to `信息


# gcc/g++ 常用编译选项
```gcc
-c          // 将 .cpp 文件 编译成 .o 但是不进行链接
-g          // 在目标文件中添加调试信息，用于 基于gdb的调试器
-o          // 指定生成文件的名字

-I<dir>     // 指定头文件路径, include-paths
-L<dir>     // 指定库文件路径, library-path
-l<libName> // 指定特定的库文件
-Wall       // 显示所有警告信息

-v          // 显示编译步骤, verbose mode

-w          // 不显示任何警告信息 (不建议)
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
break location      // 添加断点 Set a breakpoint at a location, line number, or file (e.g. "main", "5", or "hello.c:23")
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
step	    // Step into the function on this line, if possible
stepi	    // Step a single assembly instruction
continue	// Keep running from here
CTRL-C	    // Stop running, wherever you are
finish	    // Run until the end of the current function
advance location	// Advance to a location, line number, or file (e.g. "somefunction", "5", or "hello.c:23")
jump location	    // Just like continue, except jump to a particular location first.
```

## Examining and Modifying Variables
```gdb
display expression	    // Display the value of a variable or expression every step of the program—the expression must make sense in the current scope
info display	        // Show a list of expressions currently being displayed and their numbers
undisplay num	        // Stop showing an expression identified by its number (see info display)
print expression	    // Print the value of a variable or expression
printf formatstr expressionlist	        // Do some formatted output with printf() e.g. printf "i = %d, p = %s\n", i, p
set variable expression	                // Set a variable to value, e.g. set variable x=20
set (expression)	                    // Works like set variable
```

## Misc Commands
```gdb
RETURN	        // 单击RETURN 键，重复执行上一个命令
backtrace	    // Show the current stack 查看栈信息
bt	            // Alias for backtrace
attach pid	    // Attach to an already-running process by its PID
info registers	    // Dump integer registers to screen
info all-registers	// Dump all registers to screen
```