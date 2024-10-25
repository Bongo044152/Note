# Node.js 文件系統（fs）模組

Node.js 提供了一個內建的 `fs`（文件系統）模組，用於與文件系統進行交互。這個模組允許你讀取、寫入、更新和刪除文件，並進行許多其他文件操作。

## 介紹

Node.js 是基於事件驅動的架構，是 JavaScript 的執行環境。要運行此代碼，請先確認你已安裝 Node.js。

官方下載路徑: [Node.js 下載](https://nodejs.org/en/download/prebuilt-installer)

`fs` 模組的運行方式是透過“回調”來執行的操作，因此直接使用 `await` 等待它的結果是無效的。`await` 是用來等待 Promise 物件的，而 `fs` 模組提供的函數通常不返回 Promise。

### 解決方法

1. **使用 Promise 進行包裝**：
   ```js
   await new Promise((resolve, reject) => {
       fs.readFile('example.txt', 'utf8', (err, data) => {
           if (err) {
               return reject(err);
           }
           resolve(data);
       });
   });
   ```

2. **直接使用 `fs/promises`**：
   ```js
   const fs = require('fs').promises; // ES5 語法，ES6 使用 import fs from 'fs/promises';

   async function readFileAsync(filePath) {
       try {
           const data = await fs.readFile(filePath, 'utf8');
           console.log(data);
       } catch (err) {
           console.error('Error reading file:', err);
       }
   }
   ```

### 為什麼追求異步操作？

異步操作並不是傳統意義上的多線程實現，雖然它們都涉及到同時執行多個任務。異步操作允許 JavaScript 在等待某些操作（如文件讀取、網絡請求）完成時繼續執行其他代碼，這樣可以提高性能和響應速度。這裡有一個範例：

```js
const file_read = new Promise((resolve, reject) => {
    fs.readFile('example.txt', 'utf8', (err, data) => {
        if (err) {
            return reject(err); // 如果有錯誤，拒絕 Promise
        }
        resolve(data); // 成功時解析 Promise
    });
});

// do your things here ...

// 如果你想要調用資料了!
try {
    const data = await file_read;
    console.log(data);
} catch (err) {
    console.log(err);
}
```

## 總結

普通的 `fs` 模組並不支持 `await` 方法，如果你想要使用 `await`，必須使用返回 Promise 物件的模組，例如 `fs/promises`

## 想知道更多嗎?
https://nodejs.cn/api/fs.html