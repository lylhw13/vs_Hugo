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