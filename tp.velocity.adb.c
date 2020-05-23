
#include <stdio.h>
void main(){int r;
    char b3[]="19: 335 377 333 296 5931 2629 2040 1543 mt-eint 0 Edge fts_ts";
    int i2[9];char b8[1024];
    sscanf(b3, "%s %d", b8, &i2[2]); printf(" %d ", i2[2]);
    FILE *pF = popen("a shell cat /proc/cpuinfo", "r");
    if(pF){
        char buf[256];
        while(fgets(buf, 1024, pF)){  //printf(" buf:%s \n", buf);
            if(strstr(buf, "processor")){
                printf(" buf:%s \n", buf);
                // processor	: 7
                int i;
                if(sscanf(buf, "processor	: %d", &i)>0) printf(" i:%d \n", i);
            }
        }
        pclose(pF);
    }
    int oldA[9];
    #define KEY_WORD "Level     ts" //note6
    // #define KEY_WORD "fts_ts" //milan
    while(1){ //printf("%s", "a shell \"grep '" KEY_WORD "' /proc/interrupts\" ");
        char  *s="a shell \"grep '" KEY_WORD "' /proc/interrupts\" "; //printf(" cmd:%s\n", s);
        pF = popen(s, "r"); //pF = popen("a shell grep fts_ts /proc/interrupts", "r"); //pF = popen("a shell grep fts_ts /proc/interrupts|sed -r 's|\\s+| |g'", "r");// 
        if(pF){ char buf[256];
            while(fgets(buf, 1024, pF)){  //printf(" buf:%s \n", buf);
                if(strstr(buf, KEY_WORD)){ char b9[1024]; /// "fts_ts")){ 
                    // printf(" b buf:%s \n", buf);
                    // processor	: 7
                    int i[9];int n=1; // "19: 335 377 333 296 5931 2629 2040 1543 mt-eint 0 Edge fts_ts";
                    if((r=sscanf(buf, "%s %d %d %d %d %d %d %d %d", b9, &i[1], &i[2],&i[3],&i[4],&i[5],&i[6],&i[7],&i[8])) >= 0 ){ int sum=0; // if((r=sscanf(buf, "%s %d %d", b9, &i[1], &i[2])) >= 0 ){ // if((r=sscanf(buf, ": %d %d %d %d %d %d %d %d ", &i[1],&i[2],&i[n++],&i[n++],&i[n++],&i[n++],&i[n++],&i[n++])) > 0 ){ 
                        // printf(" i list:\n", i);
                        // for(n=1;n<9;n++)
                        //     printf(" %d ", i[n]);
                        // printf(" i list end\n"); 
                        for(n=1;n<9;n++){
                            sum+=i[n]-oldA[n];
                        } printf(" sum:%d \n", sum);
                        memcpy(oldA, i, sizeof(i)); //printf(" i old list:\n", i);
                        // for(n=1;n<9;n++)
                        //     printf(" %d ", oldA[n]); printf(" i old list end\n");
                    }
                }
            }
            pclose(pF);
        }
        sleep(1); 
    }
}