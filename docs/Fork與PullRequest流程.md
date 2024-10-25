# Fork 與 pull requst 流程

## 什麼是 Fork ?

**"Fork" ( 派生 ) 是指從其他人的 Git 儲存庫創建一個自己的副本**

Fork 是一個非常常見的提交流程，在尚未成熟的開發團隊中 ( 沒有一個完整的規範或者默契 )，使用 Fork 可以大幅度的降低錯誤。

## 為什麼使用 Fork ?

當初我原本想使用 "合作者" 模式讓參與者在獲得邀請過後可以控制分支，但是這樣倉庫中的分支會太多太複雜 ( 如果人數比較多的話 )，並且到時候我也不知道怎麼管理。

使用 Fork 除了可以避免之前的問題之外，在開源項目中其實也很常使用 Fork 的方式在自己的遠端倉庫先編輯自己的程式碼，在提交之前先解決一次衝突然後再將代碼利用 pull request 的方式提交到你要提交的地方/倉庫。

## Fork 的作業流程

1. 到你要 Fork 的遠端倉庫，點選右上角的「創建立 Fork」。
2. Fork 選擇只建立 `main` 分支。
3. 將 Fork 的倉庫 clone 到本 地倉庫/電腦中 。
4. 添加原始遠端倉庫的位址到你的本地倉庫：
   ```bash
   git remote add upstream <original_repository_url>
   ```
5. 獲取原始遠端倉庫的資訊 ( 使用 `fetch` ) :
   ```bash
   git fetch upstream/main
   ```
6. 在你的本地環境中建立一個新的分支 ( 基於本地 `main` 分支 ) 。
   ```bash
   git checkout main # 確定你位於 main 分支上
   git branch <New_Branch_Name> # 在 main 分支上 創建新的分支
   ```
7. 切換到該分支：
   ```bash
   git switch <BranchName>
   ```
   或者：
   ```bash
   git checkout <BranchName>
   ```
8. 瀏覽並選擇你要貢獻的區域 ( 如 C 語言、網頁技術等 ) ，創建與之對應的資料夾 ( 不要忘記加上 `README.md` 文件 ) 。
9. 在你創建的分支中提交你的變更 ( 確保不要提交到本地 `main` ) 。
10. 將你的分支推送到你的遠端倉庫：
    ```bash
    git push origin <BranchName>
    ```
11. 當你完成更新作業後，重新獲取原始倉庫的 `main` 分支：
    ```bash
    git fetch upstream/main
    ```
12. 將原始倉庫的 `main` 分支變基到你的本地 `main` 分支：
    ```bash
    git checkout main
    git rebase upstream/main
    ```
13. 合併你的更新分支到本地 `main` 分支：
    ```bash
    git checkout <BranchName>
    git rebase main
    ```
14. 將你的新的 `main` 分支推送到你的遠端倉庫：
    ```bash
    git push origin main
    ```
15. 將你的遠端倉庫的 `main` 分支發送 pull request 到原始倉庫。
16. 提交 pull request 後，等待回應並進行溝通與交流。


- 如果合併允取 : 你可以決定是否刪除你的本地分支。
- 如果要求更改
    1. 直接在你的本地 `main` 上更新，並且推送到 `origin/main`
    2. 等待通知
- 如果合併不允許 / 被拒絕
    1. 根據訊息反饋進行更改
    2. 將原本的遠端 `upstream/main` 覆蓋到你的本地 `main` -> `reset --forse upstream/main`
    3. 在你的分支中進行改進
    4. 重複步驟 11 到 16 ( 步驟14的命令改為 `git push --f origin main`)


* 如果你要進行下一次的新提交...
1. 將本地不必要的分支刪除: `git branch -d <BranchName>`
2. 獲取最新狀態 ( 步驟 4、5 )
3. 強制推送到遠端 `git push --f origin main`
4. 步驟 6~16


## 【VsCode 實作視例】

### **步驟 1**

首先你要做的是創建一個 Fork

![img](https://i.imghippo.com/files/rFn2212sPE.jpg)

點選右上角的紅色按鈕，就可以創建 Fork 了!

### **步驟 2**

勾選必要的設定，或者取新的名字

![img](https://i.imghippo.com/files/dzj2590h.jpg)

- 紅色的框框推薦勾起來，除非你有你自己的想法
- 藍色的名稱都可以任意取，不過我推薦都使用默認名稱即可，當然描述例外

### **步驟 3**

![img](https://i.imghippo.com/files/DGM6901jI.jpg)

如果你有 SSH 金鑰，使用 ssh 連線，指令會長這樣
```shell
PS C:\Users\Sakiyago\Desktop\5> git clone git@github.com:<Your_Name>/<Your_Repository_Name>.git
```

### **步驟4**

添加原始倉庫到你的 Fork 倉庫中，這樣你的電腦中的 Git 才有辦法把他們關連起來。

我們要更新到的是 "別人的遠端倉庫" ( 在本文的例子是 Bongo044152/test.git ) 並非 "你的遠端倉庫" ( 在本文的例子是 MsBongo/test.git ) 。

![img](https://i.imghippo.com/files/Jj8320bo.jpg)

說明:
    - 紅色框框呈現的使用者名稱要是 "別人的名稱" ， 因為你想要提交到 "別人的倉庫" 中。
    - 綠色框框是它的 "倉庫位址" ，你可以選擇 https 或 ssh
    - 綠色框框表示添加成功，下面會有命令說明

命令說明:
```shell
# git remote -v 會顯示當前的遠端位址，其中 origin 表示自己的遠端位址
PS C:\Users\Sakiyago\Desktop\5\test> git remote -v
origin  https://github.com/MsBongo/test.git (fetch)
origin  https://github.com/MsBongo/test.git (push)
# 添加新的遠端位址
PS C:\Users\Sakiyago\Desktop\5\test> git remote add upstream https://github.com/Bongo044152/test.git
# 顯示當前的遠端位址，其中 upstream 表示其他人的遠端位址，在本例子中表示 預提交的遠端位址
PS C:\Users\Sakiyago\Desktop\5\test> git remote -v                       
origin  https://github.com/MsBongo/test.git (fetch)
origin  https://github.com/MsBongo/test.git (push)
upstream        https://github.com/Bongo044152/test.git (fetch)
upstream        https://github.com/Bongo044152/test.git (push)
```

### **步驟5**

![img](https://i.imghippo.com/files/yj6320KnU.jpg)

說明:
    - 如果你有安裝 git graph 可以透過下方的黃色按鈕查看
    - 上面是 fetch 後呈現出的 "提交紀錄圖" ( 藍色框框 )
    - 你可以透過 `git log --graph --oneline --all` 在終端機中取得 "提交紀錄圖"

### **步驟5-7**

![img](https://i.imghippo.com/files/vxwg3957dD.jpg)

說明:
    - 創建成功後，你會看到 紅色框框 裡面多一個 hello 的分支

```shell
# 終端機的顯示 提交記錄圖 命令
PS C:\Users\Sakiyago\Desktop\5\test> git log --graph --oneline --all
* 9c84958 (HEAD -> hello, upstream/main, origin/main, origin/HEAD, main) first commit
```

### **步驟8-9**

![img](https://i.imghippo.com/files/KHgL7214gVs.jpg)

因為你先前已經移動到 hello 分支上，因此在 vscode 按下提交按鈕會提交到 hello 分支，而不是 main 分支

點捲提交即可完成你在 hello 分支上的首次提交，提交內容格式如下 ( 我希望你這樣命名 )
```
MsBongo: first commit
```
**-> 使用者名稱: first commit**

### **步驟10**
點選提交

![img](https://i.imghippo.com/files/uQB7125vA.jpg)

**注意! 是提交到你的遠端倉庫喔(origin)而非 upstream**

### **步驟11-14**

> **<font color="red">注意! 要進行步驟 11-14 ，先確保你的所有更新都已經完成。 我們想要收到的是一份 "完整的更新" 而不是 "片段式的更新"。<br><br>如果你的更新還沒有完成，請你到本地分支 ( hello ) 繼續提交、推送。</font>**

當你想要提交實，此時可能會有其他人已經提交自己的程式碼，因此可能發生衝突問題 ( 你可能和其他人編輯同一份文件，或者資料夾的位置產生移動.. )。

所以要先獲取其他人的更新新狀態，並且將其合併到你的本地 main 分支中。

然後在把你的分支給合併到本地 main 中，最後一起提交出去，到你的遠端 main 分支。

![img](https://i.imghippo.com/files/YCWu6495eDw.jpg)

指令說明:
1. 獲取遠端更新: 在你編輯代碼的過程中，獲取其他人已經更新完成了! 所以要先獲取 upstream 的更新狀況
```shell
PS C:\Users\Sakiyago\Desktop\5\test> git fetch upstream main
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Compressing objects: 100% (2/2), done.
remote: Total 2 (delta 0), reused 2 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (2/2), 240 bytes | 48.00 KiB/s, done.
From https://github.com/Bongo044152/test
 * branch            main       -> FETCH_HEAD
   9c84958..386c856  main       -> upstream/main
```

2. 合併到本地 main
```shell
# 先切換到 main 分支
PS C:\Users\Sakiyago\Desktop\5\test> git checkout main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
# 再來合併遠端更新
PS C:\Users\Sakiyago\Desktop\5\test> git rebase upstream/main
Successfully rebased and updated refs/heads/main.
```

3. 添加你的更新 -> 別忘記先切換到 main 分支上
```shell
PS C:\Users\Sakiyago\Desktop\5\test> git rebase hello
Successfully rebased and updated refs/heads/main.
```

4. 提交

### **步驟15-16**
現在! 你正準備將你的檔案更新到別人的倉庫當中!

> **注意! 記得確認紅色框框是自己的倉庫名稱，因為提交是從你的倉庫發起的!**

![img](https://i.imghippo.com/files/ao6499n.jpg)

點選綠色的 `New pull request` 即可創建一次提交。

![img](https://i.imghippo.com/files/wAx3563PRM.jpg)

確認是從你的本地的 main 分支中提交，盡量不要從你的分支中提交，不然這樣前面的獲取更新就沒有意義了。

![img](https://i.imghippo.com/files/QUZQ8333Bmg.jpg)

倉庫裡面的人員會進行檢查，確保你沒有隨意刪除別人的檔案、發生衝突等。

如果有問題，可以在裡面討論!

![img](https://i.imghippo.com/files/oDu9624nZI.jpg)

會有人進行投票等操作，只要票數過一，會有人幫你合併你的檔案到遠端倉庫! 如果你成功做到這裡，我在此感謝你的貢獻與願意讀到這裡耐心。

## 衝突解決

衝突的解決會比較複雜一些，對於 git 而言，如果同一份文件的某一行有兩個寫法/變更，git 不知道要保留哪一個變更，因此會發生衝突。

具體的解決方式會有兩種，兩種都偏複雜... 總之只要有衝突，通常是直接叫你滾回去重寫，而不是線上修改。

## 結語
希望這份文件對你有所幫助，後續有更好的提交辦法我會在更新。