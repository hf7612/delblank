#include "MyHeader.h" /* for user-defined constants */
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h> /* basic socket definitions */
#include <sys/types.h> /* basic system data types */
#include <sys/un.h> /* for Unix domain sockets */
#include <unistd.h>
int main( int argc, char **argv )
{
       int sockfd;
       struct sockaddr_un servaddr; /* Struct for the server socket address. */
       // int pid;
       // char send;

       printf( "Write freely. Terminate with Ctrl-D or Ctrl-C.\n" );

       sockfd = socket( AF_LOCAL, SOCK_STREAM, 0 ); /* Create the client's endpoint. */

       bzero( &servaddr, sizeof( servaddr ) ); /* Zero all fields of servaddr. */
       servaddr.sun_family = AF_LOCAL; /* Socket type is local (Unix Domain). */
       strcpy( servaddr.sun_path, UNIXSTR_PATH ); /* Define the name of this socket. */

/* Connect the client's and the server's endpoint. */
       connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

       // while( !feof( stdin ) ) {
       //        send = getchar();
       //        write( sockfd, &send , sizeof( char ) );
       // }
       while(1){char buf[1024];
              read(sockfd, buf, 1024); sleep(1);
       }
       close( sockfd );
}