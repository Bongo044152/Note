# 概要

1. loop
2. while loop
3. for loop

## 1. `loop`

`loop` 是一種無限循環的結構，一直到 `break` 才會結束循環。

### 基本語法

```rust
loop {
    // 你要執行的程式碼
}
```

## 2. `while loop`

rust 並不提供 `do..while..` 的語法，其他也沒什麼特別的

### 基本語法

```rust
while condition {
    // 你要執行的程式碼
}
```

**注意! rust 並不提供 `do..while..` 的語法**

## 3. `for loop`

`for loop` 的語法與 python 類似，但是細節上又有所不同

### 基本語法

```rust
for variable in collection {
    // 你要執行的程式碼
}
```