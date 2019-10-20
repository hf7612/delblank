#include <stdio.h>
#include <fcntl.h> /* Definition of AT_* constants */
#include <sys/stat.h>
int main(int argc, char *argv[]){
    struct timespec ts[2];
    ts[0].tv_nsec = UTIME_NOW;
    ts[1]=ts[0]; // int r = utimensat(AT_FDCWD, argv[2], ts, 0); // if(r) printf("  %s update fail\n", argv[2]); 
    if(argc == 3){
        int r = utimensat(AT_FDCWD, argv[2], ts, 0);
        if(r) printf("  %s update fail\n", argv[2]);
    }else{
        FILE *pF = fopen(argv[1], "r");
        if(pF){ struct stat buf;
            if(!stat(argv[1], &buf)){
                int len = buf.st_size;
                char *s = malloc(len+1);s[len]=0;
                int r = fread(s, 1, len, pF);
                char *sR = s; int i = 0;
                while (i<len) {
                    if(s[i]=='\n'){ s[i] = 0; // printf(sR);
                        int r = utimensat(AT_FDCWD, sR, ts, 0);
                        if(r) printf("  %s update fail\n",sR);
                        sR = s+i+1; }
                    if(i>=len) break;
                    i++; 
                } 
            }
            fclose(pF);
        }
    }
}