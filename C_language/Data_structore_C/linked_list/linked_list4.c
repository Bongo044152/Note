#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 再次簡化新增資料型態的過程
typedef struct Node {
    int val;
    struct Node* next;
} Node;

void create_node(struct Node** newNode, int val){

    *newNode = (struct Node*)malloc(sizeof(struct Node));

    // <- 你可以在這邊檢查 malloc 是否有成功分配到記憶體

    (*newNode)->val = val;
    (*newNode)->next = NULL;
}

void print(Node* node){
    if(node->next == NULL){
        printf("%d\n", node->val);
        return;
    }

    printf("%d -> ", node->val);
    print(node->next);
}

int main() {
    Node* head = NULL;
    create_node(&head, 0);
    Node* current = head;

    // 建構鏈結串列
    for( int i=0; i<10; i++){
        Node* temp = NULL;
        create_node(&temp, i+1);
        current->next = temp;
        current = current->next;
    }

    // 輸出鏈結串列
    // 方法 1 : 使用 while 迴圈輸出
    current = head;
    printf("使用 while loop 輸出鏈結串列的結果 : ");
    while (current->next != NULL){
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("%d\n", current->val);
    
    // 方法2 : 使用遞迴輸出鏈結串列
    printf("使用 遞迴 輸出鏈結串列的結果 : ");
    print(head);

    // <- 在這個地方記得 free 鏈結串列，你可以自己試著寫寫看，或者參考 "linked_list2.c : 56"

    return 0;
}