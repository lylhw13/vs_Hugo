---
title: "Git_errors"
date: 2019-05-11T10:38:02+08:00
draft: true
---
## Error 1

使用git push时出现error: src refspec master does not match any.

参考链接<https://segmentfault.com/q/1010000004615080>

```sh
error: src refspec master does not match any.
error: failed to push some refs to "xxxxxxx"
```

### 解决办法

一般这种情况是因为push的时候暂存区没有文件，所以无法push。

## Error 2

使用git push时出现`error: failed to push some refs to 'git@github.com:***/***.git'`

参考链接<https://www.cnblogs.com/daemon369/p/3204646.html>

参考链接<https://stackoverflow.com/questions/10298291/cannot-push-to-github-keeps-saying-need-merge>

这种错误是远程repository和我本地的repository版本冲突导致的。
产生这种问题是因为分别在远程的repository和本地的repository执行`git init`，这样在执行`git push`的时候就会产生这样版本冲突的问题。

### 解决办法

如果远程repository不重要，就强制push:

```git
git push -f origin master
```

## Error 3
>error: Your local changes to the following files would be overwritten by merge:   
Please commit your changes or stash them before you merge.

### 解决办法
1. 服务器代码与本地代码合并
    ```sh
    git stash   #saves your local modifications away and reverts the working directory to match the HEAD commit.
    git pull    
    git stash pop 
    ```
2. 服务器代码覆盖本地代码：
    ```sh
    git reset --hard #Resets the index and working tree. Any changes to tracked files in the working tree since <commit> are discarded.
    git pull
    ```

## Error 4

-  描述
    ```sh
    > ssh-add
    Error connecting to agent: No such file or directory
    ```
- solution
    1. run `powershell` as Administrator
    1. Check the current status of ssh-agent: "Get-Service | select -property name,starttype"
    2. Set the new type : "Set-Service -Name ssh-agent -StartupType Manual"
    3. Start it: "Start-Service ssh-agent"
    4. Add simply your key as before: "ssh-add"

    refer to <https://github.com/PowerShell/Win32-OpenSSH/issues/1133#issuecomment-401064568>

## Error 5
- 描述
    >   error: RPC failed; curl 18 transfer closed with outstanding read data remaining
    >
    >   fatal: The remote end hung up unexpectedly
    > 
    >   fatal: early EOF
    > 
    >   fatal: index-pack failed

- Solution
  1.  moidfy buffer:  <br />
        `git config --global http.postBuffer 524288000`  <br />
        unit is byte
  2.  modify clone depth:  <br />
        ```git
        git clone http://github.com/large-repository --depth 1
        cd large-repository
        git fetch --unshallow
        ```
  3.  change http to ssh:  <br />
        一般clone http方式的容易产生此问题，改成SSH的方式也有效，即https://改为git://

About postBuffer:
* 查询当前http.postBuffer `git config --global --get http.postBuffer`  <br />
  the default value is 1MB

>   Maximum size in bytes of the buffer used by smart HTTP transports when POSTing data to the remote system.
> 
>   For requests larger than this buffer size, HTTP/1.1 and Transfer-Encoding: chunked is used to avoid creating a massive pack file locally. Default is 1 MiB, which is sufficient for most requests

refer to <https://blog.csdn.net/IT_liuchengli/article/details/77040806><br>
<https://stackoverflow.com/questions/38618885/error-rpc-failed-curl-transfer-closed-with-outstanding-read-data-remaining>


## Error 6
### 描述
>error: Pulling is not possible because you have unmerged files.  <br />
>`hint: Fix them up in the work tree, and then use 'git add/rm <file>'`  <br />
>`hint: as appropriate to mark resolution and make a commit.`  <br />
>fatal: Exiting because of an unresolved conflict.

### solution
先执行:   `git add .`
然后按照一般步骤执行。
