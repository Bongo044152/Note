#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h> // 建立 socket

#include <netinet/in.h>

#include <unistd.h> // 用來 close socket

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
    esle{
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
    memset(&info,sizeof(info));
    info.sin_family = PF_INET;
    info.sin_addr.s_addr = inet_addr("127.0.0.1");
    info.sin_port = htons(8080);
    
    int err = connect(sockfd,(struct sockaddr *)&info,sizeof(info));
    if(err==-1){
        printf("Connection error");
    }
    
    return 0;
}
