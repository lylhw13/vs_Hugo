---
title: "Shadowsocks"
date: 2018-12-14T15:18:16+08:00
draft: true
---

```sh
wget --no-check-certificate -O shadowsocks-all.sh https://raw.githubusercontent.com/teddysun/shadowsocks_install/master/shadowsocks-all.sh
chmod +x shadowsocks-all.sh
./shadowsocks-all.sh 2>&1 | tee shadowsocks-all.log
```
## 卸载
```sh
./shadowsocks-all.sh uninstall
```

## 脚本命令
```sh
/etc/init.d/shadowsocks-libev start | stop | restart | status
```

## 配置文件
`/etc/shadowsocks-libev/config.json`
