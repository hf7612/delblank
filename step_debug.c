#include <signal.h>
#include <unistd.h>
#include <stdio.h>
int i=1;
void sigroutine(int dunno) { /* 信号处理例程，其中dunno将会得到信号的值 */
switch (dunno) {
case SIGUSR1:
printf("Get a signal -- SIGHUP \n");
i=0;
break;
case 2:
printf("Get a signal -- SIGINT ");
break;
case 3:
printf("Get a signal -- SIGQUIT ");
break;
}
return;
}

int main() {
printf("process id is %d ",getpid());
signal(SIGUSR1, sigroutine); //* 下面设置三个信号的处理方法
signal(SIGINT, sigroutine);
signal(SIGQUIT, sigroutine);
while (i) {
	sleep(1); printf(" aaaa \n"); 
}
i=1;
while (i) {
	sleep(1); printf(" aaaa44 \n");
}
i=1;

}