---
title: "C++_reference"
date: 2020-10-15T20:20:39+08:00
draft: true
---

```c++
class A{
public:
    int& ref;
};

class B{
public:
    int a = 1;
    int& ref= a;
    double& refb;
};

/*
c++标准并没有规定 reference 怎么实现，也没有规定引用是否占用空间。c++ 仅仅指明概念，具体实现由编译器决定。

g++ 中 reference 内部由指针来实现，所以和指针大小一致。

但是 reference 并不是指针。它是对象的别名。
*/
cout << sizeof(A) << endl;          // 8
cout << sizeof(B) << endl;          // 24

//When applied to a reference or a reference type, the result is the size of the referenced type.
cout << sizeof(A::ref) << sizeof(int&) << endl;         // 4
cout << sizeof(B::refb) << sizeof(double&) << endl;     // 8
```

C++为我们提供的各种存取控制仅仅是在编译阶段给我们的限制，也就是说编译器确保了你在完成任务之前的正确行为，如果你的行为不正确，那么编译器就是给你在编译时提示错误。

所谓的const和private等在实际的目标代码里根本不存在，所以在程序运行期间只要你愿意，你可以通过内存工具修改它的任何一个变量的值。

