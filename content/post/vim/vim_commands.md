---
title: "Vim commands"
date: 2018-07-06T11:09:09+08:00
draft: false
tags: ["vim"]
categories: ["vim"]
---

# Cursor Movement Keys
| Key | Moves The Cursor |
| --- | --- |
| 0(zero) | To the beginning of the current line. |
| ^ | To the first non-whitespace character on the current line. |
| $ | To the end of the current line. |
| w | To the beginning of the next word or punctuation character. |
| W | To the beginning of the next word, ignoring punctuation characters. |
| b | To the beginning of the previous word or punctuation character. |
| B | To the beginning of the previous word, ignoring punctuation characters. |
| Ctrl-f or Page Down | Down one page. |
| Ctrl-b or Page Up | Up one page. |
| numberG | To line number. For example, 1G moves to the first line of the file. |
| G | To the last line of the file. |

# 删除

## 删除双引号中的内容，其他配对括号同理如'', (), {}, <>

```vim
ci"     #删除引号中的内容，并进入编辑模式
di"     #删除引号中的内容
yi"     #复制引号中的内容
vi"     #选中引号中的内容
```
## 删除到

```vim
dG          #删除到文件结尾
d$          #删除到行尾，而不是 dt$
dtc         #删除到字符c，但是不包括c
dfc         #删除到字符c，也包括c
:1,10d      #删除从1到10行
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
## 复制全文
```vim
ggVGy           #复制
ggVG"+y         #复制到系统剪切板
```
-   gg 让光标移到首行，在vim才有效，vi中无效 
-   V   是进入Visual(可视）模式 
-   G  光标移到最后一行 


## copy to clipboard
refer to <https://stackoverflow.com/questions/3961859/how-to-copy-to-clipboard-in-vim>

The * register will do this. 
In Windows, + and * are equivalent. In unix there is a subtle difference between + and *:

>Under Windows, the * and + registers are equivalent. For X11 systems, though, they differ. For X11 systems, * is the selection, and + is the cut buffer (like clipboard). http://vim.wikia.com/wiki/Accessing_the_system_clipboard

`*` is probably what you want most of the time, so I use * because it functions as I expect it to in both environments.

In Linux distros, for some reason, you have to install vim-gtk first to gain clipboard functionality.

And for those confused about how to use registers when yanking or putting, you merely write " then the name of the register. So for copying something to the clipboard register you type ` "*y ` and then to put you type ` "*p `


参考https://www.zhihu.com/question/19863631/answer/89354508

Vim 中的复制、删除的内容都会被存放到默认（未命名）寄存器中，之后可以通过粘贴操作读取默认寄存器中的内容。寄存器是完成这一过程的中转站，Vim 支持的寄存器非常多，其中常用的有 a-zA-Z0-9+“。其中：
- 0-9：表示数字寄存器，是 Vim 用来保存最近复制、删除等操作的内容，其中 0 号寄存器保存的是最近一次的操作内容。
- a-zA-Z：表示用户寄存器，Vim 不会读写这部分寄存器
- "（单个双引号）：未命名的寄存器，是 Vim 的默认寄存器，例如删除、复制等操作的内容都会被保存到这里。
- +：剪切板寄存器，关联系统剪切板，保存在这个寄存器中的内容可以被系统其他程序访问，也可以通过这个寄存器访问其他程序保存到剪切板中的内容。

## join two lines
J joins the two lines and moves you at the start of the text you wanted to delete. This deletes a new-line character and the indentation of the line you want to move.
D deletes from the current cursor position to the end of the line but preserves the new-line character.

## swap two lines
To swap the current line with the next one, type ddp while in command mode.

dd - delete line (actually called cut in other editors) and save it in register
p - paste line from buffer

## 列编辑
[Vim 的纵向编辑模式](https://www.ibm.com/developerworks/cn/linux/l-cn-vimcolumn/index.html)



```vim
:e ~/.vim/ftplugin/sh.vim

:reg            # To see the current contents of the registers
```

it's a common custom to use the long names in configuration files for clarity.

Shift-i (command to insert at the beginning of the line)

One nice thing about macros is that vim remembers them. Each time we exit vim, the current macro definitions are stored and ready for reuse the next time we start another editing session.

As we mentioned earlier, the registers named 0-9 have a special use. When we perform ordinary yanks and deletes, vim places our latest yank in register 0 and our last nine deletes in registers 1-9. As we continue to make deletions, vim moves the previous deletion to the next number, so register 1 will contain our most recent deletion and register 9 the oldest.