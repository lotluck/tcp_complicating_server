#ifndef DS_SOCKET_H
#define DS_SOCKET_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>


#define    ds_PORT        (8888)                    // 我的常用端口
#define    BREAK_CONNECT   "I_LOVE_YOU_I_MISS_YOU"  //定义断开连接的宏定义


//封装 socket
int ds_socket(int domain,int type,int protocol);

//填充struct sockaddr_in 结构体，注意传32位整数ip
void ds_sockaddr_in(struct sockaddr_in *addr,
                    unsigned short sin_family,
                    unsigned short int port,
                    uint32_t ip_addr
                    );

//封装bind，里面还有可以重用处于timewait期间的socket地址
void ds_bind(int sockfd,struct sockaddr *my_addr,int addrlen);

// 封装listen
void ds_listen(int sockfd,int backlog);

// 封装accept
int ds_accept(int sockfd,struct sockaddr *addr,int *addrlen);

//封装connect
void ds_connect(int sockfd,struct sockaddr *addr,int addrlen);

#endif

























