---
title: "Kali_install"
date: 2019-05-26T17:18:09+08:00
draft: true
---

refer to 
[How to set up Kali Linux OS in cloud at Just $2.50/Month for penetration testing](https://arulkumar.in/how-to-set-up-kali-linux-in-cloud-at-just-2-50-month-for-penetration-testing/) <br>
[如何优雅地在VULTR上运行KALI](http://gt4404gb.top/archives/669)

1. upload iso to vultr by using link
2. install kali linux by `View Console`
3. remove the uploaded custom ISO from Vultr server settings.Otherwise, your instance will get stuck on Installer Boot Menu during startup.
4. modify ssh server
    - Login to the box via Web console and Edit the 'sshd_config' file.
    `root@Jarvis:~# nano /etc/ssh/sshd_config`

    - Inside the 'sshd_config', Uncomment and Edit the 
    following lines. 
    ```sh
    Port 22     
    .....   
    PermitRootLogin yes
    ```

    - Enable the SSH service on startup by using following commands.
    ```sh
    root@Jarvis:~# systemctl start ssh
    root@Jarvis:~# systemctl enable ssh
    ```
