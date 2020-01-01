---
title: "Ssh"
date: 2019-07-21T17:50:02+08:00
draft: true
---

## WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED! 
Problem:
WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED! 

Solution:
```sh
vim ~/.ssh/known_hosts
```
删去相应IP地址host的公钥。

## download file from ssh
Refer to [How to download a file from server using SSH?](https://stackoverflow.com/questions/9427553/how-to-download-a-file-from-server-using-ssh)

In your terminal, type:
```sh
scp your_username@remotehost.edu:foobar.txt /local/dir
```

replacing the username, host, remote filename, and local directory as appropriate.


```sh
```
936

Syntax:
```sh
scp <source> <destination>
```
To copy a file from B to A while logged into B:
```sh
scp /path/to/file username@a:/path/to/destination
```
To copy a file from B to A while logged into A:
```sh
scp username@b:/path/to/file /path/to/destination
```