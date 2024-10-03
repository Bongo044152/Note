#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// 创建新节点的静态方法，使用二级指针
Node* create_node(int val, Node* node) {
    node = (Node*)malloc(sizeof(Node)); // 分配内存
    node->val = val;                  // 设置值
    node->next = NULL;                // 初始化指针
    return node;                      // 新的指針回傳
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
    // 接收新的指針
    head = create_node(0, head);

    Node* current = head;

    for (int i = 1; i < 11; i++) {
        // 預先定義
        Node* newNode = NULL;
        // 接收新的指針
        newNode = create_node(i, newNode);
        current->next = newNode;
        current = newNode;
    }

    print_list(head);

    // 釋放內存 (略)

    return 0;
}