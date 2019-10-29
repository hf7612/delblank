#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void segfault(int dummy) {
        printf("Help!\n");
        exit(1);//Without the exit() here, this demo will loop because the illegal assignment is restarted.
}

int main() {
        int *p = 0;

        signal(SIGSEGV, segfault);
        *p = 17;
        return 0;
}