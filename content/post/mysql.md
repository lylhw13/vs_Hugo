---
title: "Mysql"
date: 2018-09-05T16:15:23+08:00
draft: true
---

# install mysql

安装的版本为 mysql-installer-community-8.0.12.0.msi

安装完成后遇到如下问题
![mysql caching_sha2_password error](/media/pic/mysql_caching_sha2_password_error.png)

参考<https://stackoverflow.com/questions/49194719/authentication-plugin-caching-sha2-password-cannot-be-loaded>

解决办法如下：

For Windows 10: Open the command prompt

```sh
cd "C:\Program Files\MySQL\MySQL Server 8.0\bin"

C:\Program Files\MySQL\MySQL Server 8.0\bin> mysql -u root -p
Enter password: *********

mysql> ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'newrootpassword';
Query OK, 0 rows affected (0.10 sec)

mysql> exit
Alternatively, you can change the my.ini configuration as the following:
```
[mysqld]

default_authentication_plugin=mysql_native_password

Restart the MySQL Server and open the Workbench again.