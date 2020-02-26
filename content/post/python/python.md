---
title: "Python"
date: 2018-09-06T15:51:29+08:00
draft: true
---

# Windows install virtualenv, virtualenvwrapper 

1.  下载安装python后，便会有pip命令, pip是Windows程序，不是Python里面的函数。

    ```sh
    pip install virtualenv
    pip install virtualenvwrapper-win   #要安装Windows版本，否则一些命令无法识别
    ```
2. 指定新创建的环境的位置。

    添加环境变量：`WORKON_HOME:    D:\Python\Envs`

3.  Commands for virtualenvwrapper
```sh
mkvirtualenv [-a project_path] [-i package] [-r requirements_file] [virtualenv options] ENVNAME         # make a new environment
mktmpenv [(-c|--cd)|(-n|--no-cd)] [VIRTUALENV_OPTIONS]      # Create a new virtualenv in the WORKON_HOME directory.
lsvirtualenv [-b] [-l] [-h]         # list all of the environments
showvirtualenv [env]                # Show the details for a single virtualenv.
rmvirtualenv ENVNAME                # Remove an environment, in the WORKON_HOME.
cpvirtualenv ENVNAME [TARGETENVNAME]            # Duplicate an existing virtualenv environment. 
workon [(-c|--cd)|(-n|--no-cd)] [environment_name|"."]          # List or change working virtual environments
deactivate          # Switch from a virtual environment to the system-installed version of Python.
```

## use virtualenv with vscode in windows

open setting.json, add the path of the envs folder as following. and restart.
` "python.venvPath": "D:\\Python\\Envs" `

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
   WORKON_HOME 就是创建的virtualenv的地址
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


## Proxy

创建虚拟环境时，如果需要proxy，如果使用下面代码会出现错误如下：
```sh
export all_proxy=socks5://127.0.0.1:1086

#Could not install packages due to an EnvironmentError: Missing dependencies for SOCKS support.
```
将上句修改为：
```sh
export all_proxy="https://127.0.0.1:1086"
```
- refer to <https://stackoverflow.com/a/39959360>
- refer to <https://github.com/pypa/virtualenv/issues/1156>


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

# pip

## use pip with socks proxy

refer to <https://stackoverflow.com/questions/22915705/how-to-use-pip-with-socks-proxy>

```sh
pip install pysocks
pip install <yourpacakge> --proxy socks5:127.0.0.1:1086
```

## some commands

```sh
pip help
```