---
title: "Mac下Apache + Php + Mysql的环境配置"
date: 2018-10-20T15:38:19+08:00
draft: false
tags: ["Mac","Apache","Php","Mysql"]
categories: ["Mac"]
---

# mac 下配置Apache+PHP+Mysql环境

参考<https://www.jianshu.com/p/2fb9a3bb12f6>，主要步骤按照其操作均可完成，但是仍有一些错误，需要解决。

有一个极为详细到英文版本，还没有来得及参考[Get Apache, MySQL, PHP and phpMyAdmin working on OSX 10.11 El Capitan](http://coolestguidesontheplanet.com/get-apache-mysql-php-and-phpmyadmin-working-on-osx-10-11-el-capitan/)。

macOS系统自带了Apache和PHP环境。默认没有开启Apache，最新版的seirra取消了图形界面，只能手动开启Apache。

- PHP version: 7.1.16
- Apache version: 2.4.33
- OS verison: macOS High Sierra 10.13

## 开启Apache
Apache相关命令如下：
```sh
sudo apachectl start    # start apache
sudo apachectl stop     # sotp apache
sudo apachectl restart  # restart apache 
```
获取apache的版本信息
```sh
httpd -v
httpd -V    # for get more info
```

在浏览器里输入`localhost`，如果出现`It works!`界面，表示Apache开启成功。

## 链接PHP
通过修改Apache的配置文件来开启PHP，步骤如下：

1. 打开终端，输入命令：`sudo vim /etc/apache2/httpd.conf`
2. 找到`#LoadModule php7_module libexec/apache2/libphp7.so`行，去掉前面的`#`。

macOS下Apache的默认文件夹为`/Library/WebServer/Documents`，在该目录下创建一个名为index.php文件，在文件中添加如下内容：`<?php phpinfo(); ?>`。删除原目录下的index.html文件，然后在浏览器中输入localhost，如果出现PHP的info页，则表示PHP开启成功，如果不成功，用前面的命令重启Apache再试。

## 安装Mysql
到MySQL官网下载最新的dmg安装包，这里下载的是mysql-8.0.12-macos10.13-x86_64.dmg。进入下载页面后，会提示你登陆或注册，这里不必理会，直接点击底部的“No thanks, just start my download.”即可开始下载。


## 安装phpMyAdmin

完成以上两步，MySQL就算安装配置完成了，为了方便安装一个可视化的工具phpMyAdmin。

直接到phpMyAdmin官网下载最新的zip包。下载完成后，将解压后的文件夹重命名为phpMyAdmin，然后放置到Apache路径的默认文件夹。

在浏览器中输入localhost/phpMyAdmin，出现phpMyAdmin的登陆页面，在该页面可以设置语言，然后用root和之前设置的密码登陆。如果登陆成功，则安装结束。

这里有两个问题：
<http://www.zixuephp.net/article-263.html>

### 问题1:

输入mysql的用户和秘密之后会出现如下错误：

`mysqli_real_connect(): (HY000/2002): No such file or directory`,

解决办法如下：
1. 把phpMyAdmin目录中的配置文件`config.sample.inc.php`重命名为`config.inc.php`；
2. 并将
```sh
$cfg['Servers'][$i]['host'] = 'localhost';
#   change to 
$cfg['Servers'][$i]['host'] = '127.0.0.1';
```

### 问题2:

参考<https://stackoverflow.com/questions/49948350/phpmyadmin-on-mysql-8-0>

>#2054 - The server requested authentication method unknown to the client
mysqli_real_connect(): The server requested authentication method unknown to the client [caching_sha2_password]
mysqli_real_connect(): (HY000/2054): The server requested authentication method unknown to the client

解决办法如下：
```sh
alias mysql=/ect/local/mysql/bin/mysql
# log in to mysql
mysql -u root -pPASSWORD
# change the Authentication Plugin with the password
mysql> ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'PASSWORD';
# after click enter it show the below line
Query OK, 0 rows affected (0.08 sec)
```
Tip: replace all `PASSWORD` to you password for root user.
