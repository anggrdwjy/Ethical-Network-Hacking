# Testing By Pass LD_PRELOAD

Source : xcode.co.id
--------
```
#Build Config
nano /var/www/html/hacking.c
gcc -c -fPIC hacking.c -o hacking
gcc -shared hacking -o hacking.so

#ByPass via BadConnect
nano /var/www/html/hacking.php
```
