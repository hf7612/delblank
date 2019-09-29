#include <sys/types.h>
       #include <sys/stat.h>
       #include <unistd.h>

int main(int argc, char *argv[]){
    const char *pathname = argv[1];
    struct stat statbuf;
    if(!stat(pathname, &statbuf)){
        if(memcmp(&statbuf.st_atim, &statbuf.st_mtim, sizeof(statbuf.st_atim))){// if(statbuf.st_atim == statbuf.st_mtim){
            printf(argv[1]);
        }
    }
}