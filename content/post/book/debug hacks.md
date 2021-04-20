根据内核配置，内核启动参数划分问题
在启动参数中加上 nosmp，可以确认是否为 SMP 环境下发生的 bug


利用内核转储掩码排除共享内存

设置断点使用函数名
不加*，断点就不会设置到汇编语言层次的函数开头，而是设置到地址偏后一点的源代码级别的开头。p81

xmm0 可以看作是个联合体 p82

在x86_64架构中，整数和指针的大小就是 giant word（双字，即 4个字节）


基本上，i386将所有参数保存到栈上。但是通过GCC的扩展功能 __attribute__(regparm(num)), 也可以实现将num个参数使用寄存器传递。 


```sh
nm - list symbols from object files

nm foo | grep foo

nm foo | grep foo | c++filt
nm -C foo | grep foo
```