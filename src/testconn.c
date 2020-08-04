#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <netdb.h>
#include <getopt.h>
#include <linux/netfilter.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    int ret;
    unsigned short port;
    struct sockaddr_in6 r_servaddr;
    
    struct in6_addr addr;
    inet_pton(AF_INET6, "2001:2000::2", &addr);

    memset(&r_servaddr, 0, sizeof(r_servaddr));
    r_servaddr.sin6_family = AF_INET6;
    //r_servaddr.sin6_addr =  addr;
    inet_pton(AF_INET6, "2001:2000::2", &r_servaddr.sin6_addr);
    port = 5001;
    r_servaddr.sin6_port = htons(port);

    

    ret = socket(AF_INET6, SOCK_STREAM, 0);
        if (ret < 0) {
            printf("Failed to create socket! [%s:%d]",
                        strerror(errno), errno);
            return 0;
        }

    ret = connect(ret, (struct sockaddr *)&r_servaddr,
                      sizeof(struct sockaddr));
        if ((ret < 0) ){
            printf("Failed to connect! [%s:%d]",
                        strerror(errno), errno);
            return 0;
        }

    printf("exit...");
    return 0;

}

