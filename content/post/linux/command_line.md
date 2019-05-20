---
title: "Command_line"
date: 2019-05-17T23:29:08+08:00
draft: true
---

# chapter 1
shell prompt:
- a pound sign ("#"): superuser privileges
- a dollar sign ("$"): normal.

| command | meaning | 
| --- | --- |
| date | date |
| cal | calender |
| df | free space on our disk drives |
| free | display the amount of free memory (`not for mac`)|
| exit or ctrl-d | ending a Terminal Session |

We can access these sessions, called virtual terminals or virtual consoles, by pressing Ctrl-Alt-F1 through Ctrl-Alt- F6 on most Linux distributions. When a session is accessed, it presents a login prompt into which we can enter our username and password. To switch from one virtual console to another, press Alt-F1 through Alt-F6. On most system we can return to the graphical desktop by pressing Alt-F7.

# chapter 2
- pwd – Print name of current working directory
- cd – Change directory
- ls – List directory contents

Note that unlike Windows, which has a separate file system tree for each storage device, Unix-like systems such as Linux always have a single file system tree, regardless of how many drives or storage devices are attached to the computer. Storage devices are attached (or more correctly, mounted) at various points on the tree according to the whims of the system administrator, the person (or people) responsible for the maintenance of the sys- tem.

Note that unlike Windows, which has a separate file system tree for each storage device, Unix-like systems such as Linux always have a single file system tree, regardless of how many drives or storage devices are attached to the computer. Storage devices are attached (or more correctly, mounted) at various points on the tree according to the whims of the system administrator, the person (or people) responsible for the maintenance of the sys- tem.

The "." notation refers to the working directory and the ".." notation refers to the working directory's parent directory. 

In almost all cases, we can omit the "./". It is implied. 

| shortcut | result |
| -- | -- |
| cd | Changes the working directory to your home directory. |
| cd - | Changes the working directory to the previous working directory. |
| cd ~user_name | Changes the working directory to the home directory of user_name. For example, cd ~bob will change the directory to the home directory of user “bob.” |

- Filenames that begin with a period character are hidden.
- Filenames and commands in Linux, like Unix, are case sensitive.
- Linux has no concept of a “file extension” 
- Though Linux supports long filenames that may contain embedded spaces and punctuation characters, limit the punctuation characters in the names of files you create to period, dash, and underscore. Most importantly, do not embed spaces in filenames. If you want to represent spaces between words in a file- name, use underscore characters. 

# chapter 3 – Exploring the System
- ls – List directory contents
- file – Determine file type 
- less – Viewfilecontents

Table 3-2: ls Long Listing Fields p40

one of the common ideas in Unix-like operating systems such as Linux is that “everything is a file.”

Once the less program starts, we can view the contents of the file. If the file is longer than one page, we can scroll up and down. To exit less, press the q key.

Table 3-3: less Commands p43

If you are using a mouse, you can double click on a filename to copy it and middle click to paste it into commands.

Table 3-4: Directories Found on Linux Systems p44

# chapter 4 – Manipulating Files and Directories
- cp – Copy files and directories
- mv – Move/rename files and directories
- mkdir – Create directories
- rm – Remove files and directories
- ln – Create hard and symbolic links

Table 4-1: Wildcards p50

Table 4-2: Commonly Used Character Classes p50

A note on notation: When three periods follow an argument in the description of a com- mand (as above), it means that the argument can be repeated.
Table 4-4: cp Options p53

Here is a useful tip: whenever you use wildcards with rm (besides carefully checking your typing!), test the wildcard first with ls. This will let you see the files that will be deleted. Then press the up arrow key to recall the command and replace ls with rm.

```sh
ln file link            # create hard link
ln -s item link         # create symbolic link, item may be directory.
```

1. A hard link cannot reference a file outside its own file system. This means a link cannot reference a file that is not on the same disk partition as the link itself.
2. A hard link may not reference a directory.

The length of a symbolic link is the length of the target item name.

# chapter 5 – Working with Commands

- type – Indicate how a command name is interpreted
- which – Display which executable program will be executed
- help – Get help for shell builtins (not work for mac)
- man – Display a command's manual page
- apropos – Display a list of appropriate commands
- info – Display a command's info entry
- whatis – Display one-line manual page descriptions
- alias – Create an alias for a command

```sh
alias name='string'         #p75
```

# chapter 6 – Redirection

- cat – Concatenate files
- sort – Sort lines of text
- uniq – Report or omit repeated lines
- grep – Print lines matching a pattern
- wc – Print newline, word, and byte counts for each file
- head – Output the first part of a file
- tail – Output the last part of a file
- tee – Read from standard input and write to standard output and files

```sh
ls -l /bin/usr 2> ls-error.txt          # only redirection error
ls -l /bin/usr 2> /dev/null             # disposing of error output

# redirection output and error 
# old version
ls -l /bin/usr > ls-output.txt 2>&1
# new version
ls -l /bin/usr &> ls-output.txt
ls -l /bin/usr &>> ls-output.txt

command1 > file1            # be careful, it will overwrite 
command1 | command2
```

wildcards always expand in sorted order

uniq
The uniq command is often used in conjunction with sort. uniq accepts a sorted list of data. It only removes the successive duplicates.

There are a couple of handy options for grep:
- -i, which causes grep to ignore case when performing the search (normally searches are case sensitive)
- -v, which tells grep to print only those lines that do not match the pattern.

Using the “-f” option, tail continues to monitor the file, and when new lines are ap- pended, they immediately appear on the display. This continues until we press Ctrl-c.

# chapter 7 – Seeing the World as the Shell Sees It
- echo – Display a line of text

As we know, filenames that begin with a period character are hidden.

tilde character (~)

Arithmetic expansion uses the following form:
`$((expression))`. Note, the double brackets.

Arithmetic expansion supports only integers (whole numbers, no decimals) but can per- form quite a number of different operations. 

Table 7-1: Arithmetic Operators p95

Brace Expansion
```sh
$ echo Front-{A,B,C}-Back 
Front-A-Back Front-B-Back Front-C-Back
$ echo Number_{1..5} 
Number_1 Number_2 Number_3 Number_4 Number_5
$ echo {01..15}
01 02 03 04 05 06 07 08 09 10 11 12 13 14 15
```
In bash version 4.0 and newer, integers may also be zero-padded
Brace expansions may be nested.

Parameter Expansion
```sh
ls -l $(which cp)
```
Backslash Escape Sequences

# chapter 8 – Advanced Keyboard Tricks

- clear – Clear the screen
- history – Display the contents of the history list

Table 8-1: Cursor Movement Commands p106
Table 8-2: Text Editing Commands
Table 8-3: Cut and Paste Commands

bash will expand !88 into the contents of the 88th line in the history list.

Table 8-5: History Commands p111
Table 8-6: History Expansion Commands p112

# chapter 9 – Permissions

- id – Display user identity
- chmod – Change a file's mode
- umask – Set the default file permissions
- su – Run a shell as another user
- sudo – Execute a command as another user
- chown – Change a file's owner
- chgrp – Change a file's group ownership
- passwd – Change a user's password

Table 9-1: File Types p116

| Owner | Group | World |
| --- | --- | --- |
| rwx | rwx | rwx |

Table 9-4: File Modes in Binary and Octal p120
Table 9-5: chmod Symbolic Notation p121
Table 9-6: chmod Symbolic Notation Examples p121
Table 9-7: chown Argument Examples p129

This is because sudo, in most configurations, “trusts” us for several minutes until its timer runs out.

# chapter 10 – Processes

- ps – Report a snapshot of current processes
- top – Display tasks, Viewing Processes Dynamically
- jobs – List active jobs
- bg – Place a job in the background
- fg – Place a job in the foreground
- kill – Send a signal to a process
- killall – Kill processes by name
- shutdown – Shutdown or reboot the system

TTY is short for “teletype,” and refers to the controlling terminal for the process. 

Table 10-1: Process States p136

# chapter 11 – The Environment

- printenv – Print part or all of the environment
- set – Set shell options
- export – Export environment to subsequently executed programs
- alias – Create an alias for a command

The set command will show both the shell and environment variables, while printenv will only display the latter.
Unlike printenv, its output is courteously sorted in alphabetical order.

One element of the environment that neither set nor printenv displays is aliases.

Table 11-2: Startup Files for Login Shell Sessions p156
Table 11-3: Startup Files for Non-Login Shell Sessions p156

`export PATH` <br />
The export command tells the shell to make the contents of PATH available to child processes of this shell.

Whenever we edit an important configuration file, it is always a good idea to create a backup copy of the file first.

```sh
source ~/.bashrc            #force bash to reread the modified .bashrc file
```

# chapter 12 – A Gentle Introduction to vi

tilde characters (~)
Table 12-1: Cursor Movement Keys p170
Table 12-3: Text Deletion Commands p173

Table 12-6: Replace Confirmation Keys p178

# chapter 13 – Customizing the Prompt

Table 13-1: Escape Codes Used in Shell Prompts p187

# chapter 14 – Package Management

Table 14-1: Major Packaging System Families p197
Table 14- 2: Packaging System Tools p199

- Low-level tools which handle tasks such as installing and removing package files
- High-level tools that perform metadata searching and dependency resolution

If a package file has been downloaded from a source other than a repository, it can be in- stalled directly (though without dependency resolution) using a low-level tool.

Because this technique uses the low-level rpm program to perform the in- stallation, no dependency resolution is performed. If rpm discovers a missing de- pendency, rpm will exit with an error.

# chapter 15 – Storage Media

- mount – Mount a file system
- umount – Unmount a file system
- fsck – Check and repair a file system
- fdisk – Manipulate disk partition table
- mkfs – Create a file system
- dd – Convert and copy a file
- genisoimage (mkisofs) – Create an ISO 9660 image file
- wodim (cdrecord) – Write data to optical storage media
- md5sum – Calculate an MD5 checksum

fstab short for “file system table”.
