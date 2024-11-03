# rust 所有權系統

- 本篇文章以字串為例來解釋 ( 官方文件也是 )

## 概要

1. 所有權 ( Ownership )
2. 借用 ( Borrowing )
3. 所有權轉移 ( Move )
4. 克隆 ( Clone )
5. 生命週期 ( Lifetimes )

## 前言

如果你們對於所有權怎麼來的，可以參考 [**Rust 所有权**](https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html) ，這本書會讓你對於所有權有更深的了解。

在提到所有權之前，讓我們先聊一下以下幾點:

1. **垃圾回收 (Garbage Collection)**
2. **手動管理 ( C/C++ 的 free )**

### **1. 垃圾回收**

垃圾回收是一種自動管理記憶體的方法，當一個物件沒有被引用時，程式會藉助垃圾回收演算法向作業系統歸還這部分主記憶體空間。

**好處:**
> **自動的垃圾回收可以讓程式員不需要考慮太多動態記憶體釋放、管理問題，這樣可以減少了內存洩漏、詭異的錯誤導致系統崩潰等問題。**

**壞處:**
> **相對手動釋放 ( malloc() + free() )，垃圾回收器效率較低，需要額外的空間進行標記，拖慢了程序的速度。**

**流程:**
1. 考慮某個物件在未來的程式執行中，將不會被存取。
2. 回收這些物件所占用的記憶體。

**使用語言:**
- Java
- Python
- JavaScript
- ...

參考資料:
- [**垃圾回收(電腦科學) - 維基百科**](https://zh.wikipedia.org/zh-tw/%E5%9E%83%E5%9C%BE%E5%9B%9E%E6%94%B6_(%E8%A8%88%E7%AE%97%E6%A9%9F%E7%A7%91%E5%AD%B8))
- [**Days 11: 什麼是垃圾回收器？ - iT 邦幫忙**](https://ithelp.ithome.com.tw/m/articles/10204860)

### **2. 手動管理**

手動記憶體管理顧名思義必須手動的、明確地分配和釋放記憶體，如 C 語言中的 `malloc()` 和 `free()`。

**好處:**
> - **效率高**：程式員可以根據需要精確控制記憶體的分配和釋放，能夠優化性能。
> - **靈活性**：允許開發者根據應用需求進行定制，適合需要高性能的系統。

**壞處:**
> - **容易出錯**：不正確的記憶體管理可能導致內存洩漏、重複釋放等錯誤，進而引起程序崩潰或不穩定。
> - **維護成本高**：需要開發者持續關注記憶體的使用情況，增加了維護的複雜性。

**流程:**
1. 當需要使用記憶體時，使用 `malloc()` 或類似函數分配所需的空間。
2. 使用完畢後，必須調用 `free()` 來釋放不再需要的記憶體。

**使用語言:**
- C
- C++
- ...

## rust 所有權簡介

[**引用自官方書籍:**](https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html#what-is-ownership)
> <b>Ownership is a set of rules that govern how a Rust program manages memory. All programs have to manage the way they use a computer’s memory while running. Some languages have garbage collection that regularly looks for no-longer-used memory as the program runs; in other languages, the programmer must explicitly allocate and free the memory. Rust uses a third approach: memory is managed through a system of ownership with a set of rules that the compiler checks. If any of the rules are violated, the program won’t compile. None of the features of ownership will slow down your program while it’s running.<br><br>
Because ownership is a new concept for many programmers, it does take some time to get used to. The good news is that the more experienced you become with Rust and the rules of the ownership system, the easier you’ll find it to naturally develop code that is safe and efficient. Keep at it!</b>

Rust 所有權介於兩者之間 ( 垃圾回收、手動管理 )，感覺起來像是透過 "作用域" 確保具有該內存的指標變數可以與該資料的生命週期一致。 -> 用 C語言 的概念來說就是一起回收變數與資料，就沒有懸浮指針的問題

開發過程中，需要明確的說明所有權的轉移，達到記憶體管理的目的。 ( 這也是為什麼我認為是半手動半自動的原因 )

<style>
.highlight {
    background-color: yellow;
}
</style>
<b><font color="red" class="highlight">在開始第一點之前，官方文件建議你先了解 "stack and heap" 的概念，而我認為，你還需要了解
"C語言的指針" 與 "動態分配記憶體" ，之後參考: [**官方書籍 4-1 Memory and Allocation**](https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html#memory-and-allocation) 你會有比較完整的概念。</font></b>

## 1. 所有權 (Ownership)

在 Rust 中，所有權是每個值都有一個唯一的所有者。每個值在任何時間點只有一個所有者，當所有者超出範圍時，該值會自動被釋放。

```rust
fn main() {
    let s = String::from("Hello, Rust!"); // s 是所有者
    println!("{}", s);
} // 此時 s 超出範圍，記憶體被釋放
```

## 2. 借用 (Borrowing)

借用允許你使用而不轉移所有權。這可以是可變借用或不可變借用。

在理解借用之前，我希望你可以明白那些資料屬於 `Copy trait` 那些不是。

[**官方書籍:**](https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html#stack-only-data-copy)
- All the integer types, such as u32.
- The Boolean type, bool, with values true and false.
- All the floating-point types, such as f64.
- The character type, char.
- Tuples, if they only contain types that also implement Copy. For example, (i32, i32) implements Copy, but (i32, String) does not.

**GPT 整理:**
1. **整數類型**:
   - 所有整數類型（如 `u32`、`i32`、`u64`、`i64` 等）都實現了 `Copy` trait。
   - 這使得它們在賦值時會被複製，原變數仍然可以使用。

2. **布林類型**:
   - `bool` 類型的值只有 `true` 和 `false` 兩個選項，也實現了 `Copy` trait。
   - 這意味著可以安全地進行複製。

3. **浮點數類型**:
   - 所有浮點數類型（如 `f32` 和 `f64`）也實現了 `Copy` trait。
   - 可以在賦值時進行複製而不影響原變數。

4. **字符類型**:
   - `char` 類型的單個字符也實現了 `Copy` trait。
   - 可以安全地進行複製操作。

5. **元組**:
   - 只有當元組中的所有成員類型都實現了 `Copy` trait 時，該元組才會實現 `Copy` trait。
   - 例如，`(i32, i32)` 是可複製的，但 `(i32, String)` 不是，因為 `String` 不實現 `Copy` trait。

### 不可變借用

```rust
fn main() {
    let s = String::from("Hello, Rust!");
    let len = calculate_length(&s); // 傳遞的是 s 的引用
    println!("Length of '{}' is {}.", s, len);
}

fn calculate_length(s: &String) -> usize {
    s.len() // 返回 s 的長度
}
```

### 可變借用

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

## 3. 所有權轉移 (Move)

當一個變量被賦值給另一個變量時，所有權會轉移。原始變量將無法使用。

```rust
fn main() {
    let s1 = String::from("Hello");
    let s2 = s1; // 所有權轉移到 s2

    // println!("{}", s1); // 這裡會出錯，因為 s1 的所有權已經轉移；你不應該訪問他
    println!("{}", s2);
}
```

## 4. 克隆 (Clone)

如果需要保留原始所有者，可以使用 `clone` 方法來創建一個值的副本。

```rust
fn main() {
    let s1 = String::from("Hello");
    let s2 = s1.clone(); // 克隆 s1，創建一個新值

    println!("{}", s1); // 這裡仍然可以使用 s1
    println!("{}", s2);
}
```

## 5. 生命週期 (Lifetimes)

生命週期是 Rust 中一個進階概念，涉及到引用的有效範圍，確保在使用引用時不會出現懸空引用。

```rust
fn main() {
    let r;
    {
        let s = String::from("Hello");
        r = &s;
    } // s 的生命週期在這裡結束
    // println!("{}", r); // 這裡會出錯，因為 r 參考的 s 已經超出範圍
}
```

## 總結

[**引用自官方書籍:**](https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html#what-is-ownership)
> <b>When you understand ownership, you’ll have a solid foundation for understanding the features that make Rust unique. In this chapter, you’ll learn ownership by working through some examples that focus on a very common data structure: strings.</b>

如果你對於 Ownership 來不太理解，可以參考以下資料:
- https://www.youtube.com/watch?v=VFIOSWy93H0 ( 這個人的影片也是官方書籍，你如果想有個人帶讀，可以參考這個影片 )