---
title: "使用Hugo搭建个人博客并部署到GitHub上"
date: 2018-06-30T15:26:58+08:00
draft: false
topics: ["Hugo", "GitHub"]
tags: ["Hugo", "GitHub"]
categories: ["Hugo"]
---
# 一， 使用Hugo搭建个人博客

## 安装Hugo

这里是在Windows安装Hugo，其他安装可以参考官方文档。

* 下载hugod的发布版,地址为 <https://github.com/gohugoio/hugo/releases> , 下载完成后解压到任意文件夹

* 将该hugo.exe的路径添加到Windows的环境变量中

* 如果安装正确，通过 hugo version 可以得到hugo的版本信息

## 搭建博客

* 创建你的博客

```sh
hugo new site mysite
```

这条命令会在`mysite`文件夹里创建一个新的`site`。

* 安装主题

```sh
cd mysite
git init
git submodule add https://github.com/budparr/gohugo-theme-ananke.git themes/ananke

# Edit your config.toml configuration file
# and add the Ananke theme.
echo 'theme = "ananke"' >> config.toml
```

* 添加一个新的内容

```sh
hugo new post/first-post.md
```

这个命令会生成一个markdown文件，目录为`mysite/content/post`，hugo会利用已经安装的主题生成一个新的post。

* 启动Hugo

```sh
hugo server -D
```

会启动一个本地的hugo server，在浏览器里通过<http://localhost:1313>即可访问。

# 二，将Hugo部署到GitHub上

个人理解：其实就是本地编写markdown内容文件，用hugo渲染成静态网页，然后将这些静态网页push到你的GitHub Pages上。这些静态网页的目录为`mysite/public`。

## 创建Github Pages

创建GitHub Pages比较简单，只要创建一个格式为`yourusername.github.io`的仓库即可。
![create_a_github_pages](/media/pic/create_a_github_pages.png)

## 部署Hugo

* 修改 config.toml

修改`mysite/config.toml`，将其中的`baseURL`调整为你自己的网址:

```toml
baseURL = "http://lylhw13.github.io/"
```

* 利用Hugo生成静态网页

```sh
hugo --buildDrafts


* 上传到Github

切换到public目录，然后将整个文件夹全部push到之前创建的仓库里。

```sh
cd public
git init
git remote add origin git@github.com:lylhw13/yourusername.github.io.git
git add -A
git commit -m "first commit"
git push -u origin master
# Tips:
# if you repository has been init before. Here you may encounter some errors. So you can change the last line as following:
# git push -u origin master --force
```

然后，就可以通过`yourusername.github.io`访问你的博客。

# 其他

## 后续发布文章
```sh
hugo new post/newpages.md #generate markdown files
hugo #generate your new pages

cd public 
git add -A
git commit -m "xxx"
git push -u origin master
```

## 常见问题：

### Error 1:

```sh
$ hugo
Error: Unable to locate Config file. Perhaps you need to create a new site.
       Run `hugo help new` for details.
```
是因为当前目录不对，应该首先切换到`mysite`的根目录下再执行`hugo`命令。

### 文章中添加图片
在`mysite/static`中新建文件夹`media`，并统一将图片放在这里，但是图片的引用链接应该从`media`开始，如`/media/pic/create_a_github_pages.png`。

## 参考文章：

* <https://www.jianshu.com/p/834d7cc0668d>
* <https://gdzhu8023.github.io/post/buildblog/>