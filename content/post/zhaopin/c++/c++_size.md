---
title: "C++_size"
date: 2020-10-20T19:25:37+08:00
draft: true
---

```c++
void foo(char str[100]) {
    //sizeof on array function parameter 'str' will return size of 'char*'
    cout << sizeof(str) << endl;    // 8 指针大小
}

int main(){
    char str[] = "hello world!";    // sizeof(str) = 13 

    char *p = str;  // sizeof(p) = 8 指针大小

    void *pm = malloc(100);     // sizeof(pm) = 8 指针大小

    return 0;
}
```