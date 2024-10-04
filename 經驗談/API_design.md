# API 設計經驗談

**API (Application Promramming Interface) 被設計用來與應用軟體溝通，提供了不同服務、軟體之間的應用通訊，一個好的 API 對於未來的擴建、甚至在部屬應用程式的過程中都可以簡化許多翻閱檔案的次數。**

我之前開發了一個大的框架，發現 API 應用程序溝通上起到一個很大的作用，包括其他服務的調用(google youtube api 、 emailjs) ， 在開發過程中因為我的 api 設計問題導致我後續又重新開始了很多次，因此我今天特別撰寫這篇文章來幫助其他人排雷/記錄這個過程。

下文除了談論到了 api 的撰寫方式之外，其實還談論到了一些前後端的經驗。

## API 相關規範

**程式碼以 `express js` 框架為例子 ( REST API ) ，使用 `javascript` 撰寫**

### 1. 路徑一律添加 /api/YOUR_SERVER

如果你的應用屬於前端應用，那麼加上 /api 可以避免路徑衝突問題。

通常來說提供前後端的機器/伺服器應該會是同一台，除非你想要被 CORS 政策給折磨，當然我也知道很多為服務的框架，他們運行很多實例然後在同一個域名中回應(可以避免 CORS 政策)；但是我想表達的是當我們加上 /api 時可以確定這是一個 aip 服務，而不是前端應用請求 (GET)。

如果路徑發生衝突，你的前端服務器(例如 nginx)會不知道該如何處裡，進而產稱某接錯誤。 為了避免上述狀況發生，建議 api 有關的服務一律加上 /api

### 2. 傳解 API 文件

使用 swagger - openapi 的方式可以幫助其他開發人員 ( 如果有 ) 或者使用者來快速的了解你的服務內容，同時也助於後續的開發

### 3. 規範的訊息傳遞

使用相同的格式傳遞可以減少不必要的人工錯誤，例如前端解析錯誤(錯誤的取值)。

其重點涵蓋以下:
- 規範格式:
```json
{
    "status": "success",
    "data": {
        "id": 123,
        "name": "John Doe",
        "email": "john.doe@example.com"
    },
    "message": "Request processed successfully.",
    "code": 200
}
```
```json
{
    "status": "error",
    "message": "Invalid request.",
    "code": 400,
    "errors": {
        "field": "Email is required."
    }
}
```
- 規範資料型態
```js
res.status(200).json(...) // 使用 .json 可以避免前端再額外花時間進行解析
```

### 4. API 版本
如果有必要，應該在你的URL之中指定你所需要使用的版本

### 5. 授權與認證

有些服務需要驗證 ( 例如如何區分付費用戶與免費用戶 ) ， 可以使用 token (jwt) 或者 sessionId 等方式進行驗證，又或者 OAuth 2.0 第三方認證 (當然第三方認證通常都要用錢)

為了避免重複註冊，你可以使用 email驗證 避免使用者重複註冊等問題

## 開發規範

### 1. API 中不應該傳輸使用者訊息，服務與服務之間應該屬於 "無狀態"

### 2. 驗證方式一律以 cookies 或者 http headrer 內進行驗證

### 3. 開發前應該搜尋足夠的資料

至少要看足夠多的文章，知道這份專案後續的進行，其中包括:
0. **查閱足夠多個文章，確保專案的可實現性以及如何實現 【重要!!!】**
1. 撰寫更新日誌 - 用以確定更新
2. 撰寫系統日誌 - 用以查看捕獲錯誤訊息 (例如api錯誤)
```json
{
    "timestamp": "2024-10-04T12:34:56Z",   // 日誌生成的時間
    "level": "INFO",                       // 日誌級別，例如 DEBUG, INFO, WARN, ERROR
    "service": "user-service",             // 服務名稱
    "version": "1.0.0",                    // 服務版本
    "message": "User created successfully", // 日誌消息
    "userId": 12345,                       // 相關用戶 ID
    "requestId": "abc-123",                // 請求 ID，用於追蹤請求
    "duration": 150,                       // 請求處理時間（毫秒）
    "error": null                          // 錯誤信息（如有）
}
```
3. 撰寫框架 - 後端的配置架構 ( 例如微服務、網路配置、系統配置等 )
4. Readme 文件 - 讓更多人了解你的企劃

### 4. 系統穩定與版本控制

在部屬與測試時，配置運行環境與相關配件的版本總是特別的煩人；程式碼需要大規模的更改、追蹤除了依靠前面說到的 "更新日誌" 之外，其實還遠遠的不夠。

1. 使用 git 版本控制系統 : 我相信作為一名開發者，利用 git 追蹤版本以及利用 github 來實現遠端儲存/協同開發 已經是家常便飯，這邊不多作介紹。
2. 使用 `yarn.lock` 來正確的鎖定實際安裝的版本 : 雖然使用 `package.json` 已經足以應對大多數的情況，但是我還是有看到其他人這麼做。
3. 使用 docker 可以幫助你解決開發環境的問題，並且快速的部屬你的應用；透過 docker 也可以實現微服務的運行方式。

### 5. 個資保護

在撰寫程式碼的過程中，不必要的資訊不應該推送到遠端倉庫，例如 api 金鑰等敏感資訊。

反之，應該儲存在環境變量當中，例如 `.env` 文件或者本地環境變量，並未你的應用添加合適的`.gitignore`文件。

### 6. 本地測試與遠端測試

程式語言中通常會包括某些實用的庫可以幫助測試，例如 JUnit for Java 、 PyTest for Python 、 Mocha for JavaScript

這些實用的工具都可以快速地幫你測試應用程式是否有漏洞

範例由 GPT 傳寫
```js
// test/api.test.js
const assert = require('assert');
const request = require('supertest'); // 用於發送 HTTP 請求

const app = require('../app'); // 你的 API 應用程式

describe('API Tests', () => {
    it('should return a list of users', (done) => {
        request(app)
            .get('/api/users') // 替換為你的 API 路徑
            .expect('Content-Type', /json/)
            .expect(200)
            .end((err, res) => {
                if (err) return done(err);
                assert(Array.isArray(res.body), 'Response should be an array');
                done();
            });
    });

    it('should return user details', (done) => {
        request(app)
            .get('/api/users/1') // 替換為你的 API 路徑
            .expect('Content-Type', /json/)
            .expect(200)
            .end((err, res) => {
                if (err) return done(err);
                assert.equal(res.body.id, 1); // 假設返回的用戶 ID 為 1
                done();
            });
    });
});
```

當然僅此依然不夠，因為實際的開發會面臨很多問題，例如瀏覽器緩存策略、瀏覽器的 CORS 政策等，都要一個一個測試，從本地到遠端。

或者使用 "端對端測試" 當然那都是後話了 ( 我還沒掌握 )。

### 7. 防禦措施

雖然大部分的人都挺友善，但是也要注意小部分的惡意行為
1. 流量限制 : 這應該不屬於防禦規範，但是建議加上會比較好(對伺服器友善)
2. 基本資安防護 : 包括防禦基本的攻擊，例如 CSRF；在後端都要進行相關的設定與防範
3. 網路防護 : 包括開啟必要的端口、減少某些敏感的 服務、操作 暴露在公有網路之下；其最佳的實踐方式應該在私有網路中進行，或者使用 vpn 來進行虛擬私有網路合併。

### 8. 程式碼撰寫規定

好的程式碼格式可降低你的很多閱讀、理解時間，好的錯誤輸出也可以快速地幫助你debug

javascript 通常不會很明確地指出問題在哪一條程式碼、哪一個部分，因此可以在捕獲異常那邊添加必要的資訊。

總結 : 
1. 程式撰寫規範 ( 後端API ) 我推薦使用 MVC 架構
2. 常用的工具/函式可以放在專門的資料夾 ( /tools )
3. 錯誤的捕獲與處裡可以克制化添加更多詳細內容

## 小結

良好的 API 設計是建立可擴展、可維護且使用者友好的應用程式的基礎。當然，開發策略和系統日誌的設計也會使後續維護更加便利。透過遵循這些原則和最佳實踐，您可以打造不僅實用而且使用起來令人愉悅的 API。從基礎開始，專注於一致性和簡單性，隨著 API 的發展，逐步融入進階功能。

精心設計的 API 旨在讓開發者的生活更輕鬆，使他們能夠以最小的摩擦建立強大的應用程式。在這個過程中，持續學習、迭代和提升您的 API 設計技能至關重要。

我知道還有許多我尚未掌握的實踐方式，可以讓整個服務變得更加完善。例如，使用集中式日誌管理系統（如 ELK Stack 或 Splunk）和一些性能優化策略（如 HTTP Cache Headers 和 Redis）將有助於提高整體反應速度和系統穩定性。

讓我們一步一步來，等我下次開發時，在學更多知識並且撰寫文章分享。

## 參考資料

- https://medium.com/dev-genius/api-design-from-basics-to-best-practices-49bbb29cf696

## 作者

張宸瑋 - 2024.10.5 00:32 撰寫