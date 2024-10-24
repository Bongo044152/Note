# 安裝並使用 Git

## 如何安狀 Git

如果有需要，可以參考影片前半段: https://www.youtube.com/watch?v=FKXRiAiQFiY (註記: 很難有人講得比他更好了，這個人超噁心)

1. 進入到官網下載連結: https://git-scm.com/downloads
2. 安裝完成後，確認是否安裝成功/可執行，以下是在windows的範例:

```shell
PS C:\Users\Sakiyago> git --version
git version 2.46.0.windows.1
```
> 註記: 如果你沒有得到類似這種輸出，以下步驟可能可以幫你解決問題:
    1. 重新啟動終端機
    2. 重新啟動你的電腦
    3. 重新安裝 (最後手段)
    4. 手動配置環境變數
    5. 上網求救 (我也沒招了...)

3. 進行初配置
```shell
PS C:\Users\Sakiyago> git config --global uesr.name "UOUR_NAME"
PS C:\Users\Sakiyago> git config --global uesr.email "UOUR_EMAIL"
```

到這邊都順利的話就結束喽!

## 額外補充

在你的桌面中，點選右鍵(如果是win11還要再點選"顯示其他選項")可以看到 "Open git branch here" ，這是 git 所提供的終端機，你可以在這邊學習 lunix 指令

- "Open git bash here"

![img](https://i.imghippo.com/files/fSbP9564TK.jpg)

- 一個簡單的 lunix 指令 -> 透過 git bash 執行
```bash
Sakiyago@MSI MINGW64 ~/Desktop
$ cd osu\!

Sakiyago@MSI MINGW64 ~/Desktop/osu!
$ ls
 Data/                avutil-49.dll*       'osu!.exe'*
 Downloads/           bass.dll*            'osu!auth.dll'*
 Localisation/        bass_fx.dll*         'osu!gameplay.dll'*
 Logs/                collection.db        'osu!seasonal.dll'*
 Microsoft.Ink.dll*   d3dcompiler_47.dll*  'osu!ui.dll'*
 OpenTK.dll*          libEGL.dll*           presence.db
 Skins/               libGLESv2.dll*        pthreadGC2.dll*
 Songs/              'osu!.Sakiyago.cfg'   'repair osu!.lnk'*
 avcodec-51.dll*     'osu!.cfg'             scores.db
 avformat-52.dll*    'osu!.db'
```

### .git 資料夾

當你初始化資料夾時，會生成 .git 資料夾，預設是不可見，除非你使用特殊指令或者方法。

.git 資料夾沒事不要動它! 那是 git 在處裡、互動的資料夾，裡面會有你的提交紀錄之類的..

1. 透過lunix指令顯示 .git
```bash
bongo@MSI:/mnt/c/Users/Sakiyago/Desktop/5/test$ ls -la
total 0
drwxrwxrwx 1 bongo bongo 512 Oct 24 23:48 .
drwxrwxrwx 1 bongo bongo 512 Oct 24 23:31 ..
drwxrwxrwx 1 bongo bongo 512 Oct 24 23:49 .git
-rwxrwxrwx 1 bongo bongo   2 Oct 24 23:49 cat.txt
-rwxrwxrwx 1 bongo bongo   0 Oct 24 23:31 dog.txt
-rwxrwxrwx 1 bongo bongo   0 Oct 24 23:31 good.txt
```
2. 透過檔案總管看到它
![img](https://i.imghippo.com/files/GRu7296izo.jpg)

## 使用 Git

### Git 常見指令整理

我叫 GPT 整理一些常用的 Git 指令，方便參與者快速查找和使用。

#### 1. 基本指令

- **初始化儲存庫**
  ```bash
  git init
  ```

- **克隆儲存庫**
  ```bash
  git clone <repository_url>
  ```

- **檢查當前狀態**
  ```bash
  git status # 有 vscode 可以不用記這個，會直接顯示
  ```

- **添加變更至暫存區**
  ```bash
  git add <file_or_directory> # 有 vscode 可以不用記這個，有介面工具
  ```

- **提交變更**
  ```bash
  git commit -m "你的提交信息" # 有 vscode 可以不用記這個，有介面工具
  ```

- **查看提交歷史**
  ```bash
  git log # 通常搭配 --graph --oneline --all ， 這個如果不知道要記
  ```

#### 2. 分支操作

- **創建新分支**
  ```bash
  git branch <branch_name>
  ```

- **切換分支**
  ```bash
  git checkout <branch_name> # git checkout -d my_branch -> 創建分支並且移動到該分支
  ```

- **合併分支**
  ```bash
  git merge <branch_name>
  ```

- **刪除分支**
  ```bash
  git branch -d <branch_name> # 強制刪除用 -D
  ```

#### 3. 遠端操作

- **查看遠端儲存庫**
  ```bash
  git remote -v
  ```

- **添加遠端儲存庫**
  ```bash
  git remote add <name> <repository_url> # 遠端可以有多個，但是操作會更複雜
  ```

- **推送變更至遠端**
  ```bash
  git push <remote_name> <branch_name> # 通常是 origin main，除非你想搞特殊
  ```

- **拉取遠端變更**
  ```bash
  git pull <remote_name> <branch_name>
  ```

#### 4. 其他常用指令

- **查看變更**
  ```bash
  git diff # 有 vscode 可以不用記這個，有介面工具
  ```

- **回退到先前的提交**
  ```bash
  # 這個命令必須知道! 
  # 通常是 git reset ID -> 混用模式
  # --hard 是重大手段! 直接強制覆蓋
  # --soft 比較鳥，自己感受
  git reset --hard <commit_id>
  ```

- **標記版本**
  ```bash
        # 我從來沒用過 ...
  git tag <tag_name>
  ```

- **顯示當前分支**
  ```bash
  git branch
  ```

#### 5. 常見問題解答

- **如何解決合併衝突？**
  - 編輯有衝突的文件，手動解決衝突後使用 `git add` 添加，然後提交。

- **如何查看某個文件的歷史變更？**
  ```bash
  git log -- <file_name>
  ```

這些指令涵蓋了 Git 的基本使用，幫助新手和有經驗的使用者快速上手。如果有其他需要補充的指令，可以隨時更新這份文件！

### Git 指令教學
( 依照推薦順序上到下排序 )
1. [**程式與網頁開發者必備技能！Git 和 GitHub 零基礎快速上手，輕鬆掌握版本控制的要訣！**](https://www.youtube.com/watch?v=FKXRiAiQFiY)
2. [**兩小時Git教程**](https://youtube.com/playlist?list=PLDBEQHWAyt9FbN7TANIXlUvtRhdoBCEQ5&feature=shared)

### VsCode 中的設置

如果你有使用 vscode，並且不想背那些超長超麻煩用起來感覺很古老的指令，可以使用 vscode 的 GUI 工具。

1. 安裝插件 GitLens
2. 安裝插件 Git Graph ( 因為GitLens的圖像化要Pro才支援，垃圾! )

介紹影片: https://www.youtube.com/watch?v=oAivN4vabzQ&list=PLDBEQHWAyt9FbN7TANIXlUvtRhdoBCEQ5&index=15

這邊我建議 GitLens 與 Git Graph 一起使用，兩個剛好互補對方沒有的功能!