#include "ds_socket.h"


int main(int argc,char *argv[])
{
    int sockfd;
    int newfd;
    struct sockaddr_in  server_addr,client_addr;
    int ret = 1;
    int n = 0;
    int sin_size;
    int pid;

    sockfd = ds_socket(AF_INET,SOCK_STREAM,0);

    ds_sockaddr_in(&server_addr,AF_INET,ds_PORT,INADDR_ANY);

    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&ret,sizeof(int));

    ds_bind(sockfd,(struct sockaddr*)(&server_addr),sizeof(server_addr));

    ds_listen(sockfd,5);

    while(1){
         printf("connect number is %d\n",n++);
         sin_size = sizeof(struct  sockaddr_in);
         newfd = ds_accept(sockfd,(struct sockaddr*)(&client_addr),&sin_size);

         printf("newfd  is successful,");
         fprintf(stderr,"server get connection from %s   %d \n",
                 inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

         char send_buf[] = "you prepare for data now \n";
         if((pid = fork()) == 0){
             char buf[1024] = {0};
             close(sockfd);
             if(write(newfd,send_buf,strlen(send_buf))==-1){
                 fprintf(stderr,"write failed\n");
                 exit(1);
             }//end if
             while((ret=read(newfd,buf,1024))!= -1){
                  if(ret == 0 || ((strcmp(buf,BREAK_CONNECT)== 0))){
                       printf("client close.............\n");
                       break;
                  }//end if
                  printf("server receive: %s\n",buf);
                  memset(buf,0x00,1024);
             }//end while
             close(newfd);
             exit(0);
         }else if(pid < 0){
             fprintf(stderr,"fork error.....................\n");
             close(newfd);
         }

    }//end while

    close(sockfd);


    return 0;
}
