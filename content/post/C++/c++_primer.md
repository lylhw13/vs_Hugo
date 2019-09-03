---
title: "C++_primer"
date: 2019-03-07T15:09:15+08:00
draft: true
---

header | function/library
-- | --
functional | bind
iterator | vary kinds of iterators
stdexcept | runtime_error

# chapter 2

Default initialization
- variables defined outside any function body are initialized to zero.
- variables of built-in type defined inside a function are unitialized.

## 2.3
```c++
int &refVal2;           // error: a reference must be initialized.
int &refVal4 = 10;      // error: initializer must be an object.
double dval = 3.14;
int &refVal5 = dval;    // error: initialzer must be an int object. 
```

## 2.6
In-class initializers are restricted as to thr form, we can use: They must either be enclosed inside curly braces or follow an = sign. We may not specify an in-class initializer inside parentheses.

# chapter 3

- A string is a variable-length sequence of characters.
- A vector is a variable-length sequence of objects of a given type.

c-style character string is indeed an array of char with null-terminated.

```c++
string s;
const char *str = s.c_str();    // the change of s can infect the str.
```

## 3.5
By default, the elements in an array are defult initialzed. As with variables of built-in type, a default-initialized array of build-in type that is defined inside a function will have undefined values.(p113)
```c++
string sa[10];          // all elements are empty string
int ia[10];             // all elements are 0
int main() {
    string sa2[10];     // all elements are empty string
    int ia2[10];        // all elements are undefined
}
```

arrays are not class types, so these functions are not member functions. (p118)
```c++
int ia[] = {...};
int *beg = begin(ia);

vector<int> vec = {...};
vector<int>::iterator beg = vec.begin();
```

Unlike subscripts for vector and string, the index of the built-in subscript operator is not an unsigned type. (p121)


## 3.6 Multidimensional Arrays

To use a multidimensional array in a range for, the loop control variable for all but the innermost array must be references. (p128)
```c++
int ia[3][4];
for (auto &row: ia)   // right
    for (auto col: row)
for (auto row: ia)    // wrong, because the row will convert to a pointer to that array's first element.
    for (auto col: row)

using int_array = int[4];
typedef int int_array[4];
for (int_array *p = ia; p != ia + 3; ++p) {
    for (int *q = *p; q != *p + 4; ++q)
        cout << *q <<'';
    cout << endl;
}
```

# chapter 5

A block is not terminated by a semicolon.

case labels must be integral constant expressions.
```c++
int ival = 1;
switch(ch){
    case 3.14: // error
    case ival: //error
    case 'a': //ok
```
A do while ends with a semicolon after the parenthesized condition.
```c++
do
    statement
while (condition);
```
A break statement terminates the nearest enclosing while, do while, for, or switch statment.
A continue statement terminates the current iteration of the nearest enclosing loop and immediately begins the next iteration.

# chapter 6

## 6.2
- Because we cannot copy an array, we cannot pass an array by value. 
- Because array are converted to pointers, when we pass an array to a function, we are actually passing a pointer to the array's first element. (p214)

Because we cannot copy an array, a function cannot return an array. However, a function can return a pointer or a refferenc to an array. (p228)
```c++
typedef int arrT[10];
using arrT = int[10];
arrT* func(int i);
```

## 6.7
Just as with arrays, when we pass a function as an argument, it will be automatically converted to a pointer.

As with arrays, we can't return a function type but can return a pointer to a function type.

It is important to note that `decltype` returns the function type, not a pointer to function type.

# chapter 7
```c++
//p294
Sales_data obj();           // opps! declares a function, not an object
Sales_data obj2;            // ok: obj2 is an object, not a function
```
A constructor that can be called with a single argument defines an implicit conversion from the constrctos's parameter type to the class type. `p295`

- The string constrctor that takes a single parameter of type const char* is not explicit.
- The vector constrctor that takes a size is explicit.    `p297`

when we define a member outside the class, we do not repeat the keyword:
- explicit      `p296`
- static        `p302`
- virtual       `p595`

### 7.5.6
In addition to the arithmetic types, references, and pointers, certain calles are also literal types.

# chapter 10

```c++
// back_inserter
vector<int> vec;
fill_n(back_inserter(vec), 10, 0);

// copy algorithms
int a1[] = {1,2,3};
int a2[sizeof(a1)/sizeof(*a1)];
auto ret = copy(begin(a1), end(a1), a2);    // ret will point just past the last element copied into a2.

```

```c++
// Lambdas
// we can omit either or both of the parameter list and return type but must always include the capture list and function body. (p388)
[capture list] (parameter list) -> return type {function body};

for_each(words.begin(), words.end(), [&os, c](const string &s) { os << s <<c;});

auto f = [v1] () mutable {return ++v1;};

// By default, if a lambda body contains any statements other than a return, that lambda is assumed to return void. (p396)
[](int i) { return i<0?-i:i;};
[](int i) -> int { if (i<0) return -i; else return i;};

auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {...});
auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz) {...});
```

# chapter 12

## 12.1

```c++
// p459
string *ps1 = new string;   // default initialized to the empty string
string *ps = new string();  // value initialized to the empty string
int *pi1 = new int;         // default initialized; *pi1 is undefined
int *pi2 = new int();       // value initialized to 0; *pi2 is 0
```

The pointer we pass to delete must either point to dynamically allocated memory or be a null pointer.

```c++
int *pia = new int[get_size()];

typedef int arrT[42];
int *p = new arrT;      // new T[]

delete [] p;
```
It is important to remember that what we call a dynamic array does not have an array type.

we cannot supply an element initializer inside the parentheses.

```c++
char arr[0];                //error
char *cp = new char[0];     //ok, but cp can't be dereferenced
```

# chapter 13

tilde ~

# chapter 15

## 15.2
The declartation contains the class name but does not include its derivation list.

There is No implicit conversion from base to derived and No conversion between objects.

# chapter 18

## 18.2 Namespaces

like blocks, namespaces do not end with a semicolon.