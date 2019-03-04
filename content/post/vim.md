---
title: "Vim commands"
date: 2018-07-06T11:09:09+08:00
draft: false
tags: ["vim"]
categories: ["vim"]
---

## 删除到文件结尾

```vim
dG  #删除到文件结尾
```

## 动作录制

参考[vim重复操作的宏录制](https://www.cnblogs.com/ini_always/archive/2011/09/21/2184446.html)

```txt
1 2 3
11 22 33
111 222 333
1111 2222 3333
```

比如这组数据，我们想删除第一列的数据(以空格分割)，如果数据行数特别多，就需要进行动作录制：

通过下面一段命令可以实现：

```vim
gg  # 将光标定位到首行
qa  # 在normal模式下开始录制，录制的宏保存在a寄存器，寄存器名称也可以为b,c,d等。
0   # 调到行首
v   # 切换到visual模式
f   # 开始查找命令
    # 查找空格
x   # 删除
j   # 向下移动一行
q   # 结束录制
3@a # 执行宏命令3次
```

## 跳转到指定行

参考[vim跳转到指定行](https://blog.csdn.net/u011848617/article/details/38434359)

下面三种都可以，其中n为行号。

```vim
ngg / nG
:n
vim +n filename #注意 + 和 n 之间没有空格
```

三者的区别在于，`ngg / nG`在编辑模式下输入，所以不需要按回车键，而`:n`在命令模式下输入还需要按回车键命令才会生效，`vim +n filename` 只能在打开文件上跳转。

ctrl + g 会返回如下信息：
`"filename" m lines --n%--`
其中m为总行数，n为当前行所在整个文件的位置比例。

## 刷新vim内容

刷新内容：`:e` 或者`:edit`

强制刷新内容：`:e!`或者`:edit!`

## 删除双引号中的内容，其他配对括号同理如'', (), {}, <>

```vim
ci"     #删除引号中的内容，并进入编辑模式
di"     #删除引号中的内容
yi"     #复制引号中的内容
vi"     #选中引号中的内容
```
## 批量替换内容
参考[vim批量替换命令实践](https://www.cnblogs.com/beenoisy/p/4046074.html)

```vim
:[addr]s/origin_str/target_str/[option]
```
`[addr]` 表示检索范围：

- 省略时表示当前行。
- `1,20` 表示从1到20行
- `%` 表示整个文件，同"1,$"
- `.,$` 表示从当前行到文件尾

`s`:    表示替换操作

`[option]`表示操作类型:

- `g` 表示全局替换
- `c` 表示进行确认
- `p` 表示替代结果逐行显示（Ctrl + L恢复屏幕
- 省略option时仅对每行第一个匹配串进行替换
- 如果在源字符串和目的字符串中出现特殊字符，需要用”\”转义 如 \t

```vim
:%s/origin_str/target_str/g    #全局替换命令
```

## replace word under cursor

```sh
ciw         # (change inner word) change the whole word under the cursor.
cw          # only change the word from the current cursor position. 
```