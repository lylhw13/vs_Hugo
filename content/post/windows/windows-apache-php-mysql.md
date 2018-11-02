---
title: "Windows 10下Apache + PHP + Mysql的环境配置"
date: 2018-09-11T09:55:53+08:00
draft: false
tags: ["Windows","Apache","Php","Mysql"]
categories: ["Windows"]
---

参考文章如下:

[Windows下Apache+PHP+MySQL搭建历程](https://www.jianshu.com/p/9f41bcdff322),

[How to install web server on Windows 10 (Apache 2.4, PHP 7, MySQL 8.0 and phpMyAdmin)](https://miloserdov.org/?p=55)


## 模块选择

- Apache 2.4.34, 
Apache的软件包为httpd-2.4.34-win64-VC15.zip, 下载目录为<https://www.apachelounge.com/download/>

- php 7.2.9
php 软件包为php-7.2.9-Win32-VC15-x64.zip, 下载目录为<https://windows.php.net/download/>, 选择VC15 x64 Thread Safe version

- MySQL 8.0.12, 软件包为mysql-installer-community-8.0.12.0.msi,

- phpMyAdmin 4.8.3, 软件包为phpMyAdmin-4.8.3-all-languages.zip, 下载地址为<https://www.phpmyadmin.net/>

关于Apache和php的版本选择, 这两个版本必须搭配, 如果不搭配就会出现如下错误:

```sh
λ httpd.exe
httpd.exe: Syntax error on line 183 of D:/amp/Apache24/conf/httpd.conf: Cannot load D:/amp/php5/php5apache2_4.dll into server: The specified module could not be found.
```

解决方法参考[“Cannot load php5apache2_4.dll into server”问题的解决方法](https://my.oschina.net/idearye/blog/192265), 
可以看到[官网](https://windows.php.net/)对于版本选择的解释如下:

>Which version do I choose?
>
>IIS
If you are using PHP as FastCGI with IIS you should use the Non-Thread Safe (NTS) versions of PHP.
>
>Apache
Please use the Apache builds provided by [Apache Lounge](http://apachelounge.com/). They provide VC11, VC14 and VC15 builds of Apache for x86 and x64. We use their binaries to build the Apache SAPIs.
>
>If you are using PHP as module with Apache builds from apache.org (not recommended) you need to use the older VC6 versions of PHP compiled with the legacy Visual Studio 6 compiler. Do NOT use VC11+ versions of PHP with the apache.org binaries.
>
>With Apache you have to use the Thread Safe (TS) versions of PHP.
>
>VC11, VC14 & VC15
More recent versions of PHP are built with VC11, VC14 or VC15 (Visual Studio 2012, 2015 or 2017 compiler respectively) and include improvements in performance and stability.
>
>- The VC11 builds require to have the Visual C++ Redistributable for Visual Studio 2012 x86 or x64 installed
>
>- The VC14 builds require to have the Visual C++ Redistributable for Visual Studio 2015 x86 or x64 installed
>
>- The VC15 builds require to have the Visual C++ Redistributable for Visual Studio 2017 x64 or x86 installed

## 安装
新建amp目录,将所有软件都集中到AMP目录下面

Apcahe, php, phpMyAdmin 均为免安装版本,直接解压到目标目录下面即可,

MySQL安装: 这个为之前默认安装

## 配置
### Apache 配置
编辑httpd.conf文件, 目录为:`D:\amp\Apache24\conf\`, 
- 修改服务器端口:

    查找 listen, 把80端口改为8080端口, 以避免和IIS端口号冲突,如下
    ```sh
    Listen 8080
    ```
- 加载PHP模块:
    在`#LoadModule vhost_alias_module modules/mod_vhost_alias.so`行后添加如下内容:
    ```sh
    LoadModule php7_module "D:/amp/php7/php7apache2_4.dll"
    AddType application/x-httpd-php .php .html .htm
    PHPIniDir "D:/amp/php7"
    ```
- 设置网站入口:
    Replace
    ```sh
    DocumentRoot "${SRVROOT}/htdocs"
    <Directory "${SRVROOT}/htdocs">
    ```
    with
    ```sh
    DocumentRoot "D:/amp/data/htdocs"
    <Directory "D:/amp/data/htdocs">
    ```
    

