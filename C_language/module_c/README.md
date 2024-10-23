# **C 語言的模塊封裝**

## **什麼叫 "模塊封裝" ?**

模塊封裝是現代程式設計中一個關鍵的概念，它將程式碼分成獨立的模塊或組件 ( 可以是物件、函數，但是我們今天討論的C語言並不支持物件導向編成 ) 。

每個模塊專注於特定的功能或任務，例如對於 `youtube` 模塊來說主要負責處理 youtube 的所有相關功能，例如 **檔案上傳、檔案下載、查詢等等..** 。

這種方法不僅提升了程式碼的結構性，同時也不需要將一堆代碼塞到同一份文件當中。

首先，模塊化提高了程式碼的 **重用性** 。開發者可以將一個模塊應用於不同的項目中，這樣不僅節省了時間，還降低了開發成本。其次，模塊化增強了程式碼的 **可維護性** 。每個模塊可以獨立進行更新或修復 ( 對於 `youtube` 模塊而言，相同的通能可以有不同的技術、呈現方式，但是在大型開發中，參數盡量不要改變 ) ，這使得整個系統的維護變得更加簡單和高效。

此外，模塊化還改善了程式碼的 **可讀性** 。清晰的模塊結構使得開發者更容易理解和跟踪程式的運行邏輯。最重要的是，模塊之間的 **隔離性** 降低了它們之間的依賴性，這樣一個模塊的改動不會輕易影響其他模塊，從而減少了潛在的錯誤。

透過模塊封裝，程式設計不僅變得更有組織，更能適應快速變化的技術需求，促進了軟體開發的效率和品質。


## **C語言如何完成 "模塊封裝" ?**

C語言的模塊封裝需要透過 "標頭黨" 與 "內部文件" 實現，例如我今天有一個標頭黨 "add.h"，就需要一個 "add.c" 來實現 add.h 的功能 ( 實現標投檔的接口 ) 。

因此 C 語言的模塊封裝需要透過 "大量的編譯" 來實現一份 "可執行文件" 。 所以! 我們需要 "建構工具" 來實現 "大量編譯" 。

## CMake 安裝

- [**官方網站**](https://cmake.org/download/)

```shell
PS C:\Users\Sakiyago> cmake --version
cmake version 3.31.0-rc2

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

## CMAke 命令

現在讓我們講解 CMake 的命令

下面是一個簡單的範例，首先要確定的一點是，你的 CMake 的版本號

```shell
PS C:\Users\Sakiyago\Desktop\Note> cmake --version
cmake version 3.31.0-rc2  # 在這邊得到你的版本號
```

接下來是撰寫 CMake 文件，和 Dockerfile 一樣，名稱叫做 `CMakeList.txt` 而且大小寫都不准錯! 並且只能有一份。

```m
cmake_minimum_required(VERSION 3.31.0-rc2)  # 設定CMake的最低版本

project(main)  # 設定項目名稱和語言為C

add_executable(main main.c)  # 建立可執行檔
```

介紹 **shell** 命令:

1. 創建 build 文件夾，如果你不想要在當前目錄中看到一堆醜爆的文件
```shell
mkdir build
cd build
```

2. 根據 "CMakeList.txt" 創建文件，需要指定 "CMakeList.txt" 的位置
```shell
cmake .. # .. 表示當前 目錄/資料夾 的上一頁，如果你不知道的話 -> 即表示 "CMakeList.txt" 的位置
```

3. 建構可執行檔
```shell
cmake --build . # 記得要在 build 文件中執行
```

### **綜合以上**

1. CMakeList.txt
```m
cmake_minimum_required(VERSION 3.31.0-rc2)  # 設定CMake的最低版本

project(main)  # 設定項目名稱和語言為C

add_executable(main main.c)  # 建立可執行檔
```

2. 執行建構
```shell
PS C:\Users\Sakiyago\Desktop\Note\module_c\little_progect> ls

    Directory: C:\Users\Sakiyago\Desktop\Note\module_c\little_progect

Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a---        2024/10/20 下午 09:29            177 CMakeLists.txt
-a---        2024/10/20 下午 09:13            157 main.c
PS C:\Users\Sakiyago\Desktop\Note\module_c\little_progect> mkdir build

    Directory: C:\Users\Sakiyago\Desktop\Note\module_c\little_progect

Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d----        2024/10/20 下午 09:37                build

PS C:\Users\Sakiyago\Desktop\Note\module_c\little_progect> cd build
PS C:\Users\Sakiyago\Desktop\Note\module_c\little_progect\build> cmake ..       
-- Building for: Visual Studio 17 2022
-- Selecting Windows SDK version 10.0.22000.0 to target Windows 10.0.22631.
-- The C compiler identification is MSVC 19.41.34123.0
-- The CXX compiler identification is MSVC 19.41.34123.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/cl.exe - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.41.34120/bin/Hostx64/x64/cl.exe - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (6.5s)
-- Generating done (0.0s)
-- Build files have been written to: C:/Users/Sakiyago/Desktop/Note/module_c/little_progect/build
PS C:\Users\Sakiyago\Desktop\Note\module_c\little_progect\build> cmake --build .
.NET Framework 的 MSBuild 版本 17.11.9+a69bbaaf5

  1>Checking Build System
  Building Custom Rule C:/Users/Sakiyago/Desktop/Note/module_c/little_progect/CMakeLists.txt
  main.c
  main.vcxproj -> C:\Users\Sakiyago\Desktop\Note\module_c\little_progect\build\Debug\main.exe
  Building Custom Rule C:/Users/Sakiyago/Desktop/Note/module_c/little_progect/CMakeLists.txt
```

3. 更多常見

```m
cmake_minimum_required(VERSION 3.31.0-rc2)

project(main)

# 以便可以找到 hello.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/module)

# 創建靜態庫
add_library(lib_hello STATIC module/hello.c)

# 創建可執行檔
add_executable(${PROJECT_NAME} main.c)

# 這邊是為了找到 good.h
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(lib_good STATIC good.c)

# 進行連接
target_link_libraries(${PROJECT_NAME} lib_hello)
target_link_libraries(${PROJECT_NAME} lib_good)
```

```shell
PS C:\Users\Sakiyago\Desktop\Note\module_c\little_progect\build> cmake --build .
[ 16%] Building C object CMakeFiles/lib_hello.dir/module/hello.c.obj
[ 33%] Linking C static library liblib_hello.a
[ 33%] Built target lib_hello
[ 50%] Building C object CMakeFiles/lib_good.dir/good.c.obj
[ 66%] Linking C static library liblib_good.a
[ 66%] Built target lib_good
[ 83%] Building C object CMakeFiles/main.dir/main.c.obj
[100%] Linking C executable main.exe
[100%] Built target main
PS C:\Users\Sakiyago\Desktop\Note\module_c\little_progect\build> ./main.exe     
Hello World
```

## CMake 教學 / 參考資料

- yt_video : https://www.youtube.com/watch?v=7YcbaupsY8I