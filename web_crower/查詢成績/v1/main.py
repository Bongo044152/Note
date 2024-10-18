'''
2024.10.16 星期三 23:42 pm

背景: 我需要了解一下其他人的狀況...
概念: 使用python 的 selenium 庫 完成網路爬蟲任務
用途: 分析班上的數據

'''

execute_chrome_path = r"C:\Users\Sakiyago\Desktop\web_crawer\chrome-win64\chrome.exe" # 替換成你的 chrome 位置
chrome_driver_path = r"C:\Users\Sakiyago\Desktop\web_crawer\chromedriver-win64\chromedriver.exe" # 替換成你的 chromedriver

# 目標網址
target_link = "http://134.208.3.66/problem/PR113-1-" + input("輸入題號: ")
# target_link = "http://134.208.3.5/problem/Arrays_Problem2"
mode = input("輸入k進入單一查詢模式: ").lower()
if mode == 'k':
    name = input("誰? ")

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
wait = WebDriverWait(driver, 5)

# Function 
def InToPage():
    wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#right-column > div.ivu-card.ivu-card-bordered.ivu-card-dis-hover > div > ul > li"))).click()
def get_rank():
    wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#main > div > div.ivu-card-body > div > div.page > ul > li.ivu-page-next")))
    data = {}  # username : runtime
    driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
    excute_time = driver.find_element(By.CSS_SELECTOR, "#main > div > div.ivu-card-body > div > div.page > ul")
    excute_time = int(excute_time.find_elements(By.CSS_SELECTOR, "li")[-2].text)
    try:
        for _ in range(excute_time):

            time.sleep(0.5)
            # 等待下一页按钮可点击
            next_page_but = wait.until(
                EC.element_to_be_clickable((By.CSS_SELECTOR, '#main > div > div.ivu-card-body > div > div.page > ul > li.ivu-page-next'))
            )
            
            # 等待表格容器可见
            container = wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#main > div > div.ivu-card-body > div > div.ivu-table-wrapper > div > div.ivu-table-body > table > tbody")))
            
            # 获取表格行
            trs = container.find_elements(By.CSS_SELECTOR, "tr")
            for tr in trs:
                # 获取运行时间和用户名
                flag = tr.find_elements(By.CSS_SELECTOR, "td")[2].text
                
                # 更新数据
                if "Accepted" in flag:
                    runtime = int(tr.find_elements(By.CSS_SELECTOR, "td")[4].text[:-2])
                    userName = tr.find_elements(By.CSS_SELECTOR, "td")[7].text
                    if userName in data:
                        data[userName] = min(data[userName], runtime)
                    else:
                        data[userName] = runtime
            
            # 点击下一页
            next_page_but.click()
            driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
    except Exception as e:
        print(e)
        return data
    return data

def get_by_name(name):
    wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#main > div > div.ivu-card-body > div > div.page > ul > li.ivu-page-next")))
    actully = {"錯誤": 0, "正確": 0}  # 錯誤/正確 : 次數
    total_runtime = [] # runtime
    driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
    excute_time = driver.find_element(By.CSS_SELECTOR, "#main > div > div.ivu-card-body > div > div.page > ul")
    excute_time = int(excute_time.find_elements(By.CSS_SELECTOR, "li")[-2].text)
    try:
        for _ in range(excute_time):

            time.sleep(0.5)
            # 等待下一页按钮可点击
            next_page_but = wait.until(
                EC.element_to_be_clickable((By.CSS_SELECTOR, '#main > div > div.ivu-card-body > div > div.page > ul > li.ivu-page-next'))
            )
            
            # 等待表格容器可见
            container = wait.until(EC.visibility_of_element_located((By.CSS_SELECTOR, "#main > div > div.ivu-card-body > div > div.ivu-table-wrapper > div > div.ivu-table-body > table > tbody")))
            
            # 获取表格行
            trs = container.find_elements(By.CSS_SELECTOR, "tr")
            for tr in trs:
                # 获取运行时间和用户名
                flag = tr.find_elements(By.CSS_SELECTOR, "td")[2].text
                
                # 更新数据
                userName = tr.find_elements(By.CSS_SELECTOR, "td")[7].text
                if userName == name:
                    if "Accepted" in flag:
                        actully["正確"] += 1
                        runtime = int(tr.find_elements(By.CSS_SELECTOR, "td")[4].text[:-2])
                        total_runtime.append(runtime)
                    else:
                        actully["錯誤"] += 1
            
            # 点击下一页
            next_page_but.click()
            driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")
    except Exception as e:
        print(e)
        return [actully, total_runtime]
    return [actully, total_runtime]

def filter_by_k(data, k):
    return {key: value for key, value in data.items() if value <= k}
def the_same_generation(data):
    return {key: value for key, value in data.items() if "411321" in key}

# Main function
def main():
    try:
        if mode != "k":
            InToPage()
            data = dict(sorted(get_rank().items(), key=lambda item: item[1]))
            driver.close()

            print("所有人:")
            print(data)
            print(f"目前有{len(data)}人 Accept")
            print()


            k = int(input("查詢幾ms以下 對象:所有人 "))
            temp = filter_by_k(data, k)
            print(f"目前有 {len(temp)}人 {k}ms 以下")
            print(temp)
            print()
            
            print("對於同一屆:")
            temp = the_same_generation(data)
            print(temp)
            print(f"一共{len(temp)}人 Accept")
            print()
            k = int(input("查詢幾ms以下 對象:同一屆 "))
            temp = filter_by_k(temp, k)
            print(f"同一屆有 {len(temp)}人 {k}ms 以下")
            print(temp)
            print()
        else:
            InToPage()
            actully, total_runtime = get_by_name(name)
            print("報告老大! 結果出爐了!")
            print(f"針對使用者{name}的初步調查如下:")
            print(actully)
            print("AC的提交ms (時間由前到後)")
            print(total_runtime[::-1])

    except Error as E:
        print(f"捕獲到錯誤 : {E}")


# 模擬程式進入點
if __name__ == "__main__":
    main()
    driver.quit()