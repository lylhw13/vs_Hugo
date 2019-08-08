---
title: "Colud_not_get_lock_Resource_temporarily_unavailable"
date: 2019-08-07T10:20:44+08:00
draft: true
---

Refer to [How to solve Kali Linux CLI error: Could not get lock /var/lib/dpkg/lock – open (9: Resource temporarily unavailable)](https://ourcodeworld.com/articles/read/824/how-to-solve-kali-linux-cli-error-could-not-get-lock-var-lib-dpkg-lock-open-9-resource-temporarily-unavailable)

- Problem:
    >E: Could not get lock /var/lib/apt/lists/lock - open (11: Resource temporarily unavailable)    <br/>
    >E: Unable to lock directory /var/lib/apt/lists/

- Solution:
    ```sh
    sudo rm /var/lib/apt/lists/lock
    sudo rm /var/cache/apt/archives/lock
    sudo rm /var/lib/dpkg/lock
    ```