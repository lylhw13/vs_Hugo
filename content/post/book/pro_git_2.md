---
title: "Pro_git_2"
date: 2019-06-13T17:00:07+08:00
draft: true
---
## Git 历史
集中化的版本控制系统（Centralied Version Control Systems, 简称 CVCS）
分布式版本控制系统（Distributed Version Control System，简称 DVCS）

Git 更像是把数据看作是对小型文件系统的一组快照。Git 更像是一个小型的文件系统，提供了许多以此为基础构建的超强工具，而不只是一个简单的 VCS。 

Git 中所有数据在存储前都计算校验和，然后以校验和来引用。Git 用以计算校验和的机制叫做 `SHA-1` 散列（hash，哈希）。
实际上，Git 数据库中保存的信息都是以文件内容的哈希值来索引，而不是文件名。

Git 一般只添加数据

Git 有三种状态，你的文件可能处于其中之一：已提交（committed）、已修改（modified）和已暂存（staged）。 已提交表示数据已经安全的保存在本地数据库中。 已修改表示修改了文件，但还没保存到数据库中。 已暂存表示对一个已修改文件的当前版本做了标记，使之包含在下次提交的快照中。

由此引入 Git 项目的三个工作区域的概念：Git 仓库、工作目录以及暂存区域。

暂存区域是一个文件，保存了下次将提交的文件列表信息，一般在 Git 仓库目录中。

```git
# 全局修改用户信息
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com

git config --list           # 检查配置信息
git config user.name        # 查看某一配置

# 查看帮助
git help <verb>
git <verb> --help
man git-<verb>
```

## Git 基础

```git
git init
```

Git 所使用的命令是"clone"而不是"checkout"。这是 Git 区别于其它版本控制系统的一个重要特性，Git 克隆的是该 Git 仓库服务器上的几乎所有数据，而不是仅仅复制完成你的工作所需要文件。 当你执行 git clone 命令的时候，默认配置下远程 Git 仓库中的每一个文件的每一个版本都将被拉取下来。

```git
git clone [url]
```
Git 支持多种数据传输协议。 上面的例子使用的是 https:// 协议，不过你也可以使用 git:// 协议或者使用 SSH 传输协议

1. Untracked
2. Unmodified 
3. Modified 
4. Staged

- Changes to be committed 待提交，说明是已暂存状态，这条提示下面是暂存区
- Changes not staged for commit 说明已跟踪文件的内容发生了变化，但还没有放到暂存区，这条提示下面是非暂存区

git add 是个多功能命令：可以用它开始跟踪新文件，或者把已跟踪的文件放到暂存区，还能用于合并时把有冲突的文件标记为已解决状态等。

git commit 提交的是最后一次运行 git add 命令时的那个版本，运行 git commit 时，在工作目录中的当前版本。

```git
$ git status -s
 M README
MM Rakefile
A  lib/git.rb
M  lib/simplegit.rb
?? LICENSE.txt
```
- ??  新添加的未跟踪文件
- A   新添加到暂存区中的文件
- M   表示修改过
    - M 靠左，说明已经放入暂存区
    - M 靠右，说明还没有放入暂存区。


文件 .gitignore 的格式规范如下：
- 所有空行或者以 ＃ 开头的行都会被 Git 忽略。
- 可以使用标准的 glob 模式匹配。
- 匹配模式可以以（/）开头防止递归。
- 匹配模式可以以（/）结尾指定目录。
- 要忽略指定模式以外的文件或目录，可以在模式前加上惊叹号（!）取反。

所谓的 glob 模式是指 shell 所使用的简化了的正则表达式。 [abc] 匹配任何一个列在方括号中的字符；[0-9] 表示匹配所有 0 到 9 之间的数字。 使用两个星号（*) 表示匹配任意中间目录，比如`a/**/z` 可以匹配 a/z, a/b/z 或 `a/b/c/z`等。

```git
$ cat .gitignore

# 忽略所有以 .o 或 .a 结尾的文件
*.[oa]

# no .a files
*.a

# but do track lib.a, even though you're ignoring .a files above
!lib.a

# only ignore the TODO file in the current directory, not subdir/TODO
/TODO

# ignore file
README.txt

# ignore folder build
build/

# ignore doc/notes.txt, but not doc/server/arch.txt
doc/*.txt

# ignore all .pdf files in the doc/ directory
doc/**/*.pdf
```

```git
git diff            # 只显示尚未暂存的改动
git diff --staged   # 查看已暂存的将要添加到下次提交里的内容
```

给 git commit 加上 -a 选项，Git 就会自动把所有已经跟踪过的文件暂存起来一并提交，从而跳过 git add 步骤:

    git commit -a -m 'added new benchmarks'

### 删除文件

```git
git rm [file]           # 从工作目录中删除指定的文件
git rm --cached [file]  # 从暂存区删除，但仍然保留在当前工作目录中
```

### 移动文件
```git
git mv file_from file_to
```

### 查看提交历史

git log 会按提交时间列出所有的更新，最近的更新排在最上面。 

```git
git log -p -2           # -p，用来显示每次提交的内容差异, -2 来仅显示最近两次提交
git log --stat          # 显示每次提交的简略的统计信息

git log --pretty=oneline
git log --pretty=format:"%h - %an, %ar : %s"
git log --pretty=format:"%h %s" --graph
```

其实作者指的是实际作出修改的人，提交者指的是最后将此工作成果提交到仓库的人。

### 撤销操作

有时候我们提交完了才发现漏掉了几个文件没有添加，或者提交信息写错了。 此时，可以运行带有 --amend 选项的提交命令尝试重新提交：
    
git commit --amend

```git
git commit -m 'initial commit'
git add forgotten_file
git commit --amend
```

最终你只会有一个提交 - 第二次提交将代替第一次提交的结果。

### 取消暂存操作

```git
git reset HEAD <file>...            # 来取消 file 文件的暂存
```

### 撤消对文件的修改

```git
git checkout -- <file>...           # to discard changes in working directory
```

git checkout -- [file] 是一个危险的命令，这很重要。 你对那个文件做的任何修改都会消失 - 你只是拷贝了另一个文件来覆盖它。 除非你确实清楚不想要那个文件了，否则不要使用这个命令。

Git 中已提交的东西几乎总是可以恢复，但是未提交的可能无法恢复。

## 远程仓库的使用

```git
git remote          # 列出你指定的每一个远程服务器的简写, 一般是 origin， 这是 Git 给你克隆的仓库服务器的默认名字

git remote -v       # 显示需要读写远程仓库使用的 Git 保存的简写与其对应的 URL

git remote add <shortname> <url>        # 添加一个新的远程 Git 仓库
git fetch <remote-name>           # remote-name 可以使用上一步的 shortname 或者 URL
```

如果你使用 clone 命令克隆了一个仓库，命令会自动将其添加为远程仓库并默认以 “origin” 为简写。 所以，git fetch origin 会抓取克隆（或上一次抓取）后新推送的所有工作。

必须注意 git fetch 命令会将数据拉取到你的本地仓库 - 它并不会自动合并或修改你当前的工作。 当准备好时你必须手动将其合并入你的工作。

```git
git push [remote-name] [branch-name]

git push origin master
```

```git
git remote show [remote-name]

git remote show origin          # 查看远程仓库
```

```git
git remote rename [old-name] [new-name]

git remote rm [repository-name]
```

## 打标签

```git
git tag         # list the tags
git tag -l 'v1.8.5*'            # 查找特定标签
```

### 创建标签
Git 使用两种主要类型的标签：轻量标签（lightweight）与附注标签（annotated）。

一个轻量标签很像一个不会改变的分支 - 它只是一个特定提交的引用。

然而，附注标签是存储在 Git 数据库中的一个完整对象。 它们是可以被校验的；其中包含打标签者的名字、电子邮件地址、日期时间；还有一个标签信息；并且可以使用 GNU Privacy Guard （GPG）签名与验证。 通常建议创建附注标签，这样你可以拥有以上所有信息；但是如果你只是想用一个临时的标签，或者因为某些原因不想要保存那些信息，轻量标签也是可用的。

```git
git tag -a v1.4 -m 'my version 1.4'             # 附注标签， -m 选项指定了一条将会存储在标签中的信息
git tag v1.4-lw             #  轻量标签本质上是将提交校验和存储到一个文件中 - 没有保存任何其他信息。 创建轻量标签，不需要使用 -a、-s 或 -m 选项，只需要提供标签名字
```

```git
git config --global alias.ci commit
git config --global alias.last 'log -1 HEAD'
```

# Git 分支

有人把 Git 的分支模型称为它的“必杀技特性”。

Git 保存的不是文件的变化或者差异，而是一系列不同时刻的文件快照。

Git 的 “master” 分支并不是一个特殊分支。 它就跟其它分支完全没有区别。 之所以几乎每一个仓库都有 master 分支，是因为 git init 命令默认创建它，并且大多数人都懒得去改动它。

```git
git branch [new-branch-name]        # creating new branch
```
一个分支就是一个可以移动的指针。

在 Git 中，HEAD是一个指针，指向当前所在的本地分支（译注：将 HEAD 想象为当前分支的别名）。 在本例中，你仍然在 master 分支上。 因为 git branch 命令仅仅创建一个新分支，并不会自动切换到新分支中去。


```git
git log --oneline --decorate        # 查看各个分支当前所指的对象。
```