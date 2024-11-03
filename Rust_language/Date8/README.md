# 概要

1. 結構體 struct
2. 物件導向編程 OOP -> by using impl

## 1. 結構體

[**官方書籍:**](https://doc.rust-lang.org/book/ch05-01-defining-structs.html#defining-and-instantiating-structs)
> **Structs are similar to tuples, discussed in “The Tuple Type” section, in that both hold multiple related values. Like tuples, the pieces of a struct can be different types. Unlike with tuples, in a struct you’ll name each piece of data so it’s clear what the values mean. Adding these names means that structs are more flexible than tuples: you don’t have to rely on the order of the data to specify or access the values of an instance.**

在這邊，除了要遵循 rust 的規則之外基本上與 C語言 無異

C語言 代碼:
```c
typedef struct Node {
    int val;
    struct Node* next
} Node;

Node* create_node(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->val = val;
    temp->next = NULL;

    return temp;
}

int main() {

    Node* head = create_node(1);
    printf("%d\n", head->val); // 需要解引用

    return 0;
}
```
Rust 代碼:
```rs
struct Node {
    val: i32,
    next: Option<Box<Node>>, // 使用 Option 來處理可能為空的指針
}

fn main() {
    let head = Node {
        val: 1,
        next: None,
    };

    println!("head value: {}", head.val);
}
```
對! 長很像! 但我也不知道 rust 想表達什麼 ...

總而言之，用法上與 C語言 差不多，但是在某些部分提供了更多的功能，例如感覺是從 js/javascript 偷來的用法:

Rust 代碼:
```rs
let _user3 = User {
    email: String::from("s3312543@gmail.com"),
    .._user2
};
```
js 代碼:
```js
let Jackson = {
    ...Allen,
    name: "Jackson"
};
```

又或者是這種令法:
```rs
struct Color(u8, u8, u8);
```

## 2. 物件導向 OOP

如果你對於物件導向有概念，會知道它被區分為 "實例（Instance）"、"類別（Class）"，並且每個物件與類別都有自己的 "屬性" 、 "方法" 。

[**出自維基百科:**](https://zh-yue.wikipedia.org/wiki/%E7%89%A9%E4%BB%B6%E5%B0%8E%E5%90%91%E7%B7%A8%E7%A8%8B)

![img](https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/CPT-OOP-objects_and_classes_-_attmeth.svg/langyue-300px-CPT-OOP-objects_and_classes_-_attmeth.svg.png)

[**官方文件介紹:**](https://doc.rust-lang.org/book/ch05-03-method-syntax.html#method-syntax)
> **Methods are similar to functions: we declare them with the fn keyword and a name, they can have parameters and a return value, and they contain some code that’s run when the method is called from somewhere else. Unlike functions, methods are defined within the context of a struct (or an enum or a trait object, which we cover in Chapter 6 and Chapter 17, respectively), and their first parameter is always self, which represents the instance of the struct the method is being called on.**

```rs
struct Triangle(u16, u16, u16); // 定義屬性
impl Triangle {                 // 定義方法 -> implement
    fn is_right_triangle(&self) -> bool {
        let Triangle(a, b, c) = self;

        let mut arr = [a, b, c];

        // simple bubble sort
        for i in 1..arr.len() {
            if arr[i-1] > arr[i] {
                let temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
            }
        }

        arr[0].pow(2) + arr[1].pow(2) == arr[2].pow(2)
    }
}
```

透過這種方式大致的實現了物件導向，詳細還要在等我深入學習。