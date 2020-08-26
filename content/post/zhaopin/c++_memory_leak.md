---
title: "C++_memory_leak"
date: 2020-08-26T17:01:02+08:00
draft: true
---

在计算机科学中，内存泄漏指由于疏忽或错误造成程序未能释放已经不再使用的内存的情况。内存泄漏并非指内存在物理上的消失，而是应用程序分配某段内存后，由于设计错误，导致在释放该段内存之前就失去了对该段内存的控制，从而造成了内存的浪费。

# C 内存泄漏
```c
#include <stdlib.h>
int main()
{
    int *array = malloc(sizeof(int));
    return 0;
}
```
编译程序时，需要加上 -g 选项
```sh
gcc -g -o main main.c
```

valgrind 使用方法是：
```sh
valgrind --tool=memcheck --leak-check=full ./main
```

c 内存泄漏
```
==5183== HEAP SUMMARY:
==5183==     in use at exit: 4 bytes in 1 blocks
==5183==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==5183== 
==5183== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==5183==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5183==    by 0x400537: main (main.c:3)

```

c++ 
```c++
#include <stdlib.h>
int main(){
    int* a = new int[10];
    //delete [] a;
    return 0;
}
```

```sh
g++ -std=c++11 -o main main.cpp 
valgrind --tool=memcheck --leak-check=full ./main
```

c++ 正常输出
```txt
==5632== HEAP SUMMARY:
==5632==     in use at exit: 72,704 bytes in 1 blocks
==5632==   total heap usage: 2 allocs, 1 frees, 72,744 bytes allocated
==5632== 
==5632== LEAK SUMMARY:
==5632==    definitely lost: 0 bytes in 0 blocks
==5632==    indirectly lost: 0 bytes in 0 blocks
==5632==      possibly lost: 0 bytes in 0 blocks
==5632==    still reachable: 72,704 bytes in 1 blocks
==5632==         suppressed: 0 bytes in 0 blocks
==5632== Reachable blocks (those to which a pointer was found) are not shown.
==5632== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==5632== 
==5632== For counts of detected and suppressed errors, rerun with: -v
==5632== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```

c++ 内存泄漏
```txt
==5614== HEAP SUMMARY:
==5614==     in use at exit: 72,744 bytes in 2 blocks
==5614==   total heap usage: 2 allocs, 0 frees, 72,744 bytes allocated
==5614== 
==5614== 40 bytes in 1 blocks are definitely lost in loss record 1 of 2
==5614==    at 0x4C2E80F: operator new[](unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==5614==    by 0x400607: main (in /home/lhw/test/test3)
==5614== 
==5614== LEAK SUMMARY:
==5614==    definitely lost: 40 bytes in 1 blocks
==5614==    indirectly lost: 0 bytes in 0 blocks
==5614==      possibly lost: 0 bytes in 0 blocks
==5614==    still reachable: 72,704 bytes in 1 blocks
==5614==         suppressed: 0 bytes in 0 blocks
==5614== Reachable blocks (those to which a pointer was found) are not shown.
==5614== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==5614== 
==5614== For counts of detected and suppressed errors, rerun with: -v
==5614== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

c++ 越界：
```txt
==5417== Invalid read of size 4
==5417==    at 0x400AD7: main (test1.cpp:5)
==5417==  Address 0x5ab6ca8 is 0 bytes after a block of size 40 alloc'd
==5417==    at 0x4C2E0EF: operator new(unsigned long) (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)

==5417== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```

c++ 未初始化内存
```sh
==5450== Conditional jump or move depends on uninitialised value(s)
==5450==    at 0x4F3CCAE: std::ostreambuf_iterator<char, std::char_traits<char>

==5450== Use of uninitialised value of size 8
==5450==    at 0x4F3BB13: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)


==5450== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)
```

