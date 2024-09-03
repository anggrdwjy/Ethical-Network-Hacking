gcc -c -fPIC hack.c -o hack
gcc -shared hack -o hack.so
