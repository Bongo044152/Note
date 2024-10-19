#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

#define TABLE_SIZE 10
#define VAL_LEN 25

typedef struct Storage{
    int val;
    char* key;
    struct Storage* next;
} Storage;

// 自動初始化
Storage* table[TABLE_SIZE];

int hash(char* key) {
    int str_len = strlen(key);

    int res = 0;
    for(int i=0; i<str_len; i++){
        res += key[i]*key[i]*0.8+7;
    }
    return res % TABLE_SIZE;
}

int add_element(char* key, int val) {
    int index = hash(key);

    Storage* head = table[index];
    Storage* current = head;

    if(head == NULL){
        head = (Storage*)calloc(1, sizeof(Storage));
        if(head == NULL){
            perror("記憶體分配錯誤!");
            return -1;
        }
        head->key = strdup(key); // 建議深拷貝 key
        head->val = val;
        head->next = NULL;
        table[index] = head; // 更新表頭
        return 0;
    }

    while(current->next != NULL){
        // 如果已經存在
        if(strcmp(current->key, key) == 0){
            current->val = val;
            return 0;
        }

        current = current->next;
    }

    // 如果已經存在於最後一位
    if(strcmp(current->key, key) == 0){
        current->val = val;
        return 0;
    }

    // 創建新的節點
    Storage* new_node = (Storage*)calloc(1, sizeof(Storage));
    if (new_node == NULL) {
        perror("記憶體分配錯誤!");
        return -1;
    }
    new_node->key = strdup(key); // 建議深拷貝 key
    new_node->val = val;
    new_node->next = NULL;

    // 將新節點添加到鏈表末尾
    current->next = new_node;
    return 0;
}

int delete_tiem(char* key) {
    int index = hash(key);

    Storage* head = table[index];
    if(head == NULL){
        printf("元素並沒有被添加過");
        return -1;
    }
    Storage* current = head;
    Storage* prev = NULL;
    while(current != NULL){
        if(strcmp(current->key, key) == 0){
            Storage* nextStorage = current->next;
            free(current->key);
            free(current);
            current = NULL; // 避免懸浮的空指針
            if(prev == NULL){
                table[index] = nextStorage;
            }
            else{
                prev->next = nextStorage;
            }
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return -1;
}

void get_HashTable(){
    for(int i=0; i<TABLE_SIZE; i++){
        Storage* temp = table[i];
        printf("第 %2d 格儲存格: [ ", i);
        while(temp != NULL){
            printf("(%s, %d) ", temp->key, temp->val);
            temp = temp->next;
        }
        printf("]\n");
    }

    printf("======================================\n");
}

void free_HashTable(){
    for(int i=0; i<TABLE_SIZE; i++){
        Storage* current = table[i];
        while(current != NULL){
            Storage* temp = current;
            current = current->next;

            // 釋放深拷貝的內存
            free(temp->key);
            free(temp);
        }
    }
}

int main() {
    
    add_element("justin", 8);
    get_HashTable();
    add_element("justin", 18);
    add_element("ORRRRRR!", 11);
    add_element("a", 11);
    add_element("b", 11);
    add_element("c", 11);
    add_element("d", 11);
    add_element("e", 11);
    add_element("f", 11);
    add_element("g", 11);
    add_element("h", 11);
    get_HashTable();
    delete_tiem("c");
    get_HashTable();

    free_HashTable();


    return 0;
}