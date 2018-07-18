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

```C++
// format
// %[flags][width][.precision][length]specifier

printf("%*.*g", width, precision, d);
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