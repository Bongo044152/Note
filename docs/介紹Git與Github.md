# 什麼是 git 與 github

幫助理解的優質影片: https://www.youtube.com/watch?v=FKXRiAiQFiY

## 什麼是 Git

Git 是分散式版本控制系統，我個人並不理解 "分散式" 的含意，但是我可以很負責任地告訴你它很好用!

版本控制你可以理解成遊戲的存檔點，當你做出一些不可逆的操作時 (例如使用 rm 指令刪除資料，通常不可逆)，亦或者做一些重大變更 ( 一次性更改1000行程式碼等操作 ) ，都會想要給自己準備類似保險的東西，而在git中我更願意稱之為 "存檔點" 。

1. rm 刪除指令範例
```shell
PS C:\Users\Sakiyago\Desktop\6> ls


    目錄: C:\Users\Sakiyago\Desktop\6


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----      2024/10/25  上午 01:34              0 test.txt


PS C:\Users\Sakiyago\Desktop\6> rm test.txt
PS C:\Users\Sakiyago\Desktop\6> ls
```
順帶一提，通常rm指令不會將你的資料轉移到 "資源回收桶"，沒錯是直接蒸發!

2. 重大邊更範例
![img](https://i.imghippo.com/files/dJrt6744KnQ.jpg)

## 什麼是 github

如果說你已經了解何為 Git 了，想必你也會發現 Git 只能自己一個人使用、存檔。

因此 Github 出現了! 它允許開發者在將代碼上傳到 "倉庫" 中，並且你只需要分享該倉庫的 "連結" ，其他人也可以看的到你的作品 ( 前提是倉庫的權限必須要設為公有 )， 並且以這個倉庫為基礎進行推送與提交，達成遠端協作。

## 想了解更多嗎? 
- [**Git與GitHub教學，認識軟體版本控制系統**](https://tw.alphacamp.co/blog/git-github-version-control-guide)
- [**官方文件**](https://docs.github.com/zh/get-started/start-your-journey/about-github-and-git)
- [**十分鐘短影片**](https://www.youtube.com/watch?v=q4CQBuZ4IGo)

## 本倉庫的Git紀錄

你可以看到 git 前面的紀錄亂掉了! 那是因為缺乏規範!

![img](https://i.imghippo.com/files/zVls9093eQI.jpg)