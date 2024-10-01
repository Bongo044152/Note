# 權限設定

1. 切換用戶
    - root用戶
    ```bash
    su - # 以 root 的身分登入
    ```
    - user用戶
    ```bash
    su - username # 特定的使用者
    ```

### 補充
> **為root用戶添加密碼**

理由: 因為`root`用戶具有非常非常大的權限，可以管理電腦的一切! 比windows的管理員模式還要強，甚至可以直接摧毀系統!

首先: 切換`root`用戶
第二步: 執行命令`passwd` (無須指定)
第三步: 添加好密碼後輸入`exit`已離開`root`模式

2. sudo

略...

3. 目前用戶
```bash
whoami
```

4. 新增用戶
```bash
useradd [option] UserName
```

Option:<br>
`-m`: 自動創建用戶的主目錄<br>
`-s`:指定用戶默認的登入shell，例如`/bin/bash`<br>
`-G`:指定用戶所屬的附加群組

5. 設定用戶密碼
```bash
passwd User
```

6. 查詢特定用戶訊息
```bash
getent passwd username
```

7. 查看所有用戶訊息
```bash
cat /etc/passwd
```

# 系統資訊

1. 取得時間 - 取得系統時間
```bash
date
```

2. 顯示本月月曆
```bash
cal
```

3. 顯示開機時數
```bash
uptime
```

4. 系統名稱以即版本訊息
```bash
uname -a
```

5. 操作系統的詳細訊息
```bash
cat /etc/os-release
```

## 介紹系統根目錄
1. `/bin`

**執行命令所需的基本執行黨**

2. `/boot`

**啟動 lunix 所需的核心文件**

3. `/dev`

**所有的設備檔案 ( 記憶體、硬碟、虛擬終端、Console 等等 )，所有的裝置都被視為一個檔案**

4. `/etc`

**系統配置檔案與應用程序以及使用者資訊(`/etc/passwd`、`/etc/group`)，`nginx`、`docker`、`python`也在其中**

5. `/home`

**用戶個人資料，每個用戶都有依照名稱命名的子目錄/資料夾**

6. `/lib`

**共享程式庫**

7. `/mnt`

**掛載臨時檔案，例如程式碼、CD讀取等**

8. `/opt`

**安裝額外的應用，例如你自己的應用服務或者docker容器或者第三方應用**

9. `/root`

**存放root用戶的資訊**

10. `/run`

**系統運行臨時開闢的檔案，重新啟動系統會被清除**

11. `/usr`

**存放包括用戶命令、用戶可共享文件(類似`/usr/lib`)**

12. `/var`

**儲存變動的數據(通穰`/var/log`會是一個常見的文件)，用以存放系統日誌等等**

13. `/sbin`

**只有系統管理員可以使用的指令，也包括了開機、修復和還原系統所需要的指令**

14. `/tmp`

**存放一些暫時性的文件**

![檔案系統階層圖](https://lcom.static.linuxfound.org/sites/lcom/files/standard-unix-filesystem-hierarchy.png)

# 開機與關機

**使用`root`管理員權限執行，執行前記得先運行`sync`將系統文件寫進硬碟**

1. 關機
```bash
shutdoen [option] TIME [message]
```

TIME:<br>
`now`:立即關機<br>
`+m`:幾分鐘之後關機，例如`+10`<br>
`hh:mm`:指定時間關機(24小時制度)，例如`20:24`

Option:<br>
`-r`: 重新開機<br>
`-h`: 系統停止運作或關閉電源<br>
`-P`:關閉電源<br>
`-c`:設消之前的關機指令

msaasge:

**隨意內容給其他使用者**
```bash
shutdown -h 16:30 "Server will shutdown at 16:30 for maintenance."
```

# 常用指令

0. `clear` : 清除終端機

1. 列出檔案
    - `ls` : **列出文件**

    - `ls -l` : **列出比較詳細的文件**

    - `ls -a` : **列出所有檔案(包括隱藏目錄)**

2. 切換目錄
    - `cd [directory path]`

3. `mkdir <directory>` : 建立目錄 (或者稱為 "資料夾")

3. `rmdir` : 刪除 <u>**空的**</u> 目錄

4. `touch` : 建立空白檔案
```bash
touch test.txt
```

6. `pwd` : 顯示當前所載路徑

7. `cp` : 複製檔案

格式:
`cp [source] [destination]`
```bash
cp test1.txt testDir1
```

8. `rm` : 刪除檔案或目錄

格式:
`rm [option] [file/folder]`

option :<br>
-f : 強制 (force) 刪除，不會出現警告訊息。<br>
-i : 互動 (interactive) 模式，刪除前會先詢問使用者。<br>
-r : 遞迴 (recursive) 刪除，用於刪除目錄，但也非常危險。

9. `mv` : 移動檔案或目錄，也可以用來修改名稱

格式: `mv [source] [destination]`

10. `cat` : 顯示檔案內容&建立檔案

- 輸出檔案範例
```bash
cat -n testcat # 加上 -n 參數，可以看到每一行都會顯示行數。
     1  This is a test.

     2  this is a test.

     3  This is a       tab     test.
```
- 建立檔案範例
```bash
bongo@MSI:/mnt/c/Users/Sakiyago/Desktop/Shell_lenguage/lunix$ cat > test.txt
666
66
6
# 這間輸入 [Ctrl + D] 表示停止輸入，如果是輸入 [Ctrl + C] 則是直接跳出 (即不儲存)
bongo@MSI:/mnt/c/Users/Sakiyago/Desktop/Shell_lenguage/lunix$ cat -n test.txt 
     1  666
     2  66
     3  6
bongo@MSI:/mnt/c/Users/Sakiyago/Desktop/Shell_lenguage/lunix$ rm test.txt  # 刪除文黨
```

11. vi 與 vim : 文本編譯器，這個可以自行了解、學習

12. `find` : 檔案查詢
```bash
find . -name "*.txt"
```

### 檔案權限
1. `chown` 更改檔案擁有者
```bash
chown user2 testFile1
```
2. `chmod` 更改檔案權限
```bash
chmod 754 testFile.txt
```
- 其中: rwx = 4 + 2 + 1
- 第一組表示 "檔案擁有者"
- 第二組表示 "檔案擁有者所屬群組"
- 第三組表示 "其餘人"

#### 補充說明
`g`表示所屬群組
`o`表示其餘人
`u`表示檔案擁有者
`a`表示所有
示例一:
```bash
chmod a=rwx
```
示例二:
```bash
chmod u=rwx,go=rx testFile.txt
```
示例三:
```bash
chmod u-w,o+x testFile.txt # 透過 '+' 與 '-' 可以進行簡單的運算
```

| 權限 | 檔案                           | 目錄                           |
|------|--------------------------------|--------------------------------|
| r    | 可以讀到檔案內容              | 可以讀到目錄下檔名            |
| w    | 可以修改文件內容              | 可以修改目錄下文件檔名        |
| x    | 可以執行文件內容              | 可以進入該目錄                |


### 一張關於檔案權限的有趣圖片
![chowm與chmod示意圖](https://turnoff.us/image/en/chown-chmod.png)


# lunix 網路工具
1. `ping`: 檢查網路連接，發送 ICMP
2. `traceroute`: 資料包從你的機器到目標主機的路由路徑
3. `ifconfig`: 顯示網路介面
4. `netstat`: 顯示網路連接、路由表等

`-t`：顯示 TCP 連接<br>
`-u`：顯示 UDP 連接<br>
`-l`：僅顯示正在監聽的連接<br>
`-n`：以數字格式顯示地址和端口號（不解析為主機名）<br>
`-p`：顯示每個連接的程序 PID<br>
`-r`：顯示路由表<br>
`-i`：顯示網路介面統計<br>

### 顯示所有 TCP 和 UDP 連接及其狀態（以數字格式顯示）
```bash
netstat -tun
```
### 正在監聽的 TCP 和 UDP 端口
```
netstat -tul
```
### 顯示所有監聽的連接及其 PID（以數字格式顯示）
```bash
netstat -tulp # 你也可以加上 n，但我不喜歡
```
### 顯示路由表
```bash
netstat -r
```
### 檢視網路介面數量
```bash
netstat -i
```

5. `nslookup` 查看 DNS的資訊
```bash
bongo@MSI:/mnt/c/Users/Sakiyago/Desktop/Shell_lenguage/lunix$ nslookup www.google.com
Server:         10.255.255.254
Address:        10.255.255.254#53

Non-authoritative answer:
Name:   www.google.com
Address: 142.250.196.196
Name:   www.google.com
Address: 2404:6800:4012:2::2004
```

6. `wget` and `curl`
- `wget`用來下載檔案
- `curl`用來測試"協議"通訊(例如http協議)

7. `nmpt` 網路掃描工具
```bash
bongo@MSI:/mnt/c/Users/Sakiyago/Desktop/Shell_lenguage/lunix$ nmap www.bongo044152.link
Starting Nmap 7.95 ( https://nmap.org ) at 2024-10-01 14:09 CST
Nmap scan report for www.bongo044152.link (18.177.62.223)
Host is up (0.039s latency).
Other addresses for www.bongo044152.link (not scanned): 18.177.98.63
rDNS record for 18.177.62.223: ec2-18-177-62-223.ap-northeast-1.compute.amazonaws.com
Not shown: 997 filtered tcp ports (no-response)
PORT    STATE  SERVICE
22/tcp  closed ssh
80/tcp  open   http
443/tcp open   https

Nmap done: 1 IP address (1 host up) scanned in 4.47 seconds
```

8. `tcpdump` 封包捕獲工具

# ssh 加密連線 (搭配使用者登入)
參考: https://hackmd.io/@tienyulin/linux-ssh

# 我以前的筆記 (具有編輯權限的連結，請勿隨意轉傳)
- https://colab.research.google.com/drive/1Gwuwl-rWxiK4t-xHIax6fuFdml34waXE?usp=sharing