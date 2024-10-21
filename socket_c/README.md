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

## 實行方案

### 1. 防火牆配置

1. 卸載該死的諾頓
2. 新增防火牆規則，允許自己想要的TCP連線進入 (在我們的例子中，5090)

### 2. 配置端口轉發

由於被監聽的端口是 wsl 的 5090
因此方法有3:
1. 使用docker做端口映射
2. 手搓一個代理
3. 流量轉發

在windows系統中，流量轉發是一個容易實現的一件事情:
1. 確保你啟用了管理員全線
2. 執行以下命令:
```shell
PS C:\Users\Sakiyago> netsh interface portproxy add v4tov4 listenport=5090 listenaddress=0.0.0.0 connectport=5090 connectaddress=172.28.23.217

PS C:\Users\Sakiyago> netsh interface portproxy show all

接聽 ipv4:             連線到 ipv4:

位址            連接埠      位址            連接埠
--------------- ----------  --------------- ----------
0.0.0.0         5090        172.28.23.217   5090
```
其中欲傳發的網址 `172.28.23.217` 需要替換成你的 wsl 的私有 ip ；在此之前可以透過 `ping` 命令來確認連線狀況 ( 透過這種方式檢查 wsl 的防火牆是否有阻擋進行簡單的連線測試 ) 。

### 3. 配置程式碼
1. 檢查server的端口配置
2. 檢查cilent的目的ip、目的端口是否正確

## 參考資料

- 文章1: https://zake7749.github.io/2015/03/17/SocketProgramming/
- hacjmd: https://hackmd.io/@zoo868e/socket-self-study
- lunix文黨: https://www.linuxhowtos.org/C_C++/socket.htm
- geeksforgeeks: https://www.geeksforgeeks.org/socket-programming-cc/
- medium 文章 : https://blog.devgenius.io/socket-programming-in-c-client-4408231f9e65
- 教學文件: https://www.geeksforgeeks.org/socket-programming-cc/