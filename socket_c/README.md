# 🚨 注意事項 🚨

### 請在 wal 中執行，並且安裝好對應的包

該檔案會持續更新，請等待文件被完善...

## 執行須知

1. 本程式由C語言撰寫，你需要一定的理解(需要具備基礎的C語言概念)
2. 運行環境為lunix，你需要對於lunix系統有一定的了解 (基礎命令、權限、工具)
3. socket是一個強大的網路工具，主要可以配置 第3層 以上的所有網路協議，但是對於下面兩層(乙太網與實體連階層)並不是我們主要探討的地方。<br>
希望你具備一定的網路知識，這樣理解起來比較輕鬆。

## 環境配置

### 1. Lunix系統

程式碼運行在lunix系統中，如果你是使用windows，可以使用wsl來快速配置你的lunix環境

如果你是其他作業系統 ( 包括windows ) 可以使用虛擬機的方式，來建立你的環境

### 2. 安裝 GCC 編譯器

```bash
sudo apt update
sudo apt install gcc
```

### 3. 安裝 Make 工具

```bash
sudo apt install make
```

### 4. 安裝必要的庫

```bash
sudo apt install build-essential
```

### 5. 確認安裝

```bash
gcc --version
make --version
```

## 可執行檔案

- test3 系列

## 參考資料

- 文章: https://zake7749.github.io/2015/03/17/SocketProgramming/
- lunix文黨: https://www.linuxhowtos.org/C_C++/socket.htm
- github 儲存庫... (搜尋中...)
- medium 文章... (搜尋中...)
- 教學文件: https://www.geeksforgeeks.org/socket-programming-cc/