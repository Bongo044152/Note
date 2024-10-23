#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define Key_length 10
#define Table_size 15

void get_error_mes(int error_code){
    switch (error_code) {
    case -1:
        printf("錯誤! 字串長度不允許超過%d\n", Key_length);
        break;
    case -2:
        printf("錯誤! 元素已經存在於字典當中!\n");
        break;
    default:
        break;
    }
}

typedef struct Data{
    char* key;
    int val;
} Data;

typedef struct Storage{
    Data* datas;
    int length;
} Storage;

Storage table[Table_size];

void init_table() {
    for (int i = 0; i < Table_size; i++) {
        table[i].datas = NULL;
        table[i].length = 0;
    }
}


int hash(const char* name){
    int length = strlen(name);
    if(length > Key_length){
        return -1;
    }

    unsigned int res = 0;
    for(int i=0; i<length; i++){
        res = (unsigned int)(name)[i] * (i+1) * 1.25 + res;
    }
    return res % Table_size;
}


int add_element(Data* data) {
    int index = hash(data->key);
    if(index < 0){
        get_error_mes(index);
    }

    Storage* current_storage = &table[index];
    for(int i=0; i<current_storage->length; i++){
        if(current_storage->datas[i].key == data->key){
            return -2;
        }
    }
    current_storage->datas = realloc(current_storage->datas, (current_storage->length + 1) * sizeof(Data));

    current_storage->datas[current_storage->length] = *data; // Add new data
    current_storage->length++; // Increase length
    return 0;
}

void print_all() {
    for (int i = 0; i < Table_size; i++) {
        Storage temp = table[i];
        printf("table %d: [ ", i+1);
        for (int j = 0; j < temp.length; j++) {
            printf("(%s => %d) ", temp.datas[j].key, temp.datas[j].val);
        }
        printf("]\n");
    }
}

int gat_value(char* name){
    int index = hash(name);
    Storage temp = table[index];

    // 透過查表來尋找
    for (int i = 0; i < temp.length; i++) {
        if(strcmp(name, temp.datas[i].key) == 0){
            return temp.datas[i].val;
        }
    }
    return -1;
}

int main() {
    init_table();

    char temp[10];
    strcpy(temp, "test");

    for (int i = 0; i < 10; i++) {
        sprintf(temp + strlen(temp), "%d", i + 1);
        Data data = { strdup(temp), i+1 };
        // Data data = { "test", i+1 };
        int error = add_element(&data);
        if(error < 0){
            get_error_mes(error);
        }

        // 重置 temp 為原始字符串
        strcpy(temp, "test");
    }
    
    print_all();

    // 嘗試取得被存入的值
    char* element = "test1";
    int res = gat_value(element);
    if(res >= 0){
        printf("%s 的數值 : %d", element, res);
    }
    else{
        printf("查詢失敗，該元素不存在");
    }

    // Free memory
    for (int i = 0; i < Table_size; i++) {
        free(table[i].datas);
    }

    return 0;
}