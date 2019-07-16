---
title: "Shadowsocks"
date: 2018-12-14T15:18:16+08:00
draft: true
---

# Server 服务端

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
会自动生成如下的配置：
{                            
    "server":"0.0.0.0",      
    "server_port":19353,     
    "password":"vultr!.",    
    "timeout":300,           
    "user":"nobody",         
    "method":"aes-256-gcm",  
    "fast_open":false,       
    "nameserver":"8.8.8.8",  
    "mode":"tcp_and_udp",    
    "plugin":"obfs-server",  
    "plugin_opts":"obfs=http"
}                            

# Client 客户端

## windows 添加混淆

- 从 [shadowssocks/simple-obfs](https://github.com/shadowsocks/simple-obfs/releases) 下载`obfs-local.zip`
- 解压出 libwinpthread-1.dll, obfs-local.exe
- 拷贝至 shadowsocks 的文件夹
- 编辑 server 参数如下：
    -   Plugin Program: `obfs-local`
    -   Plugin Options: `obfs=http;obfs-host=microsoft.com`

## Mac 添加混淆

因为 ShadowsocksX-NG, 预装的插件有：simple-obfs 和 kcptun

只用编辑 server 参数如下：
- Plugin: `simple-obfs`
- Plugin Opts: `obfs=http;obfs-host=microsoft.com`
