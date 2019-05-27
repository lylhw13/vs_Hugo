---
title: "Spider"
date: 2018-07-26T10:30:24+08:00
draft: true
tage: ["Python", "Scrapy"] 
categories: ["Python"]
---

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
```

## pip install from git repo branch

<https://stackoverflow.com/questions/20101834/pip-install-from-git-repo-branch>

```sh
#install the master
pip install git+https://github.com/tangentlabs/django-oscar-paypal.git
#install some branch, for example a branch name is issue/34/oscar-0.6
pip install git+https://github.com/tangentlabs/django-oscar-paypal.git@issue/34/oscar-0.6
```

## installing specific package versions with pip

```sh
pip install MySQL_python==1.2.2

#if have an installed version, should do as following:
pip install -Iv MySQL_python==1.2.2
#or
pip install --force-reinstall MySQL_python==1.2.2
#or
pip uninstall MySQL_python
pip install MySQL_python==1.2.2

#install a range version
pip install 'stevedore>=1.3.0,<1.4.0'
```


## pip install from zip file

download the selenium-master.zip

```sh
pip install 
```

## ImportError: No module named 'win32api'

```sh
pip install pypiwin32
```


## Error 1
`selenium.common.exceptions.WebDriverException: Message: unknown error: DevToolsActivePort file doesn't exist
  (Driver info: chromedriver=2.40.565498 (ea082db3280dd6843ebfb08a625e3eb905c4f5ab),platform=Windows NT 10.0.17134 x86_64)`

解决办法如下：
```python
options = webdriver.ChromeOptions()
options.binary_location = 'D:/Python/tools/chromedriver.exe'
browser = webdriver.Chrome(executable_path=options.binary_location, chrome_options=options)

#更改为
options = webdriver.ChromeOptions()
browser = webdriver.Chrome(executable_path='D:/Python/tools/chromedriver.exe', chrome_options=options)
```

## Force scrapy to crawl duplicate url

<https://stackoverflow.com/questions/23131283/how-to-force-scrapy-to-crawl-duplicate-url>

two methods:

1. add `dont_filter=True` argument on `Request()`.

  ```python
  Request(url=self.browser.current_url, callback=self.parse, dont_filter=True)
  ```

2. disable the duplicate filter by modify settings.py

  ```python
  # settings.py
  DUPEFILTER_CLASS = 'scrapy.dupefilters.BaseDupeFilter'
  ```

## signals

### error in pydispath

ScrapyDeprecationWarning: Importing from scrapy.xlib.pydispatch is deprecated and will no longer be supported in future Scrapy versions. If you just want to connect signals use the from_crawler class method, otherwise import pydispatch directly if needed. See: https://github.com/scrapy/scrapy/issues/1762

change the dispatch as the following:

<https://doc.scrapy.org/en/latest/topics/signals.html?highlight=signal>

```python
from scrapy import signals
from scrapy import Spider


class DmozSpider(Spider):
    name = "dmoz"
    allowed_domains = ["dmoz.org"]
    start_urls = [
        "http://www.dmoz.org/Computers/Programming/Languages/Python/Books/",
        "http://www.dmoz.org/Computers/Programming/Languages/Python/Resources/",
    ]


    @classmethod
    def from_crawler(cls, crawler, *args, **kwargs):
        spider = super(DmozSpider, cls).from_crawler(crawler, *args, **kwargs)
        crawler.signals.connect(spider.spider_closed, signal=signals.spider_closed)
        return spider


    def spider_closed(self, spider):
        spider.logger.info('Spider closed: %s', spider.name)


    def parse(self, response):
        pass
```

## mysql

参考<https://stackoverflow.com/questions/45125422/how-to-import-mysqlclient-in-python3>

```sh
pip install mysqlclient #   安装mysql 的驱动
pip install -i https://pypi.douban.com/simple/ mysqlclient  #用豆瓣源进行加速安装
```
但是上面的安装方法经常会出现错误，可以先下载[mysqlclient的whl文件](https://www.lfd.uci.edu/~gohlke/pythonlibs/#mysqlclient)再安装
```sh
pip install mysqlclient-1.3.13-cp35-cp35m-win_amd64.whl
```

## python mysql issues

Error message:

`TypeError: %d format: a number is required, not str`

Answer:

`The format string is not really a normal Python format string. You must always use %s for all fields.`


## xpath

/bookstore/book[last()]         # 选取属于 bookstore 子元素的最后一个 book 元素

//input[starts-with(@name,'name1')]    # 查找name属性中开始位置包含'name1'关键字的页面元素

//input[contains(@name,'na')]        # 查找name属性中包含na关键字的页面元素


