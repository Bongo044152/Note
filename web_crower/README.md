# Web Crawler for Sports Fields Booking

這是一個使用 Selenium 自動化操作的網頁爬蟲，用於查看未被占用的體育場地。

## 特徵

- 每次執行腳本會自動校準時間
- 小幅度的客製化你要查詢的時間範圍

## 配置環境

- [Python](https://www.python.org/downloads/)（建議版本 3.11 以上）
- 下載 [Chrome & ChromeDriver](https://googlechromelabs.github.io/chrome-for-testing/) : 確認你的版本需與 Chrome 瀏覽器相符，如果不相符可以使用 "Chrome for test" 詳細可以參閱 [這篇文章](https://developer.chrome.com/blog/chrome-for-testing?hl=zh-tw) 。

## 1. 配置虛擬環境

請在powershell中使用以下命令
```bash
# 創建虛擬環境
python -m venv venv

# 激活虛擬環境（Windows）
.\.venv\Scripts\Activate.ps1
```

## 2. 安裝依賴包

```bash
pip install selenium
```

## 3. 配置 Chrome 和 ChromeDriver 路徑

在腳本中，將以下變數替換為你的 Chrome 和 ChromeDriver 的實際路徑：

```python
execute_chrome_path = r"C:\Users\Sakiyago\Desktop\web_crawer\chrome-win64\chrome.exe"
chrome_driver_path = r"C:\Users\Sakiyago\Desktop\web_crawer\chromedriver-win64\chromedriver.exe"
```

## 4. 輸入帳號和密碼

在腳本中找到以下行，並填入你的帳號和密碼：

```python
account = "..."  # 在此填入你的帳號
password = "..."  # 在此填入你的密碼
```

## 5. 運行腳本

確保你的虛擬環境仍然處於激活狀態，然後運行腳本：

```bash
python your_script.py
```

【常見問題 - 如何確認虛擬環境處於激活狀態?】

在你的 powershell 中，已經激活的虛擬環境前面應該會有個綠色括弧 `(.venv)`

```shell
(.venv) PS C:\Users\Sakiyago\Desktop\web_crawer\體育館\.venv\Scripts> 
```

## 6. 使用說明

- 程式執行過程中，盡可能地避免人工干預(如最小化頁面等操作)
- 執行的結過會在終端機中輸出訊息

## 其他注意事項

- 在運行腳本之前，請確保網絡連接正常 ( 盡可能使用校內網路訪問，否則有可能出現未知的錯誤，當然這只是一種可能性 )


## 給初學者 ( 明哲 ) 提供的參考學習資料

- 文組也看得懂的 - 網路爬蟲 : https://www.youtube.com/watch?v=BdRjutf8K0c
- Request 簡易教學 ( 女主播 ) : https://www.youtube.com/playlist?list=PL5y2P1AqpsZ8lcW-idM8wfJ2UuscAwrTV
- 講話肏你媽慢的 "彭彭老師" : https://www.youtube.com/watch?v=ff5L6L5MTCw

... ( 懶得找了 ) ...
