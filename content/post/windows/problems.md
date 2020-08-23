---
title: "Problems"
date: 2020-08-22T10:27:23+08:00
draft: true
---

# VMware
## 您的主机不满足在启用 Hyper-V 或 Device/Credential Guard 的情况下运行 VMware Player 的最低要求。
关于 Hyper-V，代号Viridian， 旧称Windows Server Virtualization，是Microsoft的本地虚拟机管理程序，它可以在运行x86-64位的Windows上创建虚拟机。

解决办法：关闭 Hyper-V，
以管理员身份运行Windows Powershell (管理员)（Windows键+X）
运行下面命令并重启电脑：
`bcdedit /set hypervisorlaunchtype off`
