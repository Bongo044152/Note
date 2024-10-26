# 註冊 github 並且提交你的代碼

## 如何註冊 Github ?

1. 進入官網: https://github.com/
2. 跟著介面做 ( 後面你自己就會了 )

## 創建你的第一個倉庫
1. 點選 這東西，會妳的主頁面的左上角

![img](https://i.imghippo.com/files/pZEW2488Ek.jpg)

跟著步驟，恭喜你會了!

在過程中，你可能會疑惑的點:
   - 如果你要選許可證 ( License ) ，MIT我覺得不錯
   - `.gitignore`檔案 是告訴 git 有些檔案永遠不要列入 提交歷史/版本紀錄 中，自動忽略。 例如有一份檔案是你的帳號密碼，那肯定不可以直接丟到github上，除非倉庫是私有的 ( 即表示別人不會看到，除非你指定那些特定的用戶 )。

## 什麼是 SSH 金鑰?

SSH（金鑰安全外殼）金鑰是一種非對稱加密技術，用於安全地連接到遠端伺服器 ( aws 的伺服器就支持 ssh 遠端連線 )、上傳代碼到 Github 等...。

SSH 金鑰由一對密鑰組成：公鑰和私鑰。

<font color="red"><b>免責聲明: 接下來會討論到 SSH Key 的配置方式，當然在代碼提交到遠端的過程中，https是可以被使用的! 因此如果嫌麻煩可以不要配置 SSH 金鑰，但 SSH 各方面來說都挺方面，看你怎麼想。</b></font>

### 1. 金鑰組成

- **公鑰**：這東西像是一把鎖頭，你可以分給很多人讓他們自己使用這個鎖頭去加密訊息，但是正如同我前面的比喻那樣，只有鎖頭只能加密訊息並沒有鑰匙解鎖。
  
- **私鑰**：這是你的鑰匙須妥善保管不可外流。 鎖頭/加密方式 被流傳出去沒關係，但是 鑰匙/解密方式 流傳出去會造成安全隱患，即表示別人可以透過這把鑰匙開鎖。

### 2. 常見應用

- **版本控制**：用於 Git 和 GitHub，安全地推送和拉取代碼。
- **遠端伺服器管理**：用於安全地登錄到遠端伺服器（如 Linux 伺服器）。

SSH 金鑰在確保數據傳輸安全方面發揮著重要作用，並且在現代軟體開發和伺服器管理中被廣泛使用。

了解更多 SSH : https://zh.wikipedia.org/zh-tw/Secure_Shell

GitHub 的解釋: https://docs.github.com/en/authentication/connecting-to-github-with-ssh/about-ssh

## SSH 金鑰配置

### 最牛逼的說明 -> 官方文件

我真心覺得 [**Github 官方文件**](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/about-ssh)寫超好! 我認為直接看官方文件會比以下說明來的詳細、易理解。

---

這份由GPT生成指南將幫助你在 Git 和 GitHub 上配置 SSH 金鑰，確保安全地進行版本控制操作。

### 1. 生成 SSH 金鑰

1. **打開終端機**（Terminal）。
2. 輸入以下指令生成新的 SSH 金鑰：
   ```bash
   ssh-keygen -t rsa -b 4096 -C "你的電子郵件@example.com"
   ```
3. 當提示你輸入檔案名稱時，可以直接按 `Enter`，使用預設路徑（`~/.ssh/id_rsa`）。

4. 如果你希望為金鑰設置密碼，可以輸入一個密碼；如果不想，則直接按 `Enter`。

### 2. 添加 SSH 金鑰到 SSH Agent

1. 啟動 SSH Agent：
   ```bash
   eval "$(ssh-agent -s)"
   ```

2. 將生成的 SSH 金鑰添加到 SSH Agent：
   ```bash
   ssh-add ~/.ssh/id_rsa
   ```

### 3. 將 SSH 公鑰添加到 GitHub

1. 複製 SSH 公鑰到剪貼板：
   ```bash
   cat ~/.ssh/id_rsa.pub
   ```
   或者使用 `pbcopy`（macOS）：
   ```bash
   pbcopy < ~/.ssh/id_rsa.pub
   ```
   或者使用 `xclip`（Linux）：
   ```bash
   xclip -sel clip < ~/.ssh/id_rsa.pub
   ```

2. 登錄到你的 GitHub 帳戶。

3. 進入 **Settings**（設置）。

4. 在側邊欄中，點擊 **SSH and GPG keys**。

5. 點擊 **New SSH key**。

6. 在 **Title** 欄位中為金鑰命名，然後在 **Key** 欄位中粘貼你的公鑰。

7. 點擊 **Add SSH key**。

### 4. 測試 SSH 連接

你可以使用以下指令測試 SSH 連接是否成功：
```bash
ssh -T git@github.com
```
如果看到類似以下的消息，表示配置成功：
```
Hi username! You've successfully authenticated, but GitHub does not provide shell access.
```

### 常見問題

- **如果無法連接，應該檢查什麼？**
  - 確認金鑰是否已添加到 SSH Agent，並且公鑰是否正確添加到 GitHub。

- **如何查看現有的 SSH 金鑰？**
  - 可以使用以下指令查看已生成的金鑰：
  ```bash
  ls -al ~/.ssh # 這是 lunix 指令
  ```

## 上傳代碼到你的倉庫
假設你前面的步驟都順利進行，那麼是時候了!

### 1. 準備你的倉庫，這邊以 hello 為例

![img](https://i.imghippo.com/files/upGb3955NOk.jpg)

### 2. 進入倉庫後，安照指示即可完成推送

Ps. 如果沒有 SSH 金鑰，要勾選 https

![img](https://i.imghippo.com/files/lTC2717IQY.jpg)

### 3. 按照步驟執行即可，這邊以 "create a new repository on the command line" 為例

- 在桌面中創建你的資料夾，名稱與遠端同名

【終端機 windows 操作】
```shell
PS C:\Users\Sakiyago\Desktop> cd .\hello\
PS C:\Users\Sakiyago\Desktop\hello> git init
Initialized empty Git repository in C:/Users/Sakiyago/Desktop/hello/.git/
PS C:\Users\Sakiyago\Desktop\hello> echo "# hello" >> README.md
PS C:\Users\Sakiyago\Desktop\hello> git add README.md
PS C:\Users\Sakiyago\Desktop\hello> git commit -m "first commit"
[main (root-commit) fa62cfc] first commit
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 README.md
PS C:\Users\Sakiyago\Desktop\hello> git branch -M main
PS C:\Users\Sakiyago\Desktop\hello> git remote add origin git@github.com:Bongo044152/hello.git
PS C:\Users\Sakiyago\Desktop\hello> git push -u origin main
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 231 bytes | 231.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To github.com:Bongo044152/hello.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.
```

【VsCode 介面操作】
1. 使用 VsCode 開啟資料夾
2. 初始化本地倉庫 (效力等同於 git init)

![img](https://i.imghippo.com/files/dGJV9825fF.jpg)

3. 新增檔案 (官方文件是以 README.md 為例，我這邊隨便)

![img](https://i.imghippo.com/files/Veqc7961pQ.jpg)

其中:
   - 黃色框框表示 "變更"，就是教學影片提到的站存區
   - 當你點選紅色框框的 "+" 時，效力等同於 `git add fuck.txt`，也就是將變更提交到站存區
   - 之後按下提交按鈕，就可以提交了! 別忘了添加你的提交訊息

![img](https://i.imghippo.com/files/CHr2688B.jpg)

其中:
   - "蔡基" 是我的提交訊息，通常會是 "first commit" 比較常見
   - 右上角的 "打勾符號" 效力等同於 `git commit -m "蔡基"`

4. 推送到遠端

![img](https://i.imghippo.com/files/JuK1346UYI.jpg)

這個按鈕按下之後會發送到遠端，但是前提是你要先配置好你的遠端是誰，因此在vscode的終端機中:

```shell
PS C:\Users\Sakiyago\Desktop\hello> git remote add origin git@github.com:Bongo044152/hello.git
```

然後才可以按下提交按鈕，是不是很簡單啊! 之後就是無腦提交即可，方便又實惠! 這就是GUI的強大，不用背指令!

你可以到 github上檢視有沒有成功上傳
![img](https://i.imghippo.com/files/LG6125Yo.jpg)


## 想了解更多嗎?
- [**Github工作流**](Github工作流.md) <- 倉庫文件
- [**十分钟学会正确的github工作流，和开源作者们使用同一套流程**](https://www.youtube.com/watch?v=uj8hjLyEBmU)
- [**Git工作流**](https://medium.com/@trylovetom/%E8%AE%93%E6%88%91%E5%80%91%E4%BE%86%E4%BA%86%E8%A7%A3-github-flow-%E5%90%A7-4144caf1f1bf)