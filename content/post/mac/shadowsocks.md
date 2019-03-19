---
title: "Shadowsocks"
date: 2019-01-24T21:12:41+08:00
draft: true
---

# ShadowsocksX-NG
## mac端shadowsocks相应很慢
参考<https://github.com/shadowsocks/ShadowsocksX-NG/issues/606>

调整方式为：
在System Preferences... > Network > Wi-Fi > Advanced... > Proxies将默认选项从SOCKS Proxy 修改为 Automatic Proxy Configuration，在右侧代理配置文件的'URL:'内填写'http://127.0.0.1:1089/proxy.pac'

原理为：
Local Socks5 Listen Port: 1086
Local PAC Server Listen Port: 1089
这样修改过以后，造成Global Mode模式不可用。

## 添加simple-obfs混淆
ShadowsocksX-NG 在version18.0 后集成了 kcptun 和 simple-obfs两种混淆插件。参数设置如下：
- Plugin: simple-obfs
- Plugin Opts: obfs=http;obfs-host=microsoft.com