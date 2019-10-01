#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 
 #include <stdio.h>
#define MAX_PATH 1024
int main(int argc, char *argv[]){ const char *pathname;// = argv[1];
    struct stat statbuf;
    if(argc == 3){
        if(!strcmp(argv[1], "-f")){ pathname = argv[2];
            if(!stat(pathname, &statbuf)){
                if(memcmp(&statbuf.st_atim, &statbuf.st_mtim, sizeof(statbuf.st_atim))){// if(statbuf.st_atim == statbuf.st_mtim){
                    printf(argv[2]); printf("\n"); }}
        }else printf(" var err \n");
    }else if(argc == 2){
        FILE *pF = fopen(argv[2], "r");
        if(pF){ char buf[MAX_PATH]; buf[0] = 0; char *pS; pathname = argv[2];
            if(!stat(pathname, &statbuf)){
                if(statbuf.st_size > 0){ pS = malloc(statbuf.st_size+1);
                    if(pS){ pS[statbuf.st_size] = 0; int r = fread(pS, 1, statbuf.st_size, pF);
                        if(r > 0){ char *sR = pS; char *t;  
                            while(t=strchr(sR, '\n')){   t[0]=0; //printf(sR);
                                if(!stat(sR, &statbuf)){
                                    if(memcmp(&statbuf.st_atim, &statbuf.st_mtim, sizeof(statbuf.st_atim))){// if(statbuf.st_atim == statbuf.st_mtim){
                                        printf(sR); printf("\n"); }}
                                sR = t+1;   } } }}} // while(fgets(buf, 1, MAX_PATH, pF)){ w }
            fclose(pF); } }}