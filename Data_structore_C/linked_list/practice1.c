// 題目 : 建立一個長度為 10 的鏈結串列，並且移除第五位，使其長度變成9
// 可以詢問 GPT
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}Node;

//十分激烈。
Node *create_Node(int val){
    Node *new_Node = (Node*)malloc(sizeof(Node));
    new_Node->val = val;
    new_Node->next = NULL;
    return new_Node;
}

int main() {
    
    Node *head=create_Node(0);
    Node **current = &head;
    for(int i=1 ; i<10 ; i++){
        (*current)->next = create_Node(i);
        current = &((*current)->next);
    }
    current = &head;
    for(int i=0 ; i<10 ; i++){
        printf("%d ", (*current)->val);
        current = &((*current)->next);
    }


    Node *trash = NULL; //垃圾指針。
    Node **catch = NULL; //銜接指針。

    // 第 6 位
    current = &head;
    for(int i=1 ; i<6 ; i++){
        current = &((*current)->next);
    }
    catch = &((*current));

    // 第 5 位
    current = &head;
    for(int i=1 ; i<5 ; i++){
        current = &((*current)->next);
    }
    trash = &(**current);

    // 第 4 位
    current = &head;
    for(int i=1 ; i<4 ; i++){
        current = &((*current)->next);
    }


    // delete
    (*current)->next = (*catch);
    free(trash);
    trash = NULL;

    printf("\n");
    current = &head;
    for(int i=0 ; i<9 ; i++){
        printf("%d ", (*current)->val);
        current = &((*current)->next);
    }

    return 0;
}