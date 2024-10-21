# Rust 語言的學習

## Rust 介紹

Rust 是一種系統編程語言，旨在提供安全性、速度和並發性。由 Mozilla 開發，Rust 特別適合需要高性能和內存安全的應用。它的設計理念包括：

1. **記憶體安全**：Rust 通過所有權系統和借用檢查器（borrow checker）來防止常見的錯誤，如空指針和資料競爭。這讓開發者能夠在編譯時期捕捉錯誤，而不是在運行時。

2. **高性能**：Rust 的編譯器能夠生成高效的機器碼，使得 Rust 應用的性能可媲美 C 和 C++。這使得 Rust 成為編寫系統應用、嵌入式系統和高性能計算的理想選擇。

3. **現代語言特性**：Rust 擁有強大的類型系統和模式匹配功能，支持函數式編程風格，並且提供了豐富的標準庫，使得開發更為便捷。

4. **並發性**：Rust 的所有權系統使得並發編程變得更安全，開發者可以輕鬆編寫多線程應用，而無需擔心資料競爭。

5. **生態系統**：Rust 擁有一個快速增長的生態系統，`Cargo` 作為其包管理工具，簡化了依賴管理和項目構建。

### 主要用途

- **系統編程**：用於開發操作系統、驅動程式等底層系統應用。
- **Web 應用**：通過框架如 Rocket 和 Actix 來開發後端服務。
- **嵌入式開發**：適合用於資源有限的嵌入式系統。
- **遊戲開發**：使用 Bevy 和 Amethyst 等引擎進行遊戲開發。

Rust 是一種強大而現代的語言，適合用於各種領域的開發。無論你是系統編程新手還是經驗豐富的開發者，Rust 都提供了吸引人的特性和工具，值得學習和探索。

## 環境建構

參考影片、參考文獻，你需要 Visual Studio ( for microsoft )

downlinked: https://www.rust-lang.org/tools/install

### **重要資訊補充:**
**對於由於 vscode 插件 -> "rust-analyzer" 對於包管理有嚴格的要求，也就是說需要搭配包管理工具 `cargo` 來完成工作區的配置，這樣 vscode 才會提供 關鍵字提示 的功能。**

**如果要 debug 還需要另外安裝 "CodeLLDB" 作為擴展，詳細我也不清楚，等我清楚了會再逐步完善此介紹文件**

- 詳細配置參考 : https://users.rust-lang.org/t/setting-up-rust-with-vs-code/76907
- 官方文件 : https://code.visualstudio.com/docs/languages/rust (包含詳細的命令)

## 檔案描述

所有的檔案都使用 .rs 進行，這不是一個良好的配置，因為 vscode 要求我們應該使用 cargo 來進行包管理。

但是沒關係，依然可以透過命令執行如下:

```shell
PS C:\Users\Sakiyago\Desktop\Note\Rust_language> rustc hello.rs 
PS C:\Users\Sakiyago\Desktop\Note\Rust_language> ./hello.exe
Hello, world! # 這是程式輸出
```

**額外補充: .pgb 好像是編譯後的產物，具體用途等我學更多再說**

## 參考資料

- ytVideo : https://www.youtube.com/watch?v=T_KrYLW4jw8&list=PLzMcBGfZo4-nyLTlSRBvo0zjSnCnqjHYQ
- rust book: https://doc.rust-lang.org/book/ch01-01-installation.html


### <font color="red">注意! 沒意外的話本筆記不會再更新，因為這只是一份介紹文件</font>