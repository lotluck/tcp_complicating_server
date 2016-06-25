#include "ds_socket.h"

//封装 socket
int ds_socket(int domain,int type,int protocol)
{
    int sockfd;
    sockfd = socket(domain,type,protocol);
    if(sockfd == -1){
       fprintf(stderr,"sockfd create failed....................\n");
       exit(1);
    }
    return sockfd;
}

//填充struct sockaddr_in 结构体，注意传32位整数ip
void ds_sockaddr_in(struct sockaddr_in *addr,
                    unsigned short sin_family,
                    unsigned short int port,
                    uint32_t ip_addr
                    )
{
    addr->sin_family = sin_family;
    addr->sin_port = htons(port);
    addr->sin_addr.s_addr = htonl(ip_addr);

}

//封装bind，里面还有可以重用处于timewait期间的socket地址
void ds_bind(int sockfd,struct sockaddr *my_addr,int addrlen)
{
    int ret = -1;
    int opt = 1;

    setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(int));
    ret = bind(sockfd,my_addr,addrlen);
    if(ret == -1){
        fprintf(stderr,"bind failed...........................\n");
        exit(1);
    }
}

// 封装listen
void ds_listen(int sockfd,int backlog)
{
    int ret;
    ret = listen(sockfd,backlog);
    if(ret == -1){
        fprintf(stderr,"listen error.............................");
        exit(1);
    }
}

// 封装accept
int ds_accept(int sockfd,struct sockaddr *addr,int *addrlen)
{
    int newfd;
    newfd = accept(sockfd,addr,addrlen);
    if((newfd < 0)&&(errno == EINTR)){
        fprintf(stderr,"accept EINTR..........................\n");
        exit(1);
    }else if(newfd < 0){
        fprintf(stderr,"accept error:.......%s\n",strerror(errno));
        exit(1);
    }
    return newfd;
}
//封装connect
void ds_connect(int sockfd,struct sockaddr *addr,int addrlen)
{
     int ret;
     ret = connect(sockfd,addr,addrlen);
     if(ret == -1){
          fprintf(stderr,"connect error........................\n");
          exit(1);
     }
}
