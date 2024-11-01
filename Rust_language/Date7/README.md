# rust 所有權系統

當談到 Rust 的所有權系統時，以下是一些關鍵概念和範例，以字串為例來解釋這些概念。

### 1. 所有權 (Ownership)

在 Rust 中，所有權是每個值都有一個唯一的所有者。每個值在任何時間點只有一個所有者，當所有者超出範圍時，該值會自動被釋放。

```rust
fn main() {
    let s = String::from("Hello, Rust!"); // s 是所有者
    println!("{}", s);
} // 此時 s 超出範圍，記憶體被釋放
```

### 2. 借用 (Borrowing)

借用允許你使用值而不轉移所有權。這可以是可變借用或不可變借用。

#### 不可變借用

```rust
fn main() {
    let s = String::from("Hello, Rust!");
    let len = calculate_length(&s); // 傳遞的是 s 的引用
    println!("Length of '{}' is {}.", s, len);
}

fn calculate_length(s: &String) -> usize {
    s.len() // 讀取 s 的內容
}
```

#### 可變借用

```rust
fn main() {
    let mut s = String::from("Hello");
    change(&mut s); // 傳遞可變引用
    println!("{}", s);
}

fn change(s: &mut String) {
    s.push_str(", Rust!"); // 修改 s 的內容
}
```

### 3. 所有權轉移 (Move)

當一個變量被賦值給另一個變量時，所有權會轉移。原始變量將無法使用。

```rust
fn main() {
    let s1 = String::from("Hello");
    let s2 = s1; // 所有權轉移到 s2

    // println!("{}", s1); // 這裡會出錯，因為 s1 的所有權已經轉移
    println!("{}", s2);
}
```

### 4. 克隆 (Clone)

如果需要保留原始所有者，可以使用 `clone` 方法來創建一個值的副本。

```rust
fn main() {
    let s1 = String::from("Hello");
    let s2 = s1.clone(); // 克隆 s1，創建一個新值

    println!("{}", s1); // 這裡仍然可以使用 s1
    println!("{}", s2);
}
```

### 5. 生命週期 (Lifetimes)

生命週期是 Rust 中一個進階概念，涉及到引用的有效範圍，確保在使用引用時不會出現懸空引用。

```rust
fn main() {
    let r;
    {
        let s = String::from("Hello");
        r = &s; // s 的生命週期在這裡
    }
    // println!("{}", r); // 這裡會出錯，因為 r 參考的 s 已經超出範圍
}
```

### 總結

Rust 的所有權系統旨在保證內存安全並避免數據競爭。理解所有權、借用、所有權轉移、克隆和生命週期的概念是使用 Rust 的基礎，幫助開發者編寫更安全、高效的程式碼。