# GitHub 工作流程

## 簡介/引言

相信您已經是一位相對成熟或想要變得更成熟的開發者。本篇文章將探討：

1. GitHub 工作流程的概念介紹
2. GitHub Flow 工作流程的詳細介紹

請確保您具備以下知識：

- 基礎的開發知識（終端機、程式語言等）
- 什麼是 Git
- 什麼是 GitHub
- 了解並會使用 Git/GitHub
- 會使用 Markdown 語法並撰寫良好的 README 文件以介紹自己的專案

## 為什麼需要「協同開發」？

我曾獨自撰寫前後端的經驗，花了兩個星期撰寫出5000行程式碼，感到十分疲累。如果許多人一起合作，時間會更少、效率會更高，且每個人可以發揮自己的專長，例如前端和後端。

在程式開發中，每位開發者的程式碼風格和實現方式各有千秋。如果想要與他人合作，就必須遵循一定的「規範」。例如，對於前後端來說，API 文檔是必須的，其他人必須了解如何使用您的代碼。

在代碼更新過程中，各自更新代碼時容易發生衝突。因此，本篇文章將重點放在「如何將代碼更新到遠端倉庫中」，而如何協同開發將在未來的討論中進一步探討。

## 什麼是 GitHub 工作流程？

如前所述，更新代碼容易造成衝突，而工作流程則是一種公約：指導您如何正確地將程式碼更新到 GitHub 上。

## 常見的 GitHub 工作流程

1. **GitHub Flow**

   ![image](https://miro.medium.com/v2/resize:fit:1400/format:webp/1*HK59nKmhvL9WQfjsVSvSTQ.jpeg)

2. **Git Flow**

   ![image](https://miro.medium.com/v2/resize:fit:1100/format:webp/1*kEqRjySuIJIH7IkqE3wmjA.png)

介紹文章: [Git 上的三種工作流程](https://medium.com/i-think-so-i-live/git%E4%B8%8A%E7%9A%84%E4%B8%89%E7%A8%AE%E5%B7%A5%E4%BD%9C%E6%B5%81%E7%A8%8B-10f4f915167e)

---

**GitHub Flow** 是適合小型項目或獨立開發的工作流程，簡單易懂，適合入門者使用。

## Github flow

要了解 Github flow ， 除了多加練習之外，你可以參考以下資料搭配文章以更好的理解:

- 參考影片 : https://www.youtube.com/watch?v=uj8hjLyEBmU
- 文章: https://medium.com/@trylovetom/%E8%AE%93%E6%88%91%E5%80%91%E4%BE%86%E4%BA%86%E8%A7%A3-github-flow-%E5%90%A7-4144caf1f1bf

【如果有人願意提供程式碼或者圖片視例，我在這邊先感謝他】

<!-- 以空白倉庫為例:
### 1. 克隆倉庫
將遠端倉庫克隆到本地中
```shell
PS C:\Users\Sakiyago\Desktop> git clone git@github.com:Bongo044152/git-test.git
Cloning into 'git-test'...
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 3 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (3/3), done.
PS C:\Users\Sakiyago\Desktop> cd .\git-test\
PS C:\Users\Sakiyago\Desktop\git-test> ls


    目錄: C:\Users\Sakiyago\Desktop\git-test


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----      2024/10/23  下午 02:26              0 test1.txt
```

### 2. 建立分支
main ( 主要分支 ) 是你的代碼要隨時返回的狀態 ( 最穩定的存檔點 ) 、或者要隨時發行的狀態 ( release )。 因此在預設情況下不允許直接對 main 分支進行提交，所以你需要建立自己的分支當作代碼暫時儲存的地方，而其他人也因該這樣做，避免所有更新都在 main 上面引起混亂。

```shell
PS C:\Users\Sakiyago\Desktop\git-test> git branch test1
PS C:\Users\Sakiyago\Desktop\git-test> git checkout test1
Switched to branch 'test1'
```

![image](https://i.imgur.com/L82fD52.jpeg)

現在你可以看到我們創建了新的分支了!

### 3. 更新分支
就像你正常使用 git 那樣，開始對你的分支進行提交。

![img](https://i.imgur.com/tA8Ut4i.jpeg)

我這邊隨便添加了一份新文件，現在你在本地開發環境中，為了讓其他人更好的追蹤你的更新狀況，或者你今天想要跨裝置更新等操作，總之為了之後的方便，你可以對你的遠端先進行一次更新。

### 4. 合併分支並且提交

在合併分支的 -->