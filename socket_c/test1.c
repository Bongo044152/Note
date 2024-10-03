#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h> // 建立 socket

#include <netinet/in.h>

#include <unistd.h> // 用來 close socket

int main() {
    int sockfd = 0;
    sockfd = socket(AF_INET , SOCK_STREAM , 0);

    if (sockfd == -1){
        printf("Fail to create a socket.");
        return 1; // 返回非零值表示錯誤
    }

    printf("Socket created successfully.\n");

    // 關閉 socket
    close(sockfd);

    return 0;
}
