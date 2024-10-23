#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main() {
    // 聲明函數指針
    int (*funcPtr)(int, int);

    // 將函數地址賦值給指針
    funcPtr = add;

    // 使用函數指針調用函數
    int result = funcPtr(3, 4); // 相當於 add(3, 4)

    printf("Result: %d\n", result); // 輸出結果
    return 0;
}
