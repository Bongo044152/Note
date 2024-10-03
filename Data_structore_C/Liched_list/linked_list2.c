#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// 创建新节点的静态方法，使用二级指针
void create_node(int val, Node** newNode) {
    *newNode = (Node*)malloc(sizeof(Node)); // 分配内存
    (*newNode)->val = val;                  // 设置值
    (*newNode)->next = NULL;                // 初始化指针
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
}

int main() {
    // 預先定義
    Node* head = NULL;
    // 對指針進行修改新的分配，即表示透過高級的指針指向新的指針，這樣才可以傳遞指針
    create_node(0, &head);

    Node* current = head;

    for (int i = 1; i < 11; i++) {
        // 預先定義
        Node* newNode = NULL;
        // 對指針進行修改新的分配，即表示透過高級的指針指向新的指針，這樣才可以傳遞指針
        create_node(i, &newNode);
        current->next = newNode;
        current = newNode;
    }

    print_list(head);

    // 釋放內存 (略)

    return 0;
}