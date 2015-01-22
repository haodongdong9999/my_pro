#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>  
#include<sys/socket.h>  
#include<netinet/in.h>  

#define IP_FMT	"%d.%d.%d.%d"
#define IP_ARG(x) ((unsigned char *)(x))[0], ((unsigned char *)(x))[1], ((unsigned char *)(x))[2], ((unsigned char *)(x))[3]
#define MY_PORT 9001
#define STR_LEN 90
void my_inet_addr(char *pcStr, unsigned int *IpAddr)
{
    unsigned char ulDstIp[4]={0};
    char ucaTmpStr[32] = "127.0.0.1";
    printf("%s \n",pcStr);
    sscanf(ucaTmpStr,"%d.%d.%d.%d",&ulDstIp[0],&ulDstIp[1],&ulDstIp[2],&ulDstIp[3]);
    printf("%s dst ip is :"IP_FMT"\n",__FUNCTION__,IP_ARG(ulDstIp));
    printf("%d %d %d %d\n",ulDstIp[0],ulDstIp[1],ulDstIp[2],ulDstIp[3]);
    memcpy(IpAddr,ulDstIp,4);
}

int main()
{

    int sock_id;
    int client_sockid;
    int addr_len;
    int send_len;
    struct sockaddr_in my_addr;
    struct sockaddr_in my_client_addr;
    char caSend_str[STR_LEN];
    char recv_str[STR_LEN];
    memset(&my_addr,0,sizeof(my_addr));
    if((sock_id = socket(AF_INET,SOCK_STREAM,0)) < 0 )
    {
        printf("socket create fail\n");
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    my_addr.sin_port = htons(MY_PORT);

    if((bind(sock_id,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))) < 0)
    {
        printf("bind fail\n");
        return 0;
    }

    listen(sock_id,20);

    addr_len = sizeof(struct sockaddr_in);
    printf("WAITING ...\n");
    client_sockid = accept(sock_id,(struct sockaddr *)&my_client_addr,&addr_len);
    if( client_sockid < 0 )
    {
        printf("accept fail\n");
        return 0;
    }
    printf("The client IP : %s\n",inet_ntoa(my_client_addr.sin_addr));
    send_len = send(client_sockid,"I'M WAITING FOR YOU ...\n",20,0);
    if( send_len < 0 )
    {
        printf("send fail\n");
        return 0;
    }
    while( (send_len = recv(client_sockid,recv_str,STR_LEN,0)) > 0 )
    {
        recv_str[send_len] = '\0';
        printf("I'M so Glad receive %d strs is :%s\n",send_len,recv_str);
        send_len = send(client_sockid,"I'M ALREADAY RECV OVER,THANK YOU\n",40,0);
        printf("Send %d strs \n",send_len);
    }
    close(client_sockid);
    close(sock_id);
    printf("Thank you ,bye!\n");
    return 0;
}

