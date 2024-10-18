execute_chrome_path = r"C:\Users\Sakiyago\Desktop\web_crawer\chrome-win64\chrome.exe" # 替換成你的 chrome 位置
chrome_driver_path = r"C:\Users\Sakiyago\Desktop\web_crawer\chromedriver-win64\chromedriver.exe" # 替換成你的 chromedriver

# 目標網址
target_link = "https://sys.ndhu.edu.tw/gc/sportcenter/SportsFields/Default.aspx"

account = "..." # 在此填入你的帳號
password = "..." # 在此填入你的密碼

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

import time

# Error
class Error(Exception):
    def __init__(self, message):
        super().__init__(message)

# preparation stage

## service
service = Service(executable_path = chrome_driver_path)

## chrome-option
chrome_options = Options()
chrome_options.binary_location = execute_chrome_path

## driver GET target_link
driver = webdriver.Chrome(service=service, options=chrome_options)
driver.get(target_link)

## Wait
wait = WebDriverWait(driver, 15)

# Function

## LogIn part
def LogIn() -> None:
    email = wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#MainContent_TxtUSERNO")))
    email.send_keys(account)
    password_block = wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#MainContent_TxtPWD")))
    password_block.send_keys(password)
    # 按鈕
    wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#MainContent_Button1"))).click()

## select course 
def Select_time():
    # 獲取當前的本地時間
    local_time = time.localtime()
    # 格式化時間為字符串
    local_time = time.strftime('%Y/%m/%d', local_time)
    web_time = wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#MainContent_TextBox1")))
    driver.execute_script(f"arguments[0].value = '{local_time}';", web_time)
    wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#MainContent_Button1"))).click()

def nextDay():
    wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#MainContent_BtnNextD2"))).click()

def get_data(index, d):
    assert (0 <= index <= 16), "錯誤的值"
    container = wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, f"#MainContent_Table1 > tbody > tr:nth-child({3 + index})")))
    inf = container.find_elements(By.TAG_NAME, "td")[1].text
    date_y_m = time.strftime('%Y/%m', time.localtime())
    date_d = int(time.strftime('%d', time.localtime())) + d
    cur_date = f"{date_y_m}/{date_d}"
    for i in range(1,5):
        if f"羽{i}" not in inf:
            print("找到了!", f"羽{i}", cur_date, f"時間 : {index+6}:00")


# Main function
def main():
    try:
        input("開始?")
        LogIn()
        Select_time()
        for d in range(25):
            for i in range(9,16):
                get_data(i, d)
            nextDay()
            time.sleep(0.5)
    except Error as E:
        print(f"捕獲到錯誤 : {E}")


# 模擬程式進入點
if __name__ == "__main__":
    main()

driver.quit()
