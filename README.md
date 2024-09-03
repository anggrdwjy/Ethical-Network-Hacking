# Ethical Hacking
Disclaimer :
---
I am not responsible for any consequences caused by this script because this script was created for ethical hacking purposes.

Learning :
---
- PTEST [Pentest Standard](http://www.pentest-standard.org/index.php/PTES_Technical_Guidelines)
- MSTG OWAPS [OWAPS](https://owasp.org/www-project-web-security-testing-guide/latest/3-The_OWASP_Testing_Framework/1-Penetration_Testing_Methodologies#owasp-testing-guides)

NetTools :
---
```
nmap -sn [IP_ADDRESS] [NETWORK]
netdiscover
```
Support Tools For Mobile Hacking:
---
Install SNAP
```
apt install snapd
systemctl start snapd.service
systemctl status snapd.service
snap version
```
Install Scrcpy
```
snap install scrcpy
```
Setup Mobile Developer via Wireless
```
Step 1: Wi-Fi Connection
Step 2: Developer Options
Step 3: Wireless Debugging
```
Install Android Debug Bridge
```
#Install ADB
apt install android-tools-adb

#Verification
adb devices

#ADB Connect via Wireless
adb connect [IP_TARGET:PORT]
scrcpy
```
