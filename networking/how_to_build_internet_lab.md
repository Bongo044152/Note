# **How to Build a Virtual Network Lab for Learning and Testing ?**

在閱讀這篇文章之前，我希望你對於 "網路"、"虛擬機"、"網路運作" 等相關知識有所了解。

## **前言**

俗話說：「百聞不如一見！」學習網路知識也不例外。

網路 (Internet) 是一門既抽象又重要的知識領域，儘管它在我們的日常生活中隨處可見，但因為其「看不見、摸不著」的特性，對初學者來說理解起來比較困難。

這篇文章並非要深入講解網路的原理，而是聚焦於如何建立虛擬網路實驗室，讓你在學習網路時能夠有一個直觀的環境來輔助理解。

## **什麼是模擬器?**

其實模擬器的定義十分廣泛，只要以不同於被模擬端的設備，提供仿真的環境，讓使用者可以去模擬特定的需求，那就可以算是模擬器。舉個例子來說，航空公司會在訓練機師時，使用專業的飛行模擬器，讓訓練中的機師在絕對安全的情況下模擬駕駛，而不用承擔實體飛機墜落的風險。

![飛行模擬器示意圖](https://cdn1.techbang.com/system/images/71526/original/4a457e4029f1893a3c2ffec1e4e905d8.jpg?1326422324)

在資訊領域中，模擬器通常是指使用軟體來重現真實環境中的特定功能或過程，這對於學習或測試非常有幫助，尤其在無法直接使用真實設備的情況下。 ( 因為很貴! 網路設備很貴! 學校似乎支援也挺少 )

---

高品質的網路設備通常價格昂貴，如 "路由器" 、 "交換機" 和 "防火牆" 等。

總結來說，我打算使用 "模擬器" 的方式來搭建網路實驗室，雖然略遜色於實體設備，但也十分夠用。

## **difference betweem "Imitator" ( 模仿器 ) and "Simulator" ( 模擬器 )**

有名的網路模擬環境有:

1. GNS3 (Graphical Network Simulator-3) : 最受歡迎的模擬器之一，以虛擬機作為底層運作設備 ( 大多數人都這麼做 )，來達到幾乎 100% 的完美還原。
    - 優點：支持真實的映像 ( image )，並能夠模擬不同的網路設備。
    - 缺點：需要較高的系統資源，設置過程可能較為複雜。
2. Cisco Packet Tracer : 由 Cisco 提供的模擬器，主要用於學習和測試 Cisco 設備的配置。它是 Cisco 網路學習與認證的官方工具，適用於學習 Cisco 的 CCNA 和其他認證課程。
    - 優點：界面簡單，操作直觀，適合初學者，無需真實設備即可進行學習。
    - 缺點：功能相對有限。
3. Cisco CML (Cisco Modeling Labs) : Cisco 提供的一個虛擬化網路模擬工具，專為網路工程師、開發人員和系統管理員設計，能夠在虛擬環境中創建並測試複雜的網路拓撲。CML 提供真實的 Cisco 設備映像支持，並允許用戶模擬包括路由、交換、無線、SDN 等各種場景。
    - 優點：支持大量真實的 Cisco 設備映像、高度集成的設置、高品質的模擬體驗，適合進行大規模的網路實驗。
    - 缺點：需要購買商業許可證，我剛剛上官網看了一下，需要 199 美元/一年，不可買斷。
    - 註記：就在剛剛，我收到新的資訊，現在提供免費使用! 但是有一些限制...，具體資訊可以查看這一次的採訪 : [Massive News! Free Network Simulation Tool for Everyone! (Cisco CML)](https://www.youtube.com/watch?v=KykMAyJvQ_k)
4. VirL (Cisco Virtual Internet Routing Lab) : 牛逼的代名詞，好像是企業級模擬，總之就牛逼。

( ... 還有挺多 ... )

就我個人的經驗而言，我使用過 "GNS3" 和 "Cisco Packet Tracer"，體驗都很不錯。

現在讓我大致解釋一下這兩個的最主要差異:

1. "Cisco Packet Tracer" 本質上是 "Imitator" ( 模仿 )，而非 "Simulator" ( 模擬 ):

    相較於 gns3 而言，Cisco Packet Tracer 僅針對 cisco 的相關設備支援，功能相當有限，但適用於了解網路還是非常不錯的選擇。
    兩者的主要差異在於 gns3 更實際! 因為 Cisco Packet Tracer 只是 "模仿" 那些網路設備，而 gns3 是基於虛擬化技術來去模擬這些網路。
    我舉幾個簡單的例子:
    1. 當你對某個接口進行時，實際的設備需要經過短暫的內部運行、檢查過後才可以執行，而不是立刻顯示該接口已啟用。
    2. Cisco Packet Tracer 會自動儲存所有的有關設定，而 gns3 要求你需要在指令明確指出這類型的操作步驟。

2. "GNS3" 是基於虛擬機運行的，因此基本上支持所有的功能:

    因為是基於虛擬機運行，除了能夠模擬 cisco 設備外，還可以模擬其他網路設備，甚至是小型的應用程式 ( 使用 docker 進行包裝 )。


> **小總結**

如果你沒有過多個需求，那麼 "Cisco Packet Tracer" 基本上都可以滿足你，但是如果你追求更極致的模擬以及更貼近現實生活的設備運行方式，以及功能更加全面的 cisco 模擬任務， GNS3 我推薦!

- 想了解更多的模擬器: https://www.youtube.com/watch?v=cU4s9Tj_43k

## **簡單的示意圖 - "Cisco Packet Tracer"**

![Cisco Packet Tracer 展示1](https://i.imghippo.com/files/woci3800AI.png)
- 布局掩飾

![Cisco Packet Tracer 展示2](https://i.imghippo.com/files/YBVA8870EUg.png)
- 易於理解的 GUI

![Cisco Packet Tracer 展示3](https://i.imghippo.com/files/hePE6051jw.png)
- 動畫呈現數據的流向
- 可以快進傳輸的過程

![Cisco Packet Tracer 展示4](https://i.imghippo.com/files/rPxn8765HJQ.png)
- 點選查看封包的內容

## **簡單的示意圖 - "GNS3"**

![GNS3 展示1](https://i.imghippo.com/files/zPZ7361gnM.png)
- 基於真實硬體設備與虛擬機技術模擬出來的網路設備

![GNS3 展示2](https://i.imghippo.com/files/PPD4796rUY.png)
- 同一個模式下，支持的功能差距

![GNS3 展示3](https://i.imghippo.com/files/AAB4523lPs.png)
- WhireShirk 抓包分析 ( 如上圖 )

因為沒有 "Cisco Packet Tracer" 內建的動畫工具，因此使用 WhireShirk 進行抓包，又或者使用事件監聽的工具來判斷數據的流向。

---

## **基本聲明🚨**

> **對於 "Cisco Packet Tracer" ，確保你具有以下知識:**
1. 網路基本知識
2. cisco 基本知識，以及指令的運用: 關於這一點，你可以透過 google 或者 youtube 等等學習資源。
    - 我提供我的筆記但是僅作參考，此筆記不是為了教學目的而撰寫更像是備忘錄 : https://colab.research.google.com/drive/1s9ac6DVCRFBStq4r1HRJedUbAIooIv8S?usp=sharing ( 連結不一定永久有效 )
    - 或者詢問 GPT

> **對於 "GNS3" ，請確保你具有以下知識:**
1. 基本網路知識
2. 基本虛擬機認識以及如何架設虛擬機
3. docker
4. 基本網路工具認識 ( WireShark 等 )

初學者建議:

- Cisco Packet Tracer：功能簡單，適合學習網路基礎與 Cisco 設備操作。


進階者建議:

- GNS3：功能全面，支持真實網路拓撲的模擬與測試，適合追求高精度的學習者或專業人員。

## **如何安裝並使用 "Cisco Packet Tracer"**

這裡並不提供完整的教學資源，但是我找了兩個不錯的連結方便入門並且了解。

- Cisco Packet Tracer 介紹: https://www.youtube.com/watch?v=qZB_biPOBwA
- Cisco Packet Tracer 官方下載路徑: https://www.netacad.com/cisco-packet-tracer

## **如何安裝並使用 "GNS3"**

GNS3 的學習曲線十分陡峭，要掌握並不容易 ( 我花了5天研究... )，就結果而言我十分滿意!

由於 GNS3 的配置以及使用方式相對複雜，也是我本次介紹的重點。 我整理了網路上的相關知識，以免踩雷。

### 【如何安裝】
- GNS3 download link : https://gns3.com/
- GNS3 installation tutorial: https://www.youtube.com/watch?v=Ibe3hgP8gCA&list=PLhfrWIlLOoKNFP_e5xcx5e2GDJIgk3ep6

> 安裝是一個簡單的步驟， GNS3 之所以強大主要依賴於虛擬機的功能，可以快速的啟動、最大程度的客製化你想要的網路拓鋪。 GNS3 資深使用者 ( 或者你也可以認為開發人員之一 ) 也強烈建議使用 "虛擬機" 來與 GNS3 進行互動，具體內容會在下面提到。

### 【GNS3 + 虛擬機】

- GNS3 Install ( VMware Workstation Pro ): https://www.youtube.com/watch?v=A0DEnMi09LY&list=PLhfrWIlLOoKNFP_e5xcx5e2GDJIgk3ep6&index=2

雖然影片中提到 VMware Workstation Pro 需要付費，並且只有幾天的適用時間。但是經過我的查詢，目前 VMware Workstation Pro 已經免費提供給個人用戶，您可以直接下載並開始使用。

根據社群上的討論，vmware 有經過[收購風波](https://www.ithome.com.tw/news/160441)，對於 VMware Workstation Pro 因為該收購公司 ( Broadcom ) 過去在收購其他公司後往往會專注於成本削減、減少研發投入等，許多用戶認為這些產品可能不會像過去那樣的持續投入與創新，因此某些人看不起 vmware 。

或許是因為風評之類的影響到了股票啥的(我不是很懂..)，總之近期11月的[官方聲明](https://blogs.vmware.com/workstation/2024/05/vmware-workstation-pro-now-available-free-for-personal-use.html)指出，個人使用的 "VMware Workstation Pro" 直接 <font color="yellow">**免費!**</font> 因此現在我們完全不需要顧慮付費的問題。

我個人認為 VirtualBox 的地位或許會受到些許影響，畢竟虛擬機 "免費" 的很少.. 而且 vmware 的介面比 VirtualBox 好看、簡潔很多，效能也更加。

總結一下: vmware 現在是免費狀態，相較於其他虛擬機，vmware 與 gns3 的互動最佳! 根據 gpt 所述，他的 kvm ( 巢狀模擬，也就是 gns3 所依賴的關鍵技術 ) 做得很不錯! 我也在我的電腦中使用過 VirtualBox ，但是不知道為什麼遲遲都沒有連線到...。

> **如果你打算使用 VirtualBox ， 可以參考以下資訊:**
- [How to Install GNS3 VM in Virtual Box Step by Step | Linking GNS3 VM with GNS3.](https://www.youtube.com/watch?v=DdohIT07hNY)
    - 指令複製 : ( for powershell )
        ```powershell
        cd "C:\Program Files\Oracle\VirtualBox"
        ./VBoxManage modifyvm "GNS3 VM" --nested-hw-virt on
        ```

> 如果你打算使用 VMware Workstation Pro ， 並且上面的 GNS32 Install 沒有幫助到你，我這裡有額外的影片:
- [Virtualized Intel VT-x/EPT is not supported on this platform. FIXED!!!!!](https://www.youtube.com/watch?v=ABK5dC1bWfA)
    - 我在這裡註解一下，有些人的電腦有 hyper-v 或者其他裝置佔用了虛擬化的資源，需要關掉!

### 【如何在 GNS3 中使用其他設備】
- 土豪選項 ( 直接購買 ) : https://www.youtube.com/watch?v=jhh2_PP9JLU&list=PLhfrWIlLOoKNFP_e5xcx5e2GDJIgk3ep6&index=3

- 窮人選項 : 如果你對於 iourc.txt 有所了解，並且在 [GNS3 General FAQ](https://docs.gns3.com/docs/troubleshooting-faq/general-faq/)似乎也有官方的回應敲定了這個事實，當然這一切都是建立在 "合法" 的前提下。

cisco 公司的系統比較封閉，因此他會希望你使用 199$ ( 美元 ) 來購買 images 以及 lience ，使用 "官方" 的資源以及管道來合法的使用他們的產品 ( 這邊指的是 [sofeware support](https://software.cisco.com/download/home) ) 。 但是想要叫我支付 199美元 簡直是癡心妄想! 我翻找了很多文獻試圖繞過這些限制，讓我們這些骯髒的使用者可以免費的使用 cisco!

- [Get IOU Licence Key Free for GNS3 Tamil❗](https://www.youtube.com/watch?v=sfOAWf-jcGw)
    - 指令複製:
        ```bash
        sudo apt-get update
        sudo apt-get install python
        wget http://www.ipvanquish.com/download/CiscoIOUKeygen3f.py
        python3 CiscoIOUKeygen3f.py
        ```
    - GitHub 連結 ( 用於索取免費的資源，當然其他地方也有，自己找 ): https://github.com/hegdepavankumar/Cisco-Images-for-GNS3-and-EVE-NG?tab=readme-ov-file


### 【意外處理】
- 嘿! 我的防火牆阻礙了 GNS3 的啟用! [GNS3 is broken! What do I do? Troubleshooting GNS3 installation issues Windows 10 (Part 3)](https://www.youtube.com/watch?v=-pwuIkdZ3Cc&list=PLhfrWIlLOoKNFP_e5xcx5e2GDJIgk3ep6&index=6)

### 【常見問題】
- GNS3 FAQs : https://gns3.com/code-of-conduct-amp-gns3-faq
- GNS3 General FAQ : https://docs.gns3.com/docs/troubleshooting-faq/general-faq/

### 【官方文獻】
- GNS3 official documention : https://docs.gns3.com/docs/

### 【GNS3 with wireshark】
- [5- | Capture Packets using wireshark in GNS3 ? | Use of Wireshark ? | monitoring network Activity ?](https://www.youtube.com/watch?v=MPlsUMC_3_M)
- [GNS3 Lab Setup: Network Packet Analysis Simulation with Wireshark,Kali Linux,Cisco Router](https://www.youtube.com/watch?v=cmHvC20xL_I)

### 【GNS3 with Docker】
- [GNS3 Talks: How to import Docker containers into GNS3: your own or others available on Docker Hub.](https://www.youtube.com/watch?v=06wQQN1eXcs)

### 【GNS3 to network】
- [GNS3 Talks: Use the NAT node to connect GNS3 to the Internet easily!](https://www.youtube.com/watch?v=2zeoC2Q4mW0)
- [Getting Internet in GNS3 using a Cisco Router: NAT Overloading](https://www.youtube.com/watch?v=DlHAQwvMgAE)

## **參考資料**

- **[什麼是模擬器?](https://www.techbang.com/posts/8141-adv90-cover-story-playing-from-scratch-simulator)**

## **結語**

GNS3 支持多種工具，並具有高度可定制性，甚至你可以在這裡面測試你的應用程式 ( 這裡指的是網路應用程式 ) ，因為 docker 的加入賦予了無限的可能。

由於 GNS3 的學習曲線較為陡峭，建議初學者先從 Cisco Packet Tracer 開始，等到有更多需求時再轉向 GNS3。我希望這篇文章能幫助有興趣建立網路實驗室的人。

-- 2025.1.12 作者 : 張宸瑋