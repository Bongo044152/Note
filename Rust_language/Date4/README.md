# 概要

1. rust 的函式
2. rust 的條件判斷
3. rust 區塊表達式

## 1. rust 的函式

### 1. 宣告方式/格式
```rs
fn 函示名稱(參數: 型別) -> 回傳值型別 {
    // 函示內容
}
```


### 2. 宣告並且呼叫函式
```rs
fn hello1() {
    println!("hello");
}

fn main() {
    hello1();
    hello2();
}

fn hello2() {
    println!("hello2");
}
```
**rust 並不在乎你的函示在哪裡，只要讀的到就好了**
### 3. 參數傳遞

```rs
fn test(a: i8){
    println!("get a value = {}", a);
}
```

### 4. 函式迴傳值

```rs
// 形式一
fn function_return1() -> i32 {
    5 // 並沒有 ";" 
}

// 形式二
fn function_return2() -> i32 {
    return 5;
}
```

### 5. 結合上述資訊，一個極為簡單的範例
```rs
fn add(a: i32, b: i32) -> i32 {
    a + b
}
```

### 6. 函式相套
```rs
fn my_fn() {
    fn inner_fn() {
        println!("幹你 ..... ");
    }

    inner_fn(); // 這裡呼叫 inner_fn
}
```

## 2. rust 的條件判斷
```rs
fn condition() {
    let food = "tricolor beans";

    // 當你括弧用習慣之後，突然跟你說不用括弧，你會不會超不習慣的？
    if food == "cookie" {
        println!("yummy");
    } else if food == "tricolor beans" {
        println!("yuck!");
    } else {
        println!("where is my cookie?");
    }
}
```

## 3. rust 區塊表達式
```rs
fn expression() {

    let condition = true;
    let y = {
        let x = 3;
        if condition {
            x + 1
        } else {
            x - 1
        }
    };

    println!("The value of y is: {}", y);
}
```
