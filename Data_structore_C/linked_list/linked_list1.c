#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 定義一個節點 ( 鏈結串列的點 ) ， 使用結構體的架構撰寫 ( 因為 list 會強迫放同一種資料型態，因此使用 "結構體" 會是一種比較好的實踐方式 )
struct Node {
    int val;
    // 標記下一位記憶體位置，至於為什麼不可以直接寫 "Node* next"
    // 那是因為結構體尚未被定義完成，因此需要先使用 struct 聲明這是結構體本身或一部分 <- 我的理解
    struct Node* next;
};


int main() {
    // 宣告節點
    struct Node head;
    int a = 8;
    int* p1 = &a;
    char b = 'A';
    char* p2 = &b;

    printf("..%d\n", sizeof(struct Node));
    printf("..%d\n", sizeof(p1));
    printf("..%d\n", sizeof(p2));
    // 初始化 head 的 val 值
    head.val = 8;
    
    // 宣告第一個點
    struct Node node1;
    // 初始化 node1 的 vla 值
    node1.val = 9;

    // 設定 head 的下一個值 (即指向下一個串列)
    head.next = &node1;

    // 賦值並且輸出
    int head_val = head.val;
    int node1_val = node1.val;

    printf("head 的值 : %d\n", head_val);
    printf("node1 的值 : %d\n", node1_val);

    // 取 head 的節點的下一位 ( 得到指針 )
    // 之後將其解引用後，得到 .val 值
    node1_val = (*head.next).val;
    printf("head 的 next 的值 ( 即表示 node1 的值 ) : %d\n", node1_val);
    
    return 0;
}