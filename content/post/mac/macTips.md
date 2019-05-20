---
title: "Mac tips"
date: 2018-10-21T10:33:50+08:00
draft: false
tags: ["Tips"]
categories: ["Mac"]
---
# shortcuts

commands | function
-- | --
`control + a` | go to beginning of a line
`control + e` | go to end of a line

commands | function
-- | --
`command + q` | quit any mac program
`command + w` | close the current active tab
`command + option + w` | close all the tabs
`command + t` | open a new web browser tab
`command + shift + t` | open the most recently closed tab
`command + tab` | activate built-in application switcher
`command + shift + 3` | take a picture of the entire screen
`command + shift + 4` | can take a picture as you selected
`command + h` | hide the current active app
`command + option + h` | hide other apps but the current active app

| commands | function |
| --- | --- |
| option + esc | read the word |

| commands | function |
| --- | --- |
| shift + option + ? | ¿ |


Reference: [Top 10 Mac keyboard shortcuts everyone should know](https://www.cultofmac.com/317935/top-10-mac-keyboard-shortcuts/)

# Terminal

## checksum
```sh
# calculate md5 checksum
md5 /tmp/filename
# calculate SHA-1 checksum
shasum -a 1 filename
# calculate SHA-256 checksum
shasum -a 256 filename
```
## Copy the Current Path from Terminal to the Clipboard in Mac OS X
```sh
pwd                 # print current directory
pwd | pbcopy          # copy path to clipboard
pbpaste             # paste the clipboard
```

## connect to linux server
```sh
ssh -p port user-name@the-server-ip
ssh -p 22 root@140.82.17.1
```

# 查看环境参数
```sh
printenv            #查看环境参数
echo $SHELL         
echo $PATH
rm -rf          #force to delete a non-empty folder
```

# [Two Ways to Reveal the Location of a Spotlight Search Result in OS X](https://www.tekrevue.com/tip/show-spotlight-results-in-finder/)

- preview spotlight location with command key

    `tap and hold the command key`
- reveal the spotlight result's location in finder
  
    `command + return or (command + double-click)`


## zip
refer to <https://apple.stackexchange.com/questions/12371/how-can-i-compress-a-folder-into-multiple-zip-files>

Use the -s switch on the zip command in terminal. So if your folder was called FolderName

`zip -r -s 64 archive.zip FolderName/`

64 is the size of the split (in this case 64Mb).

if want to encrypt, use -e

`zip -r -s 64 archive.zip FolderName/ -e`

>Use -s to set the split size and create a split archive.  
The size is  given  as  a  number  followed optionally  by  one  
of  k (kB), m (MB), g (GB), or t (TB) (the default is m). [1]
Use zipsplit to split a zip file in to multiple smaller zipfiles. Use the -n switch to set the size of the splits.
