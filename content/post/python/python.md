---
title: "Python"
date: 2018-09-06T15:51:29+08:00
draft: true
---

#install python 

下载exe安装后，便会有pip命令

```sh
pip install virtualenv

pip install virtualenvwrapper-win   #要安装Windows版本，否则一些命令无法识别
```

新建环境变量：
`WORKON_HOME:    D:\Python\Envs`
可以指定新创建的环境的位置。

```sh
pip install scrapy

```

```sh
scrapy shell "https://book.douban.com/subject/25900156/" -s USER_AGENT="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"
scrapy shell "https://book.douban.com/subject/11611703/" -s USER_AGENT="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"
scrapy shell "https://book.douban.com/subject/1005676/" -s USER_AGENT="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"      #条目不存在
https://book.douban.com/subject/25862578/
scrapy shell "https://book.douban.com/subject/1291559/" -s USER_AGENT="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"      #301


scrapy shell "https://book.douban.com/subject/25862578/" -s USER_AGENT="Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"
```
https://httpbin.org

## Things to keep in mind while rotating user agents
1. Use User Agents strings  of recent versions of popular browsers and keep them updated
2. Rotating User-Agents without rotating IP addresses is a bad idea
3. Rotating User-Agents doesn’t guarantee that websites won’t block you