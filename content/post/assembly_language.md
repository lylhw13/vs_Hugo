---
title: "Assembly_language"
date: 2019-06-03T22:26:17+08:00
draft: true
---

# [汇编语言入门教程](http://www.ruanyifeng.com/blog/2018/01/assembly-language-primer.html)

这种因为用户主动请求而划分出来的内存区域，叫做 Heap（堆）。它由起始地址开始，从低位（地址）向高位（地址）增长。Heap 的一个重要特点就是不会自动消失，必须手动释放，或者由垃圾回收机制来回收。

调用栈有多少层，就有多少帧。
所有的帧都存放在 Stack，由于帧是一层层叠加的，所以 Stack 叫做栈。

Stack 是由内存区域的结束地址开始，从高位（地址）向低位（地址）分配。

```sh
gcc -S example.c
```

_add_a_and_b:
   push   %ebx
   mov    %eax, [%esp+8] 
   mov    %ebx, [%esp+12]
   add    %eax, %ebx 
   pop    %ebx 
   ret  

_main:
   push   3
   push   2
   call   _add_a_and_b 
   add    %esp, 8
   ret

int add_a_and_b(int a, int b) {
   return a + b;
}

int main() {
   return add_a_and_b(2, 3);
}
