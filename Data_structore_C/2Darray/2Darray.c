#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void malloc_array(int*** array, int m, int n){
    // 對 array 外層進行分配
    (*array) = (int**)malloc(sizeof(int*)*m);
    // 對 array 內層進行分配
    for(int i=0; i<n; i++){
        (*array)[i] = (int*)malloc(sizeof(int)*n); // 對每個內圈進行分配
    }
}

int main() {
    int m=3, n=4;
    int** array = NULL;
    malloc_array(&array, m, n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%p ", &(array[i][j]));
        }
        printf("\n");
    }

    // 釋放內存 - 略
    
    return 0;
}