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

# Mac 安装python3 和 virtualenv，virtualenvwrapper

1. macos自带python2.7.10，但是没有pip，首先安装pip
   ```sh
   sudo easy_install pip
   pip --version    # 查看version，此pip指向python 2.7
   which python     # 查看python的路径
   ```
2. 利用Homebrew安装python 3，安装python默认是包含pip
   ```sh
   brew install python
   #or
   brew install python3
   pip3 --version   # 查看pip3的版本，此pip3指向python 3.7
   which python     # 查看python3的路径
   ```
3. 利用pip3安装virtualenv和virtaulenvwrapper, 这样 virtualenvwrapper的默认python版本是python3
   ```sh
   pip3 install virtualenv virtualenvwrapper
   ```
4. 修改~/.zshrc，添加以下几行. 这里因为是基于pip3安装，所以必须指定python版本，否则会试图用系统默认的python版本，然后报错：No module named virtualenvwrapper
   ```sh
   export WORKON_HOME=$HOME/.virtualenvs
   export PROJECT_HOME=$HOME/Devel
   export VIRTUALENVWRAPPER_PYTHON=/usr/local/bin/python3
   source /usr/local/bin/virtualenvwrapper.sh
   ```
5. 创建虚拟环境，可以指定python版本
    ```sh
    mkvirtualenv -p python new_env_name
    #or
    mkvirtualenv --python=python new_env_name
    ```
6. 退出当前虚拟环境
    ```sh
    deactivate
    ```
7. 其他命令
    ```sh
    rmvirtualenv  ENVNAME      # delete a env
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


https://kyfw.12306.cn/otn/czxx/queryByTrainNo?train_no=5l000G193220&from_station_telecode=NKH&to_station_telecode=LLF&depart_date=2019-01-31