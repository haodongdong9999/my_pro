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
    int rec_len;
    int send_len;
    struct sockaddr_in my_addr;
    struct sockaddr_in my_client_addr;
    char receive_str[STR_LEN];
    char send_str[STR_LEN];
    memset(&my_addr,0,sizeof(my_addr));
    if((client_sockid = socket(AF_INET,SOCK_STREAM,0)) < 0 )
    {
        printf("socket create fail\n");
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    my_addr.sin_port = htons(MY_PORT);    

    if( ( connect(client_sockid,(struct sockaddr *)& my_addr,sizeof(struct sockaddr)) ) < 0 )
    {
        printf("connect is fail\n");
        return 0;
    }
    rec_len = recv(client_sockid,receive_str,STR_LEN,0);
            receive_str[rec_len] = '\0' ;
    printf("RECV : %s\n",receive_str);
    while(1)
    {
       printf("Please input what are you want to send:\n");
       scanf("%s",send_str);
       if(!(strcmp(send_str,"fuck")))
        {
            printf("Oh,My God,It's time to say byebye now\n");
            break;
        }
       printf("will send %s strs ...\n",send_str);
       send_len = send(client_sockid,send_str,strlen(send_str),0);
       printf("send %d strs ...\n",send_len);
       rec_len = recv(client_sockid,receive_str,40,0);
       receive_str[rec_len] = '\0';
       printf("SO HAPPY,WE RECV %d STRS is :%s\n",rec_len,receive_str);
    }
    close(client_sockid);
    return 0;
    
}
