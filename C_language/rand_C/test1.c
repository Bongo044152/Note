// 擲骰子遊戲 (由隨機樹決定骰子的點數)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

int main() {

    // 注意! rand() 使用固定的種子數產稱，因此如果要實現更加線時的隨機，建議使用 srand
    // srand(time(NULL));

    int table[6] = {0};
    for(int i=0; i<100; i++){
        int dice = rand()%6+1;
        table[dice-1] += 1;
    }

    for(int i=0; i<6; i++){
        printf("點數%d 出現了 %d次\n", i+1, table[i]);
    }

    return 0;
}