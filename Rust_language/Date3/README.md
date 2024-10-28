# 概要

1. 標準輸入輸出
2. 數字規則
3. 輸入格式轉換

## 1. 標準輸入輸出

### 引入模塊

```rust
use std::io; // 標準輸入輸出模塊
```

### 建立變數存放輸入

```rust
let mut input = String::new();
```

### 讀取輸入

```rust
io::stdin().read_line(&mut input).expect("Failed to read line");
```

在這裡，`.expect` 的作用是當讀取失敗時，會印出錯誤訊息並結束程式。類似於 JavaScript 的 `try-catch` 或 `.catch()`。

### 原理解釋

1. `io::stdin()` 會回傳一個 `Stdin` 物件，代表標準輸入。
2. `read_line(&mut input)` 會讀取一行輸入，並將其存放在 `input` 變數中。
3. `&mut input` 是一個可變引用，讓 `read_line` 函數可以修改 `input` 變數的值。

在這裡，你需要將 `input` 變數標記為 `mut`，表示在作用域內這個變數是可變的，否則會出現錯誤。

## 2. 數字規則

### 數字型態示例

```rust
let x: i8 = 5; // 有符號 8 位整數
let y: u8 = 10; // 無符號 8 位整數
// let z: u8 = x + y; // 會出錯，因為 x 是 i8，y 是 u8
let z: u8 = x as u8 + y; // 使用 as 來轉換數字型態
```

- Rust 嚴格要求數字型態的匹配，如果要進行不同類型的運算，需要使用 `as` 來進行顯式轉換。

### 數字格式化

```rust
let large_number = 127_000; // 使用下劃線來提高可讀性
```

- 使用下劃線來分隔數字，使其更易於閱讀，這是 rust 的特性 !

### 整數最大值

```rust
let _i32max = i32::MAX; // 取得 i32 的最大值
```

### 整數的不同寫法

以下寫法皆為相同：

```rust
let _x = 5_i8;      // 帶有類型的數字
let _x = 5i8;       // 類型在數字後
let _x = 5 as i8;   // 類型轉換
let _x = 5_i32 as i8; // 從 i32 轉換為 i8
let _x: i8 = 5;     // 明確指定類型
```

## 3. 輸入格式轉換

### 讀取並轉換輸入

```rust
let mut user_input = String::new();
io::stdin().read_line(&mut user_input).expect("Failed to read line");
let user_input = user_input.trim(); // 去掉換行符與空白符號
let user_input: i32 = user_input.parse().unwrap(); // 將字串轉換成整數
```

- `trim()` 方法用於去掉字串前後的空白和換行符。
- `parse()` 方法用來將字串轉換為整數，並使用 `unwrap()` 提取值。如果轉換失敗，將導致程式崩潰。

有關於 `unwrap()` 後續會在進行更詳細的介紹。

### 計算結果並輸出

```rust
let result = user_input * 2; // 將輸入的數字乘以 2
println!("The result is: {}", result); // 輸出結果
```