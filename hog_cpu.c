#include <pthread.h>
#include "stdio.h"
char *s;
#define STEP (1024*1024*10)
void *print_message_function( void *ptr )
{ 
    int i = 0;
    int l = atoi((char*)ptr);// message = (char *) ptr; atoi(argv[1]);
    s=malloc(l);
    int maxStep=l/STEP; printf(" %d \n", maxStep);
    char c = 0;
    while (1){
        for(i=0; i<maxStep; i++){
            memset(s+STEP*i, c++, STEP); }
        if(l>maxStep*STEP)
            memset(s+STEP*i, c++, l-maxStep*STEP);
    } 
    //  char *message;
    //  message = (char *) ptr;
    //  printf("%s \n", message);
}
main()
{
     pthread_t thread1, thread2;
     const char *message1 = "100000";//"Thread 1";
     const char *message2 = "100000";//"Thread 2";
     int  iret1, iret2;
    /* Create independent threads each of which will execute function */
     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     if(iret1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(-1);
     }
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);
     if(iret2)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(-1);
     }
     printf("pthread_create() for thread 1 returns: %d\n",iret1);
     printf("pthread_create() for thread 2 returns: %d\n",iret2);
     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */
     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); }

// int main(int argc, char *argv[]){
//     if(argc == 2){
//         int i = 0;
//         int l = atoi(argv[1]);
//         s=malloc(l);
//         int maxStep=l/STEP; printf(" %d \n", maxStep);
//         char c = 0;
//         while (1){
//             for(i=0; i<maxStep; i++){
//                 memset(s+STEP*i, c++, STEP); }
//             if(l>maxStep*STEP)
//                 memset(s+STEP*i, c++, l-maxStep*STEP);
//         }
//     }
// }
