#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5090
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // 創建 socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket創建失敗 \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("134.208.49.28");
    serv_addr.sin_port = htons(PORT);

    // 連接伺服器
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("連接失敗");
        return -1;
    }

    printf("已連接到伺服器。\n");

    int flag = 1;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);


        printf("我: ");
        if(flag){
            scanf("%s", buffer);
            flag = 0;
        }
        else{
            scanf(" %s", buffer);
        }

        // 發送訊息
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send failed");
            break;
        }

        // 接收伺服器回覆
        memset(buffer, 0, BUFFER_SIZE);
        int valread = read(sockfd, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            printf("伺服器斷開連接。\n");
            break;
        }


        printf("對方: %s\n", buffer);
    }

    printf("客戶端關閉....\n");

    // 關閉客戶端...
    close(sockfd);


    return 0;
}
