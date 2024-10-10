#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct Node {
    int val;
    struct Node* next;
};

// 建立一個小工具，可以幫助我們快速建構 node
struct Node* create_node(int val){

    // 動態分配記憶體 : 即表示得到一個指向 鏈結串列的 "頭" 的指針
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    // <- 你可以在這邊檢查 malloc 是否有成功分配到記憶體

    new_node->val = val;
    new_node->next = NULL;
    return new_node; // 返回一個指針
}


int main() {

    struct Node* head = create_node(0);
    // 建立一個變數，用來追蹤鏈結串列的值的所在位置
    struct Node* current = head;

    // 使用 for 迴圈建構鏈結串列
    for( int i=0; i<10; i++){
        // 建立一個新的節點
        struct Node* temp = create_node(i+1);
        // 當前節點需要指向新的節點
        current->next = temp;
        // 當前的節點需要移動到下一個節點作為更新
        current = current->next;
    }

    current = head;
    for(int i=0 ; i<11 ; i++){
        printf("%d ", current->val);
        current = current->next;
    }

    // 使用 while 迴圈來刪除鏈結串列
    current = head;
    // 當 current == NULL 時，即表示鏈結串列已經達到尾巴的後面 (即表示 NULL)
    // 你也可以寫成 current->next != NULL
    while(current != NULL){
        // 暫存下一個節點的指針位置
        struct Node* temp = current->next;
        // 釋放當前節點所被分配的空間
        free(current);
        // 前往下一個節點
        current = temp;
    }

    return 0;
}