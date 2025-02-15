#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>




char buffer[1000];

int main()
{
    struct sockaddr_in remote;
    int sock;
    memset(buffer, 'a', sizeof(buffer));
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        return (1);
    remote.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1", &remote.sin_addr);
    remote.sin_port = htons(6969);

    connect(sock, (void *)&remote, sizeof(remote));
    write(sock, buffer, sizeof(buffer));
    close(sock);
    return 0;
}