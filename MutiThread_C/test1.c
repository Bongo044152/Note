#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int get_sum(int a, int sum) {
    if (a == 0)
        return sum;
    return get_sum(a - 1, sum + a); // 確保返回值
}

void* test(void* num) {
    int* temp = (int*)num;
    *temp = get_sum(*temp, 0); // 計算從 1 到 *temp 的總和
    return NULL;
}

int main() {
    pthread_t thread1;
    int value1 = 100; // 需要計算的值

    // 創建線程，傳遞參數
    if (pthread_create(&thread1, NULL, test, (void*)&value1) != 0) {
        perror("錯誤!");
        return 1;
    }

    printf("我是主線程 !!\n");

    // 等待線程結束
    if (pthread_join(thread1, NULL) != 0) {
        perror("Failed to join thread");
        return 1;
    }
    else{
        printf(("線程已經合併了唷!\n"));
    }

    printf("總和: %d\n", value1); // 輸出結果


    return 0;
}