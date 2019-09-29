#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
void handler(int s)
{
    if (s == SIGUSR1) fflush(stdout);//printf(" now got a bus error signal\n");
    if (s == SIGINT) { printf(" int \n"); exit(0);}
}
int main(void) {  signal(SIGUSR1, handler); signal(SIGINT, handler);   
    time_t current_time; char* c_time_string; current_time = time(NULL);// if (current_time == ((time_t)-1)) { (void) fprintf(stderr, "Failure to obtain the current time.\n"); exit(EXIT_FAILURE); } /* Convert to local time format. */
    c_time_string = ctime(&current_time); //if (c_time_string == NULL) { (void) fprintf(stderr, "Failure to convert the current time.\n"); exit(EXIT_FAILURE); } /* Print to stdout. ctime() has already added a terminating newline character. */ // (void) printf("Current time is %s", c_time_string);
    while(1){ // current_time = time(NULL);// if (current_time == ((time_t)-1)) { (void) fprintf(stderr, "Failure to obtain the current time.\n"); exit(EXIT_FAILURE); } /* Convert to local time format. */ // c_time_string = ctime(&current_time);        
        time_t t = time(NULL); struct tm *tp = localtime(&t); printf("%04d%02d%02d_%02d%02d%02d ",tp->tm_year + 1900, tp->tm_mon+1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec);  
        FILE *pF = fopen("/sys/class/power_supply/battery/current_now", "r");
        if(pF){
            char buf[32]; buf[0] = 0;
            fread(buf, 1, 32, pF);
            printf("%s", buf);
            fclose(pF); } // printf("%s", c_time_string);
        sleep(1); } }