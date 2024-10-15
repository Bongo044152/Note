#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 5090
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    char buffer[BUFFER_SIZE] = {0}; // 將第一位設為 '\0'

    // 創建 socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 綁定 socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // 監聽
    if (listen(server_fd, 1) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("伺服器正在運行，等待連接...\n");

    int addlen = sizeof(address);
    // 接受連接 -> 它會阻塞，直到有客戶端連接請求。這意味著伺服器會暫停執行，直到一個客戶端成功連接
    // 並且將數值傳遞到 new_socket
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("客戶端已連接。\n");

    int flag = 1;

    while (1) {
        // 清空緩衝區
        memset(buffer, 0, BUFFER_SIZE);

        // 讀取訊息
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) {
            printf("客戶端斷開連接。\n");
            break;
        }

        printf("對方: %s\n", buffer);

        printf("我: ");
        if(flag){
            scanf("%s", buffer);
            flag = 0;
        }
        else{
            scanf(" %s", buffer);
        }

        if (send(new_socket, buffer, strlen(buffer), 0) < 0) {
            perror("send failed");
            break;
        }
    }

    printf("伺服器關閉....\n");

    // 正在連接的 socket -> 由 accept 創建，類似一個站存區，專門用來儲存 當前交流對象的對話
    close(new_socket);
    // 伺服器用來監聽的 socket
    close(server_fd);


    return 0;
}
