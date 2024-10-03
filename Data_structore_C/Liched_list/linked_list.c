#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 定義節點
typedef struct Node {
    int val;           // 存放資料
    struct Node* next;  // 存放下一位的記憶體，必須使用記憶體位置是因為編譯器無法確定這個結構的大小，避免造成無限相套
} Node;

// 模擬 class 資料型態
typedef struct LinkedList{
    Node* head;
    void (*print)(struct LinkedList*); // 返回的資料型態 (解引用print的記憶體位置)(欲傳入的資料型態)
} LinkedList;

Node* creat_node(int val){
    // 動態分配記憶體位置，記憶體就不會自動被釋放，因此只要指針存在就可以訪問
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode -> val = val;
    NewNode -> next = NULL;
    return NewNode;
}
// 遞迴撰寫
void print(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// 模擬建構子
LinkedList creat_LinkedList(Node* head){
    // 突然想用動態宣告
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list -> head = head;
    list -> print = print;
    return *list;
}

// 記憶體釋放工具
void freeLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // 初始化頭部
    Node* head = creat_node(0);
    Node* current = head;
    for (int i = 1; i < 11; i++){
        current -> next = creat_node(i);
        current = current -> next;
    }

    // 靜態宣告
    LinkedList list =  creat_LinkedList(head);
    list.print(&list);

    // 模擬不雅觀的釋放 -> 以後一律由指針撰寫C語言，是良好的撰寫策略 (此時你的編譯器可能會跳出警告，因為你在試圖釋放一個被靜態定義的內存)
    // free(&list);


    return 0;
}