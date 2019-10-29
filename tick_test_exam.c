#include <unistd.h>
#include <stdio.h>
int main() { fprintf(stdout, "No. of clock ticks per sec : %ld\n",sysconf(_SC_CLK_TCK)); return 0; }