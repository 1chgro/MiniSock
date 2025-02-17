#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

char *copystr(char *s1)
{
    char *s2;
    int i = 0;

    s2 = malloc(strlen(s1) + 1);
    while(s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}


int main(int ac, char **av)
{
    struct sockaddr_in remote;
    int sock;

    if (ac == 1)
    {
        perror("Usage: ./client <message>");
        exit(EXIT_FAILURE);
    }
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        return (1);
    remote.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1", &remote.sin_addr);
    remote.sin_port = htons(6969);

    char *buff;
    buff = copystr(av[1]);
    connect(sock, (struct sockaddr *)&remote, sizeof(remote));
    write(sock, buff, strlen(av[1]));
    free(buff);
    close(sock);
    return 0;
}