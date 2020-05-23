#include <stdio.h>	/* for printf */
#include <stdint.h>	/* for uint64 definition */
#include <stdlib.h>	/* for exit() definition */
#include <time.h>
#include <inttypes.h>

char *s;
#define STEP (1024*1024*10)
#define BILLION 1000000000L
int main(int argc, char *argv[]){ long long i = 0; uint64_t diff; struct timespec start, end; long long j = 0;
    if(argc == 2){
        i = 0; j = 0;
        long long l = atoll(argv[1]); //4096000000U;//
        s=malloc(l); printf(" l:%lld \n" , l);
        long long maxStep=l/STEP; printf(" l:%lld %lld \n", l, maxStep);
        char c = 0; int sum = 0;
        // for(i=0; i<maxStep; i++){
        //         memset(s+STEP*i, c++, STEP);
        //         for(j=0;j<STEP; j++) sum+=s[STEP*i+j]; }
        // if(l>maxStep*STEP){
        //     memset(s+STEP*i, c++, l-maxStep*STEP);
        //     for(j=0;j<l-maxStep*STEP; j++) sum+=s[STEP*i+j];
        // }
        // printf(" sum:%x \n", sum); CLOCK_MONOTONIC_RAW CLOCK_PROCESS_CPUTIME_ID
        
        while (1){ sum = 0; c = 0;  //printf("\n");
            system("date");clock_gettime(CLOCK_MONOTONIC_RAW, &start);//clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start); // //printf(" beg %d %d\n", sum, start.tv_sec, start.tv_nsec);
            for(i=0; i<maxStep; i++){
                memset(s+STEP*i, c++, STEP); 
                for(j=0;j<STEP; j++) sum+=s[STEP*i+j]; }
            if(l>maxStep*STEP){
                memset(s+STEP*i, c++, l-maxStep*STEP);
                for(j=0;j<l-maxStep*STEP; j++) sum+=s[STEP*i+j]; }
            // printf(" sum:%x \n", sum);
            clock_gettime(CLOCK_MONOTONIC_RAW, &end);  //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);  //
            diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
            // printf(" end %llu \n", (long long unsigned int) diff);
            system("date"); printf(" -----------------------\n");//printf(" end %d %d\n", sum, tp.tv_sec, tp.tv_nsec);
            sleep(1);
        } 
    }else if(argc == 3){
        int unit=atoi(argv[1]);
        int blks=atoi(argv[2]);
        char *s1=malloc(unit*blks);
        char c = 0;
        for(i=0; i<blks; i++){
            memset(s1+unit*i, c++, unit); }
        while (1){
            for(i=0; i<blks; i++){
                memset(s1+unit*i, c++, unit); } 
            sleep(1); }
    }else printf("memeater blockunit blocks \n")    ;
}