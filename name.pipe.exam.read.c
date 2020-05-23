// C program to implement one side of FIFO  // This side reads first, then reads  
#include <stdio.h>  
#include <string.h>  
#include <fcntl.h>  
#include <sys/stat.h>  
#include <sys/types.h>  
#include <unistd.h>    
int main() { int fd1; char * myfifo = "/cache/myfifo3";//"/data/local/tmp/myfifo3";
 signal(SIGPIPE, SIG_IGN); mkfifo(myfifo, 0666);    int i;
     
    // while (1) {          // First open in read only and read 
    while(1){
        fd1 = open(myfifo,O_RDONLY); 
        // fcntl(fd, F_SETFL, O_NONBLOCK);
        for(;;){//i=0;i<5;i++){
            char str1[4096]={0}, str2[80];  //while(1){
            int r = read(fd1, str1, 4096); printf("aaaaa r:%d %s\n", r, str1);
            if(r<=0)
                break;

        }
        close(fd1);             // Now open in write mode and write          // string taken from user. 
        sleep(1);
    }
        // fd1 = open(myfifo,O_WRONLY); 
        // fgets(str2, 80, stdin); 
        // write(fd1, str2, strlen(str2)+1); close(fd1);      } 
    return 0;  } 