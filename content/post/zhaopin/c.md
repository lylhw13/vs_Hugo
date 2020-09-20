---
title: "C"
date: 2020-09-13T17:00:18+08:00
draft: true
---

# C 语言不包含引用

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

# 判断大端小端

如果是小端序，转型后为1，否则为0
指针指在起始的位置上，小端序是先遇到小端，所以小端在起始位置上。
```c++
    int num = 0x01;

    cout << ((char)num == 1)<< endl;
    cout << (*(char *)(&num) == 1) << endl;
    
    union UN{
        int a;
        char b;
    };
    
    UN un;
    un.a = num;
    cout << (un.a == 1) << endl;
```




