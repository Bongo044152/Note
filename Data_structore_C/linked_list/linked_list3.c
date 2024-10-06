#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// 定義節點
struct Node {
    int val;
    struct Node* next;
};

// 新增資料型態
typedef struct Node Node;

// 建立一個小工具，可以幫助我們快速建構 node
// 使用二級指針來訪問並且更改玉更改的值
void create_node(Node** newNode, int val){

    // 動態分配記憶體 : 即表示得到一個指向 鏈結串列的 "頭" 的指針
    *newNode = (Node*)malloc(sizeof(Node));

    // <- 你可以在這邊檢查 malloc 是否有成功分配到記憶體

    (*newNode)->val = val;
    (*newNode)->next = NULL;
}


int main() {
    // 將指針初始化為 NULL 即表示這是一個空指針，理論上避免了訪問該指針所對應的記憶體位置
    Node* head = NULL;

    // 建立 head
    create_node(&head, 0);

    // 輸出結果
    printf("%d\n", head->val);

    return 0;
}