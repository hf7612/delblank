#include "MyHeader.h" /* for user-defined constants */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> /* basic system data types */
#include <sys/socket.h> /* basic socket definitions */
#include <errno.h> /* for the EINTR constant */
#include <sys/wait.h> /* for the waitpid() system call */
#include <sys/un.h> /* for Unix domain sockets */ /* Size of the request queue. */
#define LISTENQ 20 /* The use of this functions avoids the generation of "zombie" processes. */ // SEQPACKET
void sig_chld( int signo ) { pid_t pid; int stat;
       while ( ( pid = waitpid( -1, &stat, WNOHANG ) ) > 0 ) { printf( "Child %d terminated.\n", pid ); } }
int main( int argc, char **argv ) { int listenfd, connfd;  pid_t childpid; socklen_t clilen; struct sockaddr_un cliaddr, servaddr; signal( SIGCHLD, sig_chld ); /* Avoid "zombie" process generation. */
       listenfd = socket(AF_LOCAL, SOCK_SEQPACKET, 0 ); //listenfd = socket( AF_LOCAL, SOCK_STREAM, 0 ); 
       unlink( UNIXSTR_PATH ); /* Remove any previous socket with the same filename. */
       bzero( &servaddr, sizeof( servaddr ) ); servaddr.sun_family = AF_LOCAL; strcpy( servaddr.sun_path, UNIXSTR_PATH ); /* Define the name of this socket. */ /* Create the file for the socket and register it as a socket. */
       bind( listenfd, ( struct sockaddr* ) &servaddr, sizeof( servaddr ) );
       listen( listenfd, LISTENQ ); /* Create request queue. */
       for ( ; ; ) { clilen = sizeof( cliaddr ); /* Copy next request from the queue to connfd and remove it from the queue. */
              connfd = accept( listenfd, ( struct sockaddr * ) &cliaddr, &clilen );
              if ( connfd < 0 ) { if ( errno == EINTR ) continue; else { fprintf( stderr, "Accept Error\n" ); return -1; } }// exit( 0 );
              childpid = fork(); /* Spawn a child. */ 
              if ( childpid == 0 ) { close( listenfd );/* Child process. */ /* Close listening socket. */ // char line;
                    //  while ( read( connfd, &line, sizeof( char ) ) > 0 ) putchar( line );
                     while ( write( connfd, "aaaa\n", 5 ) > 0 ) sleep(1);//putchar( line );
                     putchar( '\n' ); return -1; }// exit( 0 );  /* Terminate child process. */ 
              close(connfd); } }