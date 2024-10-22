# Cookies 測試

## 目的

幫助明哲 了解 cookies 是如何被轉發的
幫助我記憶程式碼，因為我有時候會忘記...

## 功能簡介

### 技術/概念
使用 http 方法的 Get 操作去請求特定的 url 來取得 cookies

開發語言: node js
使用模塊 ( 目前 ):　"express" 、 "cookie-parser"

### 啟動後端

0. 環境架設: 確保你的電腦中有 [**node 模組**](https://nodejs.org/zh-tw/download/prebuilt-installer)

1. 確保你克隆了程式碼並且進入了資料夾
```shell
cd server
```

2. 安裝必要套件
```shell
npm install
```

3. 啟動後端
```shell
npm run start
```

如果成功，你會得到以下輸出:
```shell
Server listening on   http://localhost:5090
Get unsigned cookies: http://localhost:5090/GetCookieUnSigned
Get signed cookies:   http://localhost:5090/GetCookieSigned
Get all cookies:      http://localhost:5090/LogCookies
```

### 測試
使用 thunder cilent 進行測試，或者使用我晚一點完成的介面，當然這要等。

在終端機中可以找到你要的 url
```shell
Server listening on   http://localhost:5090
Get unsigned cookies: http://localhost:5090/GetCookieUnSigned
Get signed cookies:   http://localhost:5090/GetCookieSigned
Get all cookies:      http://localhost:5090/LogCookies
```
一律使用 get 方法

詳細可以閱讀 api 文件 -> 製作中 ... ( 下次更新 )