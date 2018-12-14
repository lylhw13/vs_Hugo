---
title: "Commands"
date: 2018-10-27T19:05:28+08:00
draft: true
---

# change password on root user and user account

```sh
sudo passwd                 #change the root passwd
passwd                      #change your user passwd
sudo passwd USERNAME        #change other users passwd
```
reter to [Change password on root user and user account](https://askubuntu.com/questions/423942/change-password-on-root-user-and-user-account)



# centos7 下安装netstat
```sh
yum install net-tools
netstat -tulpn
```

```sh
vim /etc/nginx/nginx.conf

```

```sh
firewall-cmd --zone=public --add-port=80/tcp --permanent
firewall-cmd --list-ports
firewall-cmd --reload
```
```sh
cat /var/log/mysqld.log | grep password

systemctl start mysqld.service

mysql -uroot -p

mysql
Hello!.13

grant all privileges on *.* to 'root'@'%' identified by 'Haha!.13' with grant option;
flush privileges;
```

```sh

npm isntall mysql

var mysql= require("mysql");
//Error: Cannot find module 'mysql'

var mysql = require('/usr/bin/mysql');
(function (exports, require, module, __filename, __dirname) {ELF 
                                                              ^

SyntaxError: Invalid or unexpected token


```

yum list intalled |grep mysql