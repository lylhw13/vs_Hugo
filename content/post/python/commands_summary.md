---
title: "Commands_summary"
date: 2018-07-26T17:35:52+08:00
draft: true
---

# some commands

## If you want to write bytes then you should open the file in binary mode.

```python
f = open('/tmp/output', 'wb')
```

## append vs extend
<https://stackoverflow.com/questions/252703/difference-between-append-vs-extend-list-methods-in-python>

append: Appends object at the end.

x = [1, 2, 3]
x.append([4, 5])
print (x)
gives you: [1, 2, 3, [4, 5]]

extend: Extends list by appending elements from the iterable.

x = [1, 2, 3]
x.extend([4, 5])
print (x)
gives you: [1, 2, 3, 4, 5]

## How to properly ignore Exceptions?
<https://stackoverflow.com/questions/730764/how-to-properly-ignore-exceptions>

```python
try:
  doSomething()
except:
  pass

#or

try:
  doSomething()
except Exception:
  pass
```

The difference is, that the first one will also catch KeyboardInterrupt, SystemExit and stuff like that, which are derived directly from exceptions.BaseException, not exceptions.Exception.
See documentation for details:

try statement — http://docs.python.org/reference/compound_stmts.html#try
exceptions — http://docs.python.org/library/exceptions

## python write utf-8

<https://stackoverflow.com/questions/934160/write-to-utf-8-file-in-python>

```python
import codecs

file = codecs.open("lol", "w", "utf-8")
file.write(u'\ufeff')
file.close()

#or

with codecs.open("lol", "w", "utf-8") as file:
    file.write(u'\ufeff')
```

## converting a list to a string

<https://stackoverflow.com/questions/2906092/converting-a-list-to-a-string>

```python
buffer=[]
file2.write(' '.join(buffer))
```

## 安装package出错时

从[Unofficial Windows Binaries for Python Extension Packages](https://www.lfd.uci.edu/~gohlke/pythonlibs/)下载合适的whl文件

```sh
pip install whl_name.whl
```

## how to check if a line is an empty line

accepted
If you want to ignore lines with only whitespace:

```python
if not line.strip():
    ... do something
```

The empty string is a False value.

Or if you really want only empty lines:

```python
if line in ['\n', '\r\n']:
    ... do  something
```

## accessing in index in 'for' loops

Using an additional state variable, such as an index variable (which you would normally use in languages such as C or PHP), is considered non-pythonic.

The better option is to use the built-in function enumerate(), available in both Python 2 and 3:

```python
for idx, val in enumerate(ints):
    print(idx, val)
```

## re.match vs re.search

<http://www.runoob.com/python/python-reg-expressions.html>

re.match只匹配字符串的开始，如果字符串开始不符合正则表达式，则匹配失败，函数返回None；而re.search匹配整个字符串，直到找到一个匹配。

In list[first:last], last is not included.