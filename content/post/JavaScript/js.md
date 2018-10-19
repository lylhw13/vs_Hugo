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