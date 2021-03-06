---
title: "C"
date: 2020-09-13T17:00:18+08:00
draft: true
---

# C 语言不包含引用

C++ 对 C 的增强，表现在六个方面：

增强了类型检查机制
增加了面向对象的机制
增加了泛型编程的机制（template）
增加了异常处理
增加了重载的机制
增加了标准模板库（STL）

# new malloc 区别

new/delete
1. 返回一个有类型的指针
2. new 不会返回NULL，失败时会抛出一个异常
3. 会调用构造函数和析构函数
4. 调用是通过指定类型（编译器计算大小）
5. 是否调用 malloc/free 是基于实现的

malloc/free
1. 返回 void*
2. 失败时返回 NULL
3. 调用时通过指定大小 (in bytes)

# struct 区别

1. C 结构体不能包含成员函数，C++可以
2. 在创建结构体时，C中必须使用struct，而 C++ 不需要
3. C结构体大小为 0，C++结构体大小为 1
4. C结构体不能含有静态变量，C++可以
5. C结构体成员变量不能直接初始化，但是C++可以
6. C中只能有结构体的指针，不能有结构体引用（ C语言不含有引用 ）
7. 在 C  中，嵌套结构的名字和外层结构的名字位于相同的作用域。
    ```c
    struct S{
        struct T{/*...*/} t;
        //...
    };
    struct T x; // C 中是正确的，表示“S::T x;”, 但在 C++ 中是错误的。
    ```

# qsort

```c
#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a, const void*b) {
    return *(int*)a - *(int*)b;     // 注意先转换为整型，再进行加减或比较运算
}

int main(){
    int num[3]= {3,1,2};
    qsort(num, 3, sizeof(int), cmp);

    for(int i=0; i< 3; ++i) {
        printf("%d\n", num[i]);
    }
    return 0;
}
```


指针的算术操作是以它们指向的对象的大小为单位来进行的，而这种大小单位并不一定是字节
