#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc,char *argv[]){ 
    struct stat buf;
    if(argc == 3){
        if(!stat(argv[2], &buf)){
            if(buf.st_atime != buf.st_mtime) printf("%s\n", argv[2]);
        }else {
            printf("no %s\n", argv[1]);
        }
    }else{
        FILE *pF = fopen(argv[1], "r");
        if(pF){
            if(!stat(argv[1], &buf)){
                int len = buf.st_size;
                char *s = malloc(len+1);s[len]=0;
                int r = fread(s, 1, len, pF);
                char *sR = s; int i = 0;
                while (i<len) {
                    if(s[i]=='\n'){ s[i] = 0; // printf(sR);
                        if(!stat(sR, &buf)){
                            if(buf.st_atime != buf.st_mtime) printf("%s\n", sR);
                        }else { printf("no %s\n", sR); }
                        sR = s+i+1; }
                    if(i>=len) break;
                    i++; 
                } 
            }
            fclose(pF);
        }
    }
}