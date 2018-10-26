---
title: "Js"
date: 2018-09-08T13:31:23+08:00
draft: true
---

# cannot load php5apache2_4.dll into server

参考<https://my.oschina.net/idearye/blog/192265>

```sh
λ httpd.exe
httpd.exe: Syntax error on line 183 of D:/amp/Apache24/conf/httpd.conf: Cannot load D:/amp/php5/php5apache2_4.dll into server: The specified module could not be found.
```

出现这种错误一般是因为php和apache用的版本不匹配，参考[官网](https://windows.php.net/)解释如下

>Which version do I choose?
>
>IIS
If you are using PHP as FastCGI with IIS you should use the Non-Thread Safe (NTS) versions of PHP.
>
>Apache
Please use the Apache builds provided by Apache Lounge. They provide VC11, VC14 and VC15 builds of Apache for x86 and x64. We use their binaries to build the Apache SAPIs.
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

因此这里选择的版本是`php-7.2.9-Win32-VC15-x64.zip`

# Apache
file:///D:/amp/readme_first.html

Installation

You must first install the Visual C++ 2008 Redistributable Package. Download and Install, if you have not done so already (see URL above)

Unzip the Apache24 folder in the package zip file to the root directory on any drive. This is the "ServerRoot" in the config.
Example: c:\Apache24

To test your installation;

Open a command prompt window and cd to the \Apace24\bin folder on the drive you unzipped the zip file to.

To Start Apache in the command prompt type:

httpd.exe
Press Enter. If there are any errors it will tell you. Warnings will not stop Apache from working, they do need to be addressed none the less. If there are no errors (there shouldn't be, but it happens) the cursor will sit and blink on the next line. So far so good.

This distribution comes pre-configured for localhost. You can now test your installation by opening up your Web Browser and typing in the address:

http://localhost
If everything is working properly you should see the Apache Haus's test page.

You can shut down Apache by pressing Ctrl+C (It may take a few seconds)


To Install Apache as a service:

In most cases you will want to run Apache as a Windows Service. 
To do so you install Apache as a service by typing at the command prompt [1];

httpd -k install
You can then start Apache by typing

httpd -k start
Apache will then start and eventually release the command prompt window.

[1] You have to run the command prompt as Administrator in Windows Vista/7/2008/8/8.1/10/2012/


Other Command line options:

Stop Apache	 	httpd -k stop
Restart Apache	httpd -k restart
Uninstall Apache Service	httpd -k uninstall
Test Config Syntax	httpd -t
Version Details	httpd -V
Command Line Options List	httpd -h

## 解决httpd: Could not reliably determine the server's fully qualified domain name
用记事本打开 httpd.conf

将里面的 #ServerName localhost:80 注释去掉即可。

再执行 httpd

然后可以通过浏览器访问 http://localhost:80 ，如果页面显示 “It works！” ，即表示apache已安装并启动成功。

## mysqli::query(): Couldn't fetch mysqli
<https://stackoverflow.com/questions/19937880/mysqliquery-couldnt-fetch-mysqli>

Warning: mysqli::query(): Couldn't fetch mysqli in C:\Program Files (x86)\EasyPHP-DevServer-13.1VC9\data\localweb\my portable files\class_EventCalendar.php on line 43

You are closing connection too early with DBconnection->close(); ! Do it after your queries !

Explanation: don't insert ...->close(); in __destruct(), because connection becomes closed immediately whenever CLASS is loaded.

