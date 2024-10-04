#include <stdio.h>        // 提供輸入輸出功能，例如 printf 和 scanf，用於顯示訊息和讀取用戶輸入
#include <stdlib.h>       // 提供一般工具函數，例如內存管理 (malloc, free) 和程序控制 (exit)
#include <string.h>       // 包含字符串操作的函數，例如 memset (初始化內存) 和 strcpy (字符串複製)
#include <arpa/inet.h>    // 包含網路地址轉換函數，例如 inet_addr (將 IPv4 地址轉換為網路字節序) 和 ntohs (將網路字節序轉換為主機字節序)
#include <sys/types.h>    // 定義與網路編程和其他系統調用相關的數據類型，例如 ssize_t 和 sa_family_t
#include <sys/socket.h>   // 提供 socket 的創建、綁定、監聽和接受等函數，並定義 struct sockaddr 和 struct sockaddr_in 等結構
#include <netinet/in.h>   // 定義與網路協定 (如 TCP/IP) 有關的常數和結構，例如 IPPROTO_TCP、SOCK_STREAM 和 sockaddr_in 結構
#include <unistd.h>       // 提供對 POSIX 系統調用的接口，例如 close (關閉 socket) 和 read/write 函數，用於處理文件描述符

int main() {

	//socket的建立
    int sockfd = 0;
    
    /** 
    Prototype : int socket(int domain, int type, int protocol);

    Arguments

    - domain
    定義了socket要在哪個領域溝通，常用的有2種：

    AF_UNIX/AF_LOCAL：用在本機程序與程序間的傳輸，讓兩個程序共享一個檔案系統(file system)
    AF_INET , AF_INET6 ：讓兩台主機透過網路進行資料傳輸，AF_INET使用的是IPv4協定，而AF_INET6則是IPv6協定。
    
    - type
    說明這個socket是傳輸的手段為何：

    SOCK_STREAM：提供一個序列化的連接導向位元流，可以做位元流傳輸。對應的protocol為TCP。
    SOCK_DGRAM：提供的是一個一個的資料包(datagram)，對應的protocol為UDP
    
    - protocol
    設定socket的協定標準，一般來說都會設為0，讓kernel選擇type對應的默認協議。
    */
    sockfd = socket(AF_INET , SOCK_STREAM , 0);

    if (sockfd == -1){
        printf("Fail to create a socket.");
    }
    else{
        printf("Socket created successfully.\n");
    }

    /**
    struct sockaddr_in {
        short            sin_family;   // AF_INET,因為這是IPv4;
        unsigned short   sin_port;     // 儲存port No
        struct in_addr   sin_addr;     // 參見struct in_addr
        char             sin_zero[8];  // Not used, must be zero
    };

    struct in_addr {
        unsigned long s_addr;          // load with inet_pton() => 將整數型態的 ipv4 轉換變成 整數型態
    };
    */

    //socket的連線
    struct sockaddr_in info;
    // 初始化該記憶體 ， 相較於 melloc 是分配記憶體
    memset(&info, 0, sizeof(info));  // 初始化該記憶體為 0
    info.sin_family = PF_INET; // sockaddr_in 為 Ipv4 結構
    info.sin_addr.s_addr = inet_addr("8.8.8.8"); // Ipv4
    info.sin_port = htons(53); // 開啟端口
    
    int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
    if (err == -1) {
        printf("Connection error\n");
    } else {
        printf("Connected successfully\n");
    }
    
    // 關閉 socket
    close(sockfd); // 記得關閉 socket
    return 0;
}
