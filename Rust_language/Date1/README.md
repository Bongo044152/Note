# 概要

1. 安裝 rust
2. 在 vscode 配置 rust
3. 建立你的第一份 rust 檔案
4. 了解 rust 的管理工具 `cargo` 命令
5. 了解 `rustfmt` 自動格式化代碼工具
6. rust 的特性

## 1. 安裝 rust

- 參考書籍: https://doc.rust-lang.org/book/ch01-01-installation.html

1. [**進入官網**](https://www.rust-lang.org/tools/install)並且下載適合你的安裝程式
2. 安裝成功後，嘗試在終端機中運行
```shell
PS C:\Users\Sakiyago\Desktop\Note\Rust_language\Date1> rustc --version
rustc 1.82.0 (f6e511eec 2024-10-15) 
PS C:\Users\Sakiyago\Desktop\Note\Rust_language\Date1> rustup update
info: syncing channel updates for 'stable-x86_64-pc-windows-msvc'
info: checking for self-update

  stable-x86_64-pc-windows-msvc unchanged - rustc 1.82.0 (f6e511eec 2024-10-15)

info: cleaning up downloads & tmp directories
```
你應該會得到類似這樣的輸出。

### 錯誤排查
如果你的命令執行失敗，請嘗試以下除厝步驟:
1. 重新啟動你的終端機
2. 重新啟動你的電腦
3. 手動配置環境變數
4. 根據你的問題，查閱更多文獻

## 2. 在 vscode 配置 rust
很神奇的地方是，關於怎麼在 vscode 配置 rust 的文獻相當的少，但是 microsoft 扔然提供了文件幫助使用者在vscode啟用 rust 。

- https://code.visualstudio.com/docs/languages/rust

或者參考以下[**這份文獻**](https://users.rust-lang.org/t/setting-up-rust-with-vs-code/76907)

上述內容可以總結程3個步驟:
1. 在 vscode 中加入 "rust-analyzer" 插件
2. 在 vscode 中加入 "-Code LLDB" 插件
3. 使用 `cargo` 建構你的程式

### 額外說明
在 rust-analyzer 中，你一定要使用 cargo 創建代碼，不可以只是單純的 .rs 否則自動提示功能不會被加入。

## 3. 建構 rust 專案

- 執行命令 `cargo new <ProjectName>`
```shell
PS C:\Users\Sakiyago\Desktop\Note\Rust_language> cargo new Date2
    Creating binary (application) `Date2` package
warning: the name `Date2` is not snake_case or kebab-case which is recommended for package names, consider `date2`
note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html
```

## 4. 了解 Cargo 命令
1. `cargo build` : 編譯程式碼
```shell
PS C:\Users\Sakiyago\Desktop\Rust_language\hello_world> cargo build
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.00s
```
編譯完成後，可以在 ./target/debug/<YourProjectMame>.exe
2. `cargo run` : 編譯並且執行程式碼
```shell
PS C:\Users\Sakiyago\Desktop\Rust_language\hello_world> cargo run
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.08s
     Running `target\debug\hello_world.exe`
Hello, world!
```
3. `cargo check` : 檢查 cargo 專案是否可以接受編譯 ( 編譯前手動檢查錯誤 )
```shell
PS C:\Users\Sakiyago\Desktop\Rust_language\hello_world> cargo check
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.00s
```

## 5. rustfmt 命令

```rs
fn main() {



    println!("Hello, world!");}
```
上面這個程式碼看起來醜爆了! 現在執行這個神奇的命令，它會變得漂亮:
```shell
PS C:\Users\Sakiyago\Desktop\Rust_language\hello_world\src> rustfmt main.rs
```
執行完過後
```rs
fn main() {
    println!("Hello, world!");
}
```

## 6. 特性

1. 閱讀並且嘗試執行下面的程式碼，你會發現有趣的事情
```rs
fn main() {
    let x = 4;
    println!("x = {}", x);

    // this will not cause an error, while variable is declared twice
    let x = 5;
    println!("x = {}", x);
    let x = x+1;
    println!("x = {}", x);

    // rust 語言中，如果要像第12行那樣更改數值，必須要事先聲明 mut -> multiple
    // 如果沒有事先聲明編譯器會叫!
    let mut y = 9;
    println!("y = {}", y);
    y = 10;
    println!("y = {}", y);

    // 沒有聲明 mut
    let z = 10;
    println!("z = {}", z);
    // z = 20; <- 這會引發錯誤

    // 執行多餘的步驟
    let mut a = 15;
    a = 20; // 為什麼不要一開始就決定好? rust 會這樣警告你，因為實際上你只需要 let a = 20; 即可
    println!("a = {}", a);

    // 宣告一個變數但是不使用!
    let b = 9; // 他還是會警告你! 爽不爽!

    let _c = 9; // 這是預設不會被使用的變數，加上 _ 表示
}
```
從這裡可以看出 rust 非常嚴格