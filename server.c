#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

#define PORT 6969

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in server_addr;
    char buffer[1000000] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket failed\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port=htons(PORT);

    // bind
    if (bind(server_fd, (void *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("binding failed!");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("listening failed!");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("server is listening in port %d....", PORT);



    ssize_t bytes_read;
    int i = 1;
    while(1)
    {
        new_socket = accept(server_fd, NULL, NULL);
        if (new_socket < 0)
        {
         perror("Accept failed");
         close(server_fd);
         exit(EXIT_FAILURE);
        }
        if ((bytes_read = read(new_socket, buffer, sizeof(buffer))) > 0)
        {
            if (bytes_read < 0)
            {
                perror("Read failed");
            }
            else
            {
                buffer[bytes_read] = '\0';
                printf("Received msg number %d :\n%s\n", i, buffer);
            }
        }
        i++;
        close(new_socket);
    }

    close(new_socket);
    close(server_fd);
}
