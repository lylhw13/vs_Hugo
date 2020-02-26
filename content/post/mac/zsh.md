---
title: "Zsh"
date: 2019-01-03T20:26:22+08:00
draft: true
---

# install plugins
配置参考<https://www.cnblogs.com/xishuai/p/mac-iterm2.html>
<https://medium.com/@caulfieldOwen/youre-missing-out-on-a-better-mac-terminal-experience-d73647abf6d7>
## install zsh-syntax-highlighting  
refer to <https://github.com/zsh-users/zsh-syntax-highlighting/blob/master/INSTALL.md>

1. Clone this repository in oh-my-zsh's plugins directory:
    ```sh
    git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting
    ```
2. Activate the plugin in ~/.zshrc:
    ```sh
    plugins=( [plugins...] zsh-syntax-highlighting)
    ```
3. Source ~/.zshrc to take changes into account:
    ```sh
    source ~/.zshrc
    ```

## install zsh-autosuggestions
```sh
git clone https://github.com/zsh-users/zsh-autosuggestions ~/.oh-my-zsh/custom/plugins/zsh-autosuggestions
```

# command not found
- modify the ~/.zshrc, then add the new path.
- source ~/.zshrc

## use proxy

通过命令打开文件，然后在后续添加你的代理地址
```sh
# 打开配置文件
vim ~/.bash_profile
# 如果用了`oh-my-zsh` 那么修改`~/.zshrc`
# 在后面新增配置
export http_proxy=http://127.0.0.1:1087
export https_proxy=$http_proxy
# 同理，可能执行` source ~/.zshrc`
source ~/.bash_profile
```

修改测试
可以通过如下方式进行测试
```sh
# 方式1：输入如下命令,看看显示的运行商是什么，如果是国外那么就ok
curl cip.cc

# 方式2：通过google测试，有结果，说明Ok
curl -i https://google.com
```

### 快速切换

可以在 ~/.zshrc 或者 ~/.bash_profile 中添加这样的alias：
```sh
alias useproxy='export all_proxy=socks5://127.0.0.1:1086'
alias disproxy='unset all_proxy'
```