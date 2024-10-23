/**
 * 【 稍微進階一點的基礎練習 】
 * 
 * 鏈結串列樣式範例 : 
 * 
 * a -> b -> c
 *              -> 4 -> 5 -> 6 -> 7
 *      A -> B
 * 
 * 1. 創建該類型的鏈結串列
 *      - a -> b -> c -> .... 的長度為 l1
 *      - A -> B -> ..... 的長度為 l2
 *      - 4 -> 5 -> 6 -> .... 的長度為 l3
 * 
 * 2. 創建完成過後，試著思考一下給定兩個頭部
 * 
 *  head1 = a -> b -> ...
 *  head2 = A -> B -> C -> ...
 * 
 * 如果兩者有相遇，返回該點
 * 如果兩者沒有相遇，返回 -1
 */


// 節點定義
typedef struct Node{
    int val;
    struct Node* next;
} Node;

// 第一題作答區

// 回傳的格式
typedef struct Cross_list{
    Node* head1;
    Node* head2;
} Cross_list;

Cross_list* creat_cross_linked_list(int l1, int l2, int l3){

    // 第一大題程式撰寫區
}

// 執行區域，自行驗證有無錯誤
int main(){


    return 0;
}


// 第二大題作答區 : 前往 leetcode 吧! -> https://leetcode.com/problems/intersection-of-two-linked-lists/description/