#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    // Connect to the server and read the response
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr = {0};

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(4242);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    char buffer[4096] = {0};
    size_t read_size = 0;

    while (read_size = read(sockfd, buffer, 4096) > 0) {
        printf("%ld> %s", read_size, buffer);
        if (strcmp(buffer, "WELCOME\n") == 0)
            write(sockfd, "GRAPHIC\n", 8);
        memset(buffer, 0, 4096);
    }
    return 0;
}