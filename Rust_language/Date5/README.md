# 猜數字遊戲

## 涵蓋
1. 了解 cargo 以及 "pakage"
2. rust 的 `match` 、 `rand`
3. rust 的迴圈

## 內文
在 rust 中，包管理主要的檔案有兩個
1. Cargo.toml: 記錄你的主要 library 套件
2. Cargo.lock: 副檔名為 lock 的檔案，用來記錄所有相依的套件

### **什麼是 `Cargo.toml` ?**

1. **定義依賴**：`Cargo.toml` 是一個配置文件，在 `[dependencies]` 部分中，指定了項目所需的外部 crate 及其版本。

2. **版本語義**：使用語義版本控制（SemVer）來指定依賴的版本，例如 `rand = "0.8.5"`，表示使用 0.8.5 及以上版本，但低於 0.9.0 的任何版本。這樣可以確保代碼在依賴更新時仍然可以正常編譯。

3. **依賴更新**：當你添加或修改依賴後，運行 `cargo build` 時，Cargo 會自動從 crates.io 下載所需的 crate 及其依賴，並進行編譯 :
```shell
PS C:\Users\Sakiyago\Desktop\Note\Rust_language\Date5> cargo run      
   Compiling cfg-if v1.0.0
   Compiling byteorder v1.5.0
   Compiling getrandom v0.2.15
   Compiling rand_core v0.6.4
   Compiling ppv-lite86 v0.2.20
   Compiling rand_chacha v0.3.1
   Compiling rand v0.8.5
   Compiling Date5 v0.1.0 (C:\Users\Sakiyago\Desktop\Note\Rust_language\Date5)
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 3.29s
     Running `target\debug\Date5.exe`
```

4. **快速重建**：如果沒有改變 `Cargo.toml` 或代碼，重複運行 `cargo build` 不會重新編譯已經下載的依賴，Cargo 會重用之前編譯的結果，加快構建速度 ( 你可以比對上下執行 `cargo run` 的輸出差異 )
```shell
PS C:\Users\Sakiyago\Desktop\Note\Rust_language\Date5> cargo run
    Finished `dev` profile [unoptimized + debuginfo] target(s) in 0.02s
     Running `target\debug\Date5.exe`
```

5. **依賴鏈**：Cargo 會自動下載該依賴所需的所有其他依賴確保完整，並且使用 `Cargo.lock` 來鎖定依賴版本，確保每次編譯都使用相同的依賴版本。

這是今日的範例: 
```toml
[package]
name = "Date5"
version = "0.1.0"
edition = "2021"

[dependencies]
rand = "0.8.5"
```

- 資料來源: [**Cargo 官方書籍**](https://doc.rust-lang.org/book/title-page.html) 經由人工篩選出正確的段落後由GPT列點生成，並且人工重新編輯整理。

### **什麼是 `Cargo.lock` ?**

1. **可重現的構建**：`Cargo.lock` 文件確保每次構建都使用相同的依賴版本，有助於穩定。

2. **初次構建生成**：當你第一次運行 `cargo build` 時，Cargo 會根據 `Cargo.toml` 中的依賴信息計算出適用的版本，並將這些版本寫入 `Cargo.lock` 文件。

3. **未來構建使用**：如果 `Cargo.lock` 文件存在，Cargo 會直接使用該文件中指定的版本，以保持穩定。

4. **版本更新**：當需要更新某個 crate 時，可以使用 `cargo update` 命令。這個命令會忽略 `Cargo.lock`，根據 `Cargo.toml` 中的規範找到最新的版本，並更新 `Cargo.lock` 文件。

6. **合作優勢**：預設情況下 `Cargo.lock` 會被 `git` 讀取，幫助多人協作時統一環境/版本。

- 資料來源: [**Cargo 官方書籍**](https://doc.rust-lang.org/book/title-page.html) 經由人工篩選出正確的段落後由GPT列點生成，並且人工重新編輯整理。

# cargo 的額外補充

在[**官方文件中**](https://doc.rust-lang.org/book/title-page.html)有補充兩個 cargo 的魔法:

1. `cargo build --release` : 這個命令會使用預設的優化來編譯你的程式碼，並將結果放在 `target/release` 目錄中。這個命令會使用預設的優化來編譯你的程式碼，並將結果放在 `target/release` 目錄中。
2. `cargo doc --open` : 這個命令用於生成項目的文檔。

特別是那個 doc 真的是魔法 !
