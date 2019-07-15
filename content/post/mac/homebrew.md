---
title: "Homebrew"
date: 2019-04-09T17:29:13+08:00
draft: true
---

## Commands
```sh
brew list           # show a list of all your installed homebrew packages
brew cask list      # show the items installed using the caskroom
brew cask insatll [software]
brew info [package]         # show the information
```

## 为 Homebrew 添加代理

Refer to [让 Homebrew 走代理更新](https://www.logcg.com/archives/1617.html)

临时调用代理的话
```sh
export ALL_PROXY=socks5://127.0.0.1:1086
```

写入终端配置的话：
```sh
# for bash shell
echo export ALL_PROXY=socks5://127.0.0.1:1086 >> ~/.bash_profile
# for zsh shell
echo export ALL_PROXY=socks5://127.0.0.1:1086 >> ~/.zsh_profile
```

But can'r ping behind the proxy. ping needs a direct network connection on the IP level to do its work. A proxy works on a higher layer of the TCP/IP network model, where there is no direct access to the IP protocol.

You would need to somehow circumvent the proxy (change firewall settings, use a VPN, ...). Whether this is possible (and allowed) depends on your network configuration, but it's probably not possible.

As a workaround, there are many web-based ping services available (search for "web-based ping"). These will work.