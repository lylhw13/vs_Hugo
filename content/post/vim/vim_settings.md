---
title: "Vim_settings"
date: 2019-03-21T16:03:03+08:00
draft: true
---

# brew install vim
```sh
vim --version           # 显示vim的详细信息

system vimrc file: "$VIM/vimrc"
user vimrc file: "$HONE/.vimrc"
```
the path used by macOS's default vim install is /usr/share/vim/vimrc

# .viminfo 和 .vimrc

- ~/.viminfo 由系统自动生成，记录vim的操作行为

# setting
```vim
# spell checking 
set spell spelllang=en_us
set nospell
```
```vim
set encoding=utf-8
set fileencodings=utf-8,gbk,latin1

set number
set autoindent "Auto-indent new lines
set expandtab "Use spaces instead of tabs
set shiftwidth=4 "Number of auto-indent spaces 
filetype plugin indent on
syntax on

set tabstop=4
```

# 退出插入模式
`Esc` or `ctrl + [`

# 设置主题配色

- clone 之
git clone https://github.com/altercation/solarized
- 拷贝 vim 主题
cd solarized/vim-colors-solarized/
mkdir -p ~/.vim/colors
cp colors/solarized.vim ~/.vim/colors/
- 配置 vim
vim ~/.vimrc
syntax on
set background=dark
colorscheme solarized
set backspace=2