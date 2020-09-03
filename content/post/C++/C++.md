---
title: "C++"
date: 2018-07-01T12:12:11+08:00
draft: false
tags: ["C++"]
categories: ["C++"]
---

# C++ 问题汇总

## 关于C/C++的输入输出精度。

参考文章<https://stackoverflow.com/questions/16831623/precision-issue-with-sscanf>

* 输入：

```C++
double d;
//here %lf for a double, not %f.
sscanf("5.655035220e-02", "%lf", &d); # it does not lost any precision.
```

```C++
// parse C string str
double atof(const char* str);
double strtod(const char* str, char** endptr);

// parse string
double stod(const stirng& str, size_t* idx=0);
```

* 输出：

```C
// format
// %[flags][width][.precision][length]specifier

printf("%*.*g", width, precision, d);
```

```c++
#include <iomanip>
cout << setiosflags(ios::fixed) << setprecision(2);
```

通过调整`precision`可以得到不同的精度。

详细的格式参数参考<http://www.cplusplus.com/reference/cstdio/printf/>

Specifier | Output | Example
----------|--------|-------
d or i | Signed decimal integer | 392
u | Unsigned decimal integer | 7235
x | Unsigned hexadecimal integer | 7fa
X | Unsigned hexadecimal integer (uppercase) | 7FA
f | Decimal floating point, lowercase | 392.65
F | Decimal floating point, uppercase | 392.65
e | Scientific notation (mantissa/exponent), lowercase | 3.9265e+2
E | Scientific notation (mantissa/exponent), uppercase | 3.9265E+2
g | Use the shortest representation: %e or %f | 392.65
G | Use the shortest representation: %E or %F | 392.65
c | Character | a
s | String of characters | sample

## read data line


## struct constructor in c++

参考<https://stackoverflow.com/questions/1127396/struct-constructor-in-c>

In C++ the only difference between a class and a struct is that members and base classes are private by default in classes, whereas they are public by default in structs.

So structs can have constructors, and the syntax is the same as for classes.

<https://softwareengineering.stackexchange.com/questions/262463/should-we-add-constructors-to-structs>

Sometimes it's appropriate to add constructor to a struct and sometimes it is not.

Adding constructor (any constructor) to a struct prevents using aggregate initializer on it. So if you add a default constructor, you'll also have to define non-default constructor initializing the values. But if you want to ensure that you always initialize all members, it is appropriate.

Adding constructor (any constructor, again) makes it non-POD, but in C++11 most of the rules that previously applied to POD only were changed to apply to standard layout objects and adding constructors don't break that. So the aggregate initializer is basically the only thing you lose. But it is also often a big loss.

```c++
//case 1
struct TestStruct {
    double number;
};
//case 2
struct TestStruct {
    double number;
    TestStruct(double aDouble) : number(aDouble) { }
    //there is no semicolon in the last line
};
```

## C++: Vector iterator won't work in templates

```c++
template<typename A>
void addAllVector(std::vector<A> &dest, const std::vector<A> &src) {
    std::vector<A>::const_iterator it;
    for (it = src.begin(); it!=src.end();  ++it) {
        dest.push_back(*it);
    }
}  
```

change to

```c++
template<typename A>
void addAllVector(std::vector<A> &dest, const std::vector<A> &src) {
    typename std::vector<A>::const_iterator it;     //this line changed
    for (it = src.begin(); it!=src.end();  ++it) {
        dest.push_back(*it);
    }
}  
```

## Stack and Heap

### refer to <https://forum.qt.io/topic/9130/is-there-a-general-rule-when-to-favor-a-heap-object-over-a-stack-object-if-the-stack-object-is-passed-by-value-a-lot>

    For the stack/heap decision - that's mostly (not always!) a matter of the live time of objects: `stack for short term objects, heap for long living objects`. As for every rule of thumb: there are exceptions!

    One important thing to remember, is that you can think of the heap as random memory. That is, you can create things, and destroy them, and generally let the objects have independent lives without it affecting things. Items can be contiguous or far apart. In no particular order. Think of the heap as your "general purpose" memory.

    The stack, by definition, is a sequential block of memory. First in, last out. So, you're limited in the lifespan of objects. It serves a different purpose than the heap. It's there for items that are more limited in scope and lifespan, such as passing parameters, or having short-term elements in a method.

    Also, if you create an object on the stack, it is immediately scoped to the block in which it was created. As soon as you leave that block, the item is popped off the stack and disappears. If you try to work around this, then you will end up with a ton of objects down in your main() or in some class. That becomes very kludgy and inefficient. With heap-based memory, you can pass pointers around and the data lives independently of where it was allocated, until such time as you tell it to go away.

    Additionally, the QObject class hierarchy relies on heap-based objects, as objects need to be allocated on the heap for QObject's memory management routines to work.

    If the widget which doesn't have a parent, you had better allocate it on the stack.

### [What’s the difference between a stack and a heap?](https://www.programmerinterview.com/index.php/data-structures/difference-between-stack-and-heap/)

    In a multi-threaded application, each thread will have its own stack. But, all the different threads will share the heap. 

### [How do I choose heap allocation vs. stack allocation in C++?](https://stackoverflow.com/questions/7973138/how-do-i-choose-heap-allocation-vs-stack-allocation-in-c)

## override
refer to <https://stackoverflow.com/questions/18198314/what-is-the-override-keyword-in-c-used-for>,
<https://stackoverflow.com/questions/13880205/is-the-override-keyword-just-a-check-for-a-overridden-virtual-method>

- the introduction of override keyword in C++11 is nothing more than a check to make sure that the function being implemented is the overrideing of a virtual function in the base class.