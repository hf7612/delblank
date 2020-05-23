// C program to implement one side of FIFO  // This side writes first, then reads  
#include <stdio.h>  
#include <string.h>  
#include <fcntl.h>  
#include <sys/stat.h>  
#include <sys/types.h>  
#include <unistd.h>    
#include <signal.h>
#include <log/log.h> 
int main(int argc, char *argv[]) { 
    #if 0
    int fd; char * myfifo = "/data/local/tmp/myfifo3"; mkfifo(myfifo, 0666); char arr1[80], arr2[80];  int i; signal(SIGPIPE, SIG_IGN);
char buf[]="gggg1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890\n";
    printf(" i:%d \n", i);// while (1)
    {          // Open FIFO for write only 
        fd = open(myfifo, O_WRONLY|O_APPEND);//O_WRONLY|);// |O_NONBLOCK);             // Take an input arr2ing from user.          // 80 is maximum length O_NONBLOCK
        if(fd <= 0){
            printf(" err \n");
        }
        fcntl(fd, F_SETFL, O_NONBLOCK);
        for(;;){//i=0;i<100000000; i++){
            char b2[1024]; printf(" i:%d \n", i);
            write(fd, buf, strlen(buf));
            sprintf(b2," i:%d \n", i);
            write(fd, b2, strlen(b2)); i++; sleep(1);
            
        }// fgets(arr2, 80, stdin);             // Write the input arr2ing on FIFO          // and close it 
        // write(fd, arr2, strlen(arr2)+1); 
        close(fd);             // Open FIFO for Read only 
        printf(" end\n");
        // fd = open(myfifo, O_RDONLY);             // Read from FIFO 
        // read(fd, arr1, sizeof(arr1));             // Print the read message 
        // printf("User2: %s\n", arr1); close(fd);      
        } 
    pause();
#endif
#if 1

    // ALOGE("ddj");
    // __android_log_buf_write(LOG_ID_CRASH, ANDROID_LOG_FATAL, LOG_TAG, msg.c_str());
    #undef LOG_TAG
    #define LOG_TAG "tagjoes"  
    // __android_log_buf_write(LOG_ID_MAIN, ANDROID_LOG_FATAL, LOG_TAG, "aaaa");//msg.c_str());
    // __android_log_buf_write(8, ANDROID_LOG_FATAL, LOG_TAG, "000000000000000000000000000000111111111111111111111111111111aaaa");//msg.c_str());
    // __android_log_buf_write(8, ANDROID_LOG_FATAL, LOG_TAG, argv[1]);//msg.c_str());
    __android_log_buf_write(8, 3, LOG_TAG, argv[1]);//msg.c_str());
    // ALOGE("joes123123");
    #endif
    return 0;  } 