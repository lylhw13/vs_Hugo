---
title: "通过QQ音乐网页抓取周杰伦歌曲的歌词并制作相关词云"
date: 2018-07-30T14:30:22+08:00
draft: true
---

# 通过QQ音乐网页抓取周杰伦歌曲的歌词

## 创建一个全新的python环境

```sh
#创建一个新的python环境，这里因为已经安装过virtualenvwrapper， 所以命令如下
mkvirtualenv [mkvirtualenv-options] [virtualenv-options] DEST_DIR
#新的环境自动激活，然后下载安装scrapy
pip install scrapy
#创建一个新的scrapy工程
scrapy startproject collectonLyrics
#利用默认模板生成一个spider
cd collectionLytics
scrapy genspider colLyrics qq.com

pip install selenium
pin install mysqlclient
#如果某些包安装出现错误，可以先下载[相应的whl文件](https://www.lfd.uci.edu/~gohlke/pythonlibs/)再安装
```

# 豆瓣
```python
pip install mysqlclient
pip install requests
pip install redis
pip install pandas
pip install fake_useragent
pip install pypiwin32
pip install Pillow
```