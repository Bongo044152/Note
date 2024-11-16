# Chapter 2 : Review Of Underlying Network Technologies

## Two Approaches To Network Communication

書中提到，網路基本上分為兩種連線/通信方式:

> **Whether they provide connections between one computer and another or between a terminal and a computer, communication networks can be divided into two basic types: connection-oriented (sometimes called circuit-switched) and connectionless (sometimes called packet-switched?).**

### 1. **Connection-oriented（面向連接）** : Connection-oriented networks operate by forming a dedicated connection or circuit between two points.

早期的美國電話系統，使用 Connection-oriented :
1. 由撥出電話 ( 暫時稱為 電話A ) 建立一個連線，經由某個機構 ( 書中稱呼為: "local switching office" )。
2. 經過 "trunk lines"，可以理解為被彙整過的資料流。
3. 經過 接收方( 暫時稱為 電話B ) 所在地的某個機構 ( remote switching office )
4. 最後傳遞到 電話B

> **The U.S. telephone system uses a connection-oriented technology - a telephone call establishes a connection from the originating phone through the local switching office, across trunk lines, to a remote switching office, and finally to the destination telephone.**

這種經由 "專用線路" 的方式其優點在於 "在通訊的過程中，不會有其他的網路活動干擾到你" 。

但同時，缺點也很明顯 -> 當你沒有在使用該服務時，依然會向你索取固定費用。 舉例:"既使雙方都沒有說話，電話費依然會計" 。

> **The advantage of connection-oriented networking lies in its guaranteed capacity: once a circuit is established, no other network activity will decrease the capacity of that circuit. One disadvantage of connection-oriented technology arises from cost: circuit costs are fixed, independent of use. For example, one pays a fixed rate for a phone call, even when the two parties do not talk.**

### 2. **Connectionless（無連接）** : The type often used to connect computers. Data to be transferred across a network is divided into small pieces called packets that are multiplexed onto high capacity intermachine connections.

書中對於 packet 的解釋 :
> **A packet, which usually contains only a few hundred bytes of data, carries identification that enables the network hardware to know how to send it to the specified destination. For example, a large file to be transmitted between two machines must be broken into many packets that are sent across the network one at a time. The network hardware delivers the packets to the specified destination, where software reassembles them into a single file again.**

網路上喜歡用 "郵政系統" 來當作例子，在信上你會註記寄信人與收信人。 信件寄出之後，並沒有一條固定的路線會抵達目的地。

對於這種連線/通信方式，其好處是許多台設備可以同時進行通訊 ( 例如許多人可以同時寄信 )，而懷處也很明顯: "如果有許多設備同時發送請求，會對網路造成負擔" 。

> **The network hardware delivers the packets to the specified destination, where software reassembles them into a single file again. The chief advantage of packetswitching is that multiple communications among computers can proceed concurrently, with intermachine connections shared by all pairs of computers that are communicating. The disadvantage, of course, is that as activity increases, a given pair of communicating computers receives less of the network capacity. That is, whenever a packet switched network becomes overloaded, computers using the network must wait before they can send additional packets.**

現今網路對於網路壅擠有相應的應對方式，就我的理解 IPv4頭部 有一個欄位專門記錄網路的壅塞情況。

Explicit Congestion Notification (ECN): 2 bits<br>
&nbsp;&nbsp;&nbsp;&nbsp;This field allows end-to-end notification of network congestion without dropping packets.<br>
&nbsp;&nbsp;&nbsp;&nbsp;ECN is an optional feature available when both endpoints support it and effective when also supported by the underlying network. ( 內容來自維基百科：https://en.wikipedia.org/wiki/IPv4 )

### 現今的廣義定義

對於 Connection-Oriented 與 Connection-less ，我認為書中寫得有點拘束: ( 以下內容參考自 : https://www.geeksforgeeks.org/difference-between-connection-oriented-and-connection-less-services/ )

Connection-Oriented service 意旨建立一個 "穩定的連線" ，例如 TCP 的握手就是確認這件事情。

![img](https://media.geeksforgeeks.org/wp-content/uploads/20190519204240/Untitled-Diagram-217.png)

對於 Connection-less service 雙方並沒有建立連線或者終止，封包並不會依照特定的路線抵達，UDP 就屬於此類型。

![img](https://media.geeksforgeeks.org/wp-content/uploads/20190519204308/Untitled-Diagram-221.png)

| **連接導向服務 (Connection-oriented Service)** | **無連接服務 (Connection-less Service)** |
|--------------------------------------------|----------------------------------------|
| 連接導向服務與電話系統相關。                         | 無連接服務與郵政系統相關。                        |
| 連接導向服務適用於長時間且穩定的通信。                 | 無連接服務適用於突發性（bursty）的通信。              |
| 連接導向服務是必要的。                            | 無連接服務不是必須的。                            |
| 連接導向服務是可行的。                            | 無連接服務在某些情況下可能不可行。                    |
| 在連接導向服務中，不會發生擁塞。                    | 在無連接服務中，可能會發生擁塞。                      |
| 連接導向服務保證可靠性。                           | 無連接服務不保證可靠性。                           |
| 在連接導向服務中，數據包遵循相同的路由。              | 在無連接服務中，數據包不一定遵循相同的路由。           |
| 連接導向服務需要較高範圍的帶寬。                     | 無連接服務需要較低範圍的帶寬。                        |
| 例如：TCP（傳輸控制協定）                        | 例如：UDP（用戶資料報文協定）                         |
| 連接導向服務需要身份驗證。                         | 無連接服務不需要身份驗證。                          |

---

## Ethernet Technology

### **什麼是 Ethernet ?**

> **Ethemet is the name given to a popular packet-switched LAN technology invented at Xerox PARC in the early 1970s.**

- 乙太網路（英語：Ethernet）是一種電腦區域網路技術。IEEE組織的IEEE 802.3標準制定了乙太網路的技術標準，它規定了包括實體層的連線、電子訊號和媒介訪問控制的內容。乙太網路是目前應用最普遍的區域網路技術，取代了其他區域網路標準如權杖環、FDDI和ARCNET。 ( 資料來自:https://zh.wikipedia.org/zh-tw/%E4%BB%A5%E5%A4%AA%E7%BD%91 )

### **Ethernet 的發展**

#### 1. 10Base5 : 最早實現 10 Mbit/s 的傳輸速度，使用 "coaxial cable" ( 同軸電纜 ) 作為物理傳輸線。 半徑大約 0.5 inch 最長可以傳輸 500 公尺遠。

為了避免電磁場等干擾，在線路內部中包裹了 金屬保護膜 ，也因此這種線不易於彎折。

![img - A cross-section of the coaxial cable used in the original Ethernet](https://i.imghippo.com/files/mr7602Fy.jpg)
- 圖片來自於書本

要和電腦互相連線，需要一個物理設備叫做 "transceiver" 。
transceiver 是一個小塊的硬體通常直接安裝在物理線路上 (直接與乙太網路線相接) ，如下圖。

![img - transceiver with ethernet network line](https://i.imghippo.com/files/WZ1444Vc.jpg)
- 圖片來自書本

> **A transceiver is a small piece of hardware usually found physically adjacent to the ether. In addition to the analog hardware that senses and controls electrical signals on the ether, a transceiver contains digital circuitry that allows it to communicate with a digital computer.**

除此之外， transceiver 還會檢測乙太網是否被使用，以及將類比的電信號(電信號是連續的)轉換成數字信號 :
> **The transceiver senses when the ether is in use and translates analog electrical signals on the ether to (and from) digital fornl.**

在 transceiver 與 computer 之間，使用 AUI 作為介面街口 (即表示連接 NIC/網路卡 與 transceiver 的插頭)。

![img - a connection between a computer's bus and an Ethernet in the original scheme](https://i.imghippo.com/files/Xh9243FQ.jpg)
![img - a view of ethernet connection in office environment](https://i.imghippo.com/files/pnYB7145dc.jpg)
- 兩張圖片皆來自書本

![img - 現實生活中的 10Base5 樣式](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjuRlZawBisxgfIe2TqFk_8aSplWxTVoPpKnBbzjwNl_X3CRk822qmIXSSKq2LP5VmPLHbMJPiOWviJzaRezNr7DeA9eUu6i4zCqEBy08G6bbhULGutYrOTxsLsYls74Du-8LoWY38mkZgb/w640-h422/10base5.png)
- 圖片來源 : https://www.networkurge.com/2017/10/10base5.html

#### 2. Thin-Wire Ethernet -> 10Bace2

前面提到 10Base5 的設計缺點 : 在網路線內部加上金屬膜包裹導致其不易彎折。

除了這一點之外，使用 transceiver 作為連接，也是一筆不小的開銷。

> **Several components of the original Ethernet technology have undesirable properties. For example, because a transceiver contains electronic components, it has a nontrivial cost. Furthermore, because transceivers are located with the cable and not with computers, locating or replacing them is difficult. The coaxial cable that fornls the ether is difficult to install. In particular, to provide maximum protection against electrical interference from devices like electric motors, the cable contains heavy shielding that makes it difficult to bend. Finally, the AUI cable is also thick and difficult to bend.**

在辦公環境中，實際上電磁干擾不可能如此的巨大! 因此工程師們又開發了一個新的方案: 10Base2，即去除/或者降低金屬膜的厚度，使其變得更加有彈性(我認為是指更容易彎折)之外，由於去除了 transcever 的設計也使得其價格變得更加低廉。

其缺點也很明顯，因為設計的關係其傳輸距離變得更短 ( 根據 [維基百科](https://zh.wikipedia.org/zh-tw/%E4%BB%A5%E5%A4%AA%E7%BD%91#10Mbps%E4%B9%99%E5%A4%AA%E7%B6%B2 ) 提供，距離縮短到了最大200公尺實際可能185公尺的傳輸距離，而原本的10Base5方案最大傳輸距離是500公尺 )，連接的電腦個數也變少了。

> **To reduce costs for environments like offices that do not contain much electrical interference, engineers developed an alternative Ethernet wiring scheme. Fornlally known as lOBase2 and usually called thin-wire Ethemt or thinnett, the alternative coaxial cable is thinner, less expensive, and more flexible. However, thin-wire Etherne has some disadvantages. Because it does not provide as much protection from electrical interference, thin-wire Ethernet cannot be placed adjacent to powerful electrical equipment like that found in a factory. Furthermore, thin-wire Ethernet covers somewhat shorter distances and supports fewer computer connections per network than thick Ethernet.**

除了去除了 transceiver 之外，連接方式也有所改變: 需要通過電腦連接電腦的方式，如圖:

![img - view of thin-wire ethernet connection](https://i.imghippo.com/files/mdv2472UWs.jpg)
- 圖片來自書本

> **Manufacturers of small computers and workstations find thin-wire Ethernet an especially attractive scheme because they can integrate Ethernet hardware into single board computers and mount connectors directly on the back of the computer.<br>Because a thin-wire Ethernet connects directly from one computer to another, the wiring scheme works well when many computers occupy a single room. The thin-wire cable runs directly from one computer to the next. To add a new computer, one only needs to link it into the chain**

#### 3. Twisted Pair Ethernet -> 10BaseT ( IEEE 標準名稱為: IEEE 802.3 )

得益於科技的發展，電磁場干擾不再需要透過 金屬膜的包裹 來將其杜絕，而是採用 twisted pair ( 雙膠線 ) 的方式。 因此從 10BaseT 之後，基本上使用金屬膜的方式慢慢的變少 (不是說沒有，而是不常見) 。

即使 10Base2 已經改善了很多 10Base5 的缺點，但是透過 "電腦連接電腦" 的方式有一個致命傷:
- 在 10Base2 中，其中一台電腦關機或者出現意外，則網路癱瘓。
並且 10BaseT 使用 雙膠線 與 銅芯 傳導更進一步的壓低成本。

> **Advances in technology have made it possible to build Ethernets that do not need the electrical shielding of a coaxial cable. Called twisted pair Ethernet, the technology allows a computer to access an Ethernet using conventional unshielded copper wires similar to the wires used to connect telephones?. The advantages of using twisted pair wiring are that it further reduces costs and protects other computers on the network from a user who disconnects a single computer. In some cases, a twisted pair technology can make it possible for an organization to use Ethernet over existing wiring; in others, the needed wiring (called category 5 cable) is cheaper and easier to install than coaxial cable.**

10BaseT 表示最大傳輸速率為 10Mbps ， Base 表示 "基帶傳輸" ，T表示使用雙膠線( Twisted Pair )。

![img - 10BaseT with hub: network topology](https://i.imghippo.com/files/vfiK8278XdI.jpg)
- 圖片來自書本

> **The hub is an electronic device that simulates the signals on an Ethernet cable. Physically, a hub consists of a small box that usually resides in a wiring closet; a connection between a hub and a computer must be less than 100 meters long. A hub requires power, and can allow authorized personnel to monitor and control its operation over the network. To the host interface in a computer, a connection to a hub appears to operate the same way as a connection to a transceiver. That is, an Ethernet hub provides the same communication capability as a thick or thin Ethernet; hubs merely offer an alternative wiring scheme.**

#### 4. 網路傳輸速率概念澄清

這本書的作者有提到所謂的 10Mbps 表示網路的 "帶寬量" ( the capacity of the network ) 而非實際上兩台電腦交換數據的速度。

應該將 10Mpbs 表示為 每秒最多能夠容納多少數據，可以類比為"馬路"。

- 10Mpbs 表示這條馬路的寬度，馬路越寬車流量也可以相對較大。
- 100Mbps 表示更寬的馬路，即表示可以一次性傳遞更多的流量。

我認為這是合理的解釋，因為從物理的角度上看都是使用 "電" 作為傳輸的媒介，速率按理來說也要相同。

> **Although the wiring scheme evolved from the original thick cable to thin cable and finally to twisted pair, much of the original Ethernet design remained the same. In particular, the initial twisted pair Ethernet design operates at the same rate as the original thick Ethernet, which means that data can be transmitted at 10 million bits per second. Although a computer can generate data at Ethernet speed, raw network speed should not be thought of as the rate at which two computers can exchange data. Instead, network speed should be thought of as a measure of total traffic capacity. Think of a network as a highway connecting multiple cities, and think of packets as cars on the highway. High bandwidth makes it possible to carry heavy traffic loads, while low bandwidth means the highway cannot carry as much traffic. A 10 Mbps Ethernet, for example, can handle a few computers that generate heavy loads, or many computers that generate light loads.**

早期 CPU 的速率受限，因此即使開發出 100Mps 的網路也沒有什麼用途 ( 因為你用不到那麼多 )。
到了 "1990年代" 隨著CPU的效能增加，更強大的網路也將要問世...

> **In the late 1970s when Ethernet was standardized, a LAN operating at 10 Mbps had more than sufficient capacity for many computers because the available CPU speeds and network interface hardware prohibited a given computer from transmitting data rapidly. By the mid 1990s, however, CPU speeds had increased dramatically as had the use of networks. Consequently, an Ethernet operating at 10 Mbps did not have sufficient capacity to act as a central corporate backbone for even a moderate sized corporation - Ethernet had become a bottleneck.**

#### 5. Fast Ethernet : 100Base-T ( IEEE 標準名稱為: IEEE 802.3u )

基於 10Base-T 提供更高的傳輸效率。

> **To overcome the throughput limitation of Ethernet, engineers designed a new version of Ethernet that operates an order of magnitude faster. Known formally as l0OBase-T, the technology is usually called Fast Ethernet.**

> **As the formal name implies, Fast Ethernet uses category 5 twisted pair wiring, the same wiring used for 10Base-T. However, through clever use of the wires, Fast Ethernet allows a station to transmit or receive data at 100 Mbps.**

#### 6. 10/100 Ethernet

前面提到了 100Mbps 與 10Mpbs 的傳輸速率，在當時的技術上並不是所有的設備都可以跑的那麼快。

因此 10/100 Base-T 問世，這類型的網路線允許兩個設備互相溝通想要使用的通訊速率。

10/100Base-T 在物理層面上使用 Rj45 連接器，因為對於 10Base-T 與 100Base-T 而言，只需要4個pin即可工作，因此在物理層面上，兩者互通。

![img - free CCNA coures: 10/100Base-T connection](https://i.imghippo.com/files/bmXu8320GyQ.png)
- 資料來源 : 我的另一個筆記 / Free CCNA

兩個設備會互相發送訊號，讓對方知道自己應該使用什麼樣的傳輸效率對方才可以配合。

> **In essence, all 100Base-T hardware interjects extra signals, making it possible for the hardware at one end of a cable to know which hardware type is connected to the other end.**

透過這種自行溝通的方式，可以說十分方便。

> **For example, consider a computer that has a 101100 interface card. If the computer is connected to a 10Base-T hub, the hardware in the card will automatically detect the speed and communicate at 10 Mbps. If the same computer is then unplugged from the 10Base-T hub and connected to a 100Base-T hub, the hardware will automatically detect the new speed and begin transmitting at 100 Mbps. The transition in speed is completely automatic: neither the software nor the hardware needs to be reconfigured.**

#### 7.  Gigabit Ethernet : IOOOBase-T

隨著需求的增加，工程師們又開發出 1000Base-T 的形式。

但是這個形式有一個小小的缺點: "相對於 10Base-T 與 100Base-T 的標準，更容易受到電磁干擾"。

> **The high data rate does have a slight disadvantage - it makes gigabit Ethernet more susceptible to electrical interference. Consequently, wiring that operates well with 10Base-T or even 100Base-T may not work well with 1000Base-T.**

#### 8.  Properties of an Ethernet

> **For now, it is enough to understand that the lowest level hardware does not distinguish among transmissions - a hub passes all packets to each host interface, which chooses packets the computer should receive and filters out all others.**

上面這串文字解釋了 hub 的特性，因為 hub 只在 OSI 網路模型中的第一層 ( 物理層 ) 工作，他就是個複讀機，會將電信號放大並且傳輸給所有連接 hub 的設備。

乙太網路使用 "best-effort delivery mechanism" 因為接受方不會回應訊息 ( 例如: "我收到了" ) 。 因此要使用 TCP/IP 這類的上層協議來協助工作。

乙太網路採用分散式架構，這意味著沒有中央管理機構來控制設備的發送權限。每個設備都能自主決定何時發送數據，並透過 CSMA/CD 協議來避免衝突。

> **It is CSMA because multiple machines can access an Ethernet simultaneously and each machine determines whether the network is idle by sensing whether a carrier wave is present. When a host interface 'has a packet to transmit, it listens to see if a message is being transmitted (i.e., performs carrier sensing). When no transmission is sensed, the host interface starts transmitting.**

CSMA/CD（Carrier Sense Multiple Access with Collision Detection）是一種在局域網（LAN）中常用的媒介存取控制協議 ( 以前常用 )，主要用於以太網（Ethernet）網絡中，以管理多台設備共享傳輸介質（如同軸電纜或雙絞線）的情況，確保數據傳輸不會發生衝突，並能在衝突發生時進行適當的處理。

當檢測到網路被占用 ( 透過監聽某種波 ) 意味著現在不可以傳輸資訊，等待網路空閒過後則繼續發送資料。

> **Furthermore, the hardware must observe a minimum idle time between transmissions, which means that no single pair of communicating machines can use the network without giving other machines an opportunity for access.**

書中的內容換句話說，你不能一直傳輸資料，而不給其他設備使用時間。

#### 9. Collision Detection And Recovery

> **When a station begins transmission, the signal does not reach all parts of the network simultaneously. Instead it travels along copper wires at approximately 70% of the speed of light. Thus, it is possible for two transceivers to both sense that the network is idle and begin transmission simultaneously. When the two electrical signals cross they become scrambled, meaning that neither remains meaningful. Such incidents are called collisions.**

因為電信號並非光速，因此存在一定的概率存在不同步。 因此即使你遵循 CSMA 也依然無法完全規避碰撞。 當兩個電信號互相交錯通過 ( 互相干擾 ) ，這兩個信號都將變得沒有意義，我們稱之為 "碰撞" 。

CSMA/CD的工作原理： ( by ChatGpt )
1. **Carrier Sense（載波監聽）**：
   - 在發送數據之前，每個設備首先監聽網絡中是否有其他設備正在傳輸數據（即監聽「載波信號」）。如果網絡繁忙（有其他設備正在傳輸），設備將等待，直到網絡空閒。

2. **Multiple Access（多重存取）**：
   - 多台設備可以共享同一條傳輸介質，它們都可以嘗試在網絡上發送數據。因此，CSMA/CD必須解決多設備競爭使用傳輸介質的問題。

3. **Collision Detection（碰撞檢測）**：
   - 在設備開始傳輸數據後，它會繼續監聽網絡，以檢查是否發生了碰撞。如果兩台設備同時發送數據，它們的信號會互相干擾，發生碰撞。設備能夠檢測到這種碰撞，並會立即停止傳輸。

4. **Collision Handling（碰撞處理）**：
   - 一旦檢測到碰撞，設備會發送一個特殊的「干擾信號」（稱為「jamming signal」）來通知其他設備發生了碰撞。隨後，這些設備會根據一個隨機的退避算法（通常稱為「指數退避」）等待一段隨機的時間，再重新嘗試發送數據。


> **The Ethernet handles collisions in an ingenious fashion. Each station monitors the cable while it is transmitting to see if a foreign signal interferes with its transmission. Technically, the monitoring is called collision detection (CD), making the Ethernet a CSMAJCD network. When a collision is detected, the host interface aborts transmission, waits for activity to subside, and tries again.**

對於碰撞的處理方式大致為以下三個步驟: [參考資料](https://www.101labs.net/what-occurs-when-a-collision-happens-on-a-network-find-out/)

1. 偵測：當一個或多個裝置偵測到資料衝突時，它將發送干擾訊號以通知網路上的其他裝置該問題。此干擾訊號被網路上的所有其他裝置識別並導致下一步。
2. 退避：一旦偵測到網路衝突，網路上的所有其他裝置就會發送並隨後接收干擾訊號，並且指示所有相關裝置在嘗試重新傳輸其資料包之前等待隨機的時間量。這個過程稱為“退避演算法”，在網路上使用它有助於防止資料包相互衝突。
3. 重傳：一旦兩個設備的退避期結束，設備就會重傳其資料包。如果發生另一次碰撞，則從第一步開始重複此程序。隨著步驟的每次迭代，退避期將呈指數級增長，以進一步降低持續資料衝突的可能性。

![img - collision](https://www.101labs.net/wp-content/uploads/2023/06/2-1-scaled-752x1024-1.webp)

早期網路系統中碰撞非常非常常見! 當網路系統變得愈大，碰撞發生的機率也會愈高。

有幾個因素可能會增加乙太網路資料衝突的可能性，包括：

- 網路擁塞：更高水準的流量或更密集、更擁塞的網路上的連續流量會顯著增加同時資料包傳輸的可能性，從而導致衝突。
- 網路規模大：隨著網路整體規模和連接到網路的單一設備數量的增加，資料或網路衝突的可能性急劇增加。較大的網路發生衝突的可能性較高，但也更有可能以有助於最大程度地減少實際發生衝突的方式組織網路。
- 較長的電纜長度：增加資料衝突幾率的另一個因素是在建置實體網路基礎架構時使用較長的電纜。較長的電纜會產生較高的訊號傳輸延遲，增加發生衝突的時間視窗。

> **Care must be taken or the network could wind up with all stations busily attempting to transmit and every transmission producing a collision. To help avoid such situations, Ethernet uses a binary exponential backoff policy where a sender delays a random time after the first collision, doubles the range if a second attempt to transmit also produces a collision, quadruples the range if a third attempt results in a collision, and so on.**

#### 10. Ethernet Hardware Addresses

也被稱為「Mac位址」，早期網路使用 hub 作為 "中介設備" ，透過 廣播(broadcast) 的方式將數據重複並發給 "所有電腦" 。

就像 信/紙條/包裹 上沒有收件人署名，你不知道這個東西是否是給自己的，因此我們需要 Mac 位址作為確認。 基本上每台設備的 Mac 位址不可能重複 ( 燒錄在硬體中 )，你甚至可以從你的電腦的 Mac 位址中得知生產你的設備的公司等訊息。

> **Physical addresses are associated with the Ethernet integace hardware; moving the hardware integace to a new machine or replacing a hardware integace that has failed changes the machine's physical address.**

因為 hub 是個蠢蛋! 因此你需要手動地確認這個封包是不是你自己的。 如果你將網卡網卡設定為 "混雜模式（Promiscuous mode）" 網卡將不會過濾包裹，這意味著其他人的流量會到你的電腦中，你也可以藉此獲取他人的資訊。

#### 11. Ethernet Frame Format

如果你讀過 OSI 網擄模型，你會知道 header 的概念，如果你是一個合格的資工系學生或者有相關背景，那你應該聽過 PDU(Protocal Data Unit) 的架構。

![img - PDU](https://i.imghippo.com/files/PAYX3422wZk.png)
- 圖片來源 : 我的另一個筆記 / Free CCNA

Ethernet header:

![img - ethernet header](https://media.geeksforgeeks.org/wp-content/uploads/IEEE-802.3-Ethernet-Frame-Format.png)
- 圖片來源 : https://www.geeksforgeeks.org/ethernet-frame-format/

以下來自 GPT 的筆記輸出:

1. **Preamble (前導碼) — 7 bytes**
   - **描述**：前導碼是 7 個字節，包含了 56 位的 1 和 0 的組合，用來幫助接收端同步時鐘，確保數據能夠正確接收。
   - **作用**：它的目的是讓接收端的硬件準備好接收數據。在以太網的傳輸中，前導碼是必需的，但它並不承載實際的數據。
   - **範例**：`10101010 10101010 10101010 10101010 10101010 10101010 10101010`（7 個字節）

2. **Start of Frame Delimiter (SFD) — 1 byte**
   - **描述**：SFD 是 1 個字節，通常是 `0xAB`，用來指示以太網幀的開始。它的主要作用是區分前導碼（Preamble）和實際的幀頭部數據。
   - **範例**：`0xAB`

3. **Destination MAC Address (目標 MAC 地址) — 6 bytes**
   - **描述**：這個字段指定了數據幀的目標設備的 **MAC 地址**，它是 6 個字節（48 位）。每個設備的 MAC 地址由製造商分配。
   - **作用**：目標 MAC 地址用來標識數據幀的接收者。這是數據鏈路層的地址，與網絡層的 IP 地址不同。
   - **範例**：`00:1A:2B:3C:4D:5E`

4. **Source MAC Address (源 MAC 地址) — 6 bytes**
   - **描述**：這個字段指定了發送數據幀的設備的 **MAC 地址**，它同樣是 6 個字節。這是發送者的唯一標識。
   - **作用**：當接收設備收到幀時，它會根據源 MAC 地址知道數據的發送者，並可用於發送回應（例如 ARP 回應）。
   - **範例**：`00:1B:2C:3D:4E:6F`

5. **Ethertype / Length (類型/長度字段) — 2 bytes**
   - **描述**：這個字段根據使用的以太網框架有兩種含義：
     - **在 Ethernet II 框架下**，它表示 **Ethertype**，指定了數據包的上層協議（如 IPv4、IPv6、ARP 等）。
     - **在 IEEE 802.3 框架下**，它表示 **Payload 長度**，指出數據部分的長度（以字節為單位）。
   - **Ethertype 常見值**：
     - `0x0800` — IPv4
     - `0x86DD` — IPv6
     - `0x0806` — ARP
   - **範例**：
     - `0x0800`（表示承載 IPv4 協議的數據包 -> 上層協議）

6. **Data (數據部分 / 有效載荷) — 46 到 1500 bytes**
   - **描述**：這是數據幀的有效載荷，包含了實際傳輸的數據。根據以太網標準，數據部分大小範圍是 46 到 1500 字節。如果數據少於 46 字節，則需要填充（Padding）至最小長度 46 字節。
   - **作用**：此部分包含了實際要發送的數據，通常是如 IP 數據包、ARP 請求等。
   - **範例**：`[IPv4 packet data]`

7. **Frame Check Sequence (FCS) — 4 bytes**
   - **描述**：FCS 是 4 個字節，用於 **錯誤檢測**，它使用 **循環冗餘檢查**（CRC）算法來檢查幀的完整性。
   - **作用**：接收端會使用 CRC 檢查幀是否在傳輸過程中發生了錯誤。如果 FCS 校驗失敗，幀將被丟棄並要求重新發送。
   - **範例**：`[CRC Checksum]`

| 項目                         | 字節數   | 描述 |
|----------------------------|--------|------|
| **Preamble**                | 7      | 用於同步信號，無實際數據 |
| **Start of Frame Delimiter (SFD)** | 1      | 以太網幀的開始指示 |
| **Destination MAC Address** | 6      | 目標設備的 MAC 地址 |
| **Source MAC Address**      | 6      | 發送設備的 MAC 地址 |
| **Ethertype / Length**      | 2      | 表示 Ethertype 或 Payload 長度 |
| **Data**                    | 46–1500| 實際數據（有效載荷） |
| **Frame Check Sequence (FCS)** | 4      | 循環冗餘檢查（CRC） |

---

#### 12. Extending An Ethernet With Repeaters 

如果想要延長乙太網的有效傳輸長度，通常會使用 "中間設備" 來達到這一點 ( 增強電信號之類的 )。

常見的 LAN中間設備: (書中提到，現實生活中很難看到 Hub 與 Bridge )

1. **集線器（Hub）**
- **作用**：集線器是一種較為簡單的設備，用於將多個設備連接到同一網絡。它工作在 **物理層**（OSI 模型的第一層），當接收到來自某個端口的數據時，會將數據廣播到所有其他端口。由於它不會根據目標地址轉發數據，因此會增加不必要的網絡流量。
- **用途**：已經逐步被交換機取代，但在某些舊的或低成本的網絡中仍然使用。

2. **網絡橋接器（Bridge）**
- **作用**：網絡橋接器用來連接兩個或多個局部網絡（LAN），使它們能夠像一個單一的網絡一樣進行通信。它工作在 **數據鏈路層**，根據 **MAC 地址** 來決定是否轉發數據幀。
- **用途**：主要用來擴展網絡範圍，或將不同的網段連接在一起。隨著交換機的普及，橋接器的使用逐漸減少。

<br>

> **However, to preserve the CSMA/CD timing, the Ethernet standard restricts the use of repeaters - at most two repeaters can be placed between any two machines.**

#### 13. Extending An Ethernet With Bridges

由於 CSMA/CD 的限制: 任意兩個設備之間，不應該存在三個以上的hub。

Bridge 用來連接兩個不同的乙太網 ( 網路上解釋為不同的網段 )，並且在網路中是透明的 "你不會意識到它的存在" 。

> **Bridges hide the details of interconnection: a set of bridged segments acts like a single Ethernet.**

以下為 GPT 整理:

橋接器（Bridge）用來連接兩個或多個 乙太網段，並且它比集線器（Hub）或重複器（Repeater）更有效，因為橋接器是基於 數據包（Packet） 運行，而非單純傳遞電氣信號。它不會複製噪音、錯誤或不正確的數據幀，僅在收到有效的數據幀後，才會將其轉發到其他網段。每個網段之間的連接遵循 CSMA/CD 規則，這使得各個網段之間的 碰撞 和 延遲 互不干擾。 ( 換句話說是在 Layer 2 工作 )

橋接器隱藏了網絡之間的互連細節，對於網絡上的設備來說，它們依然視所有橋接過的網段為 單一網絡，並使用相同的硬體、幀格式和通信協議來與遠端設備通信，這樣的橋接網絡被稱為 透明橋接網絡。

自適應橋接器（Adaptive Bridge） 不僅僅是複製數據幀，它還能根據 源 MAC 地址 學習每個設備所在的網段，並根據 目標 MAC 地址 決定是否轉發數據包。這樣，橋接器能夠減少不必要的數據包轉發，提升網絡效能。當目的地址在同一網段時，橋接器不會轉發該數據包；如果目標設備不在該網段或是廣播/多播地址，橋接器則將其轉發到其他網段。

---

我並不認為這是一個重點，因為現在 Bridge 大多已經被 Switch(交換機) 所取代。


## LAN 光纖網路 : Fiber Distributed Data Interconnect (FDDI) -> 曾經的王者如今的歷史...

FDDI（光纖分佈式數據接口，Fiber Distributed Data Interface）是一種曾經流行於局域網（LAN）中的技術，主要用於大規模、高速的企業網絡。FDDI使用光纖作為傳輸介質，提供100Mbps的傳輸速率，並以 環狀結構 連接設備，看起來就很好玩。

但是! 現代的乙太網（Ethernet）已經取代了FDDI，如果你對於前面的內容有所印象，維基百科中提到:

乙太網路（英語：Ethernet）是一種電腦區域網路技術。IEEE組織的IEEE 802.3標準制定了乙太網路的技術標準，它規定了包括實體層的連線、電子訊號和媒介訪問控制的內容。乙太網路是目前應用最普遍的區域網路技術，<font color="red">取代了其他區域網路標準如權杖環、FDDI和ARCNET</font>。 ( 資料來源: [維基百科](https://zh.wikipedia.org/zh-tw/%E4%BB%A5%E5%A4%AA%E7%BD%91#%E5%8F%82%E8%80%83%E6%96%87%E7%8C%AE) )

FDDI，其優點有:
1. 因為使用光纖作為傳輸，因此不會受到強烈磁場的干擾
2. 因為傳輸媒介是光，因此傳輸距離也將對較長

雖然 "Optical fiber(光纖)" 聽起來很脆弱 (易斷) 但實際上其實還行，只要你不要彎折超過90度以上即可。

FDDI 提供 100Mbps 的傳輸速率，整體採用環狀的架構，在這個環上連接著你的設備。

> **An FDDI network is a 100 Mbps shared token passing ring technology with a self-healing capability. An FDDI network is shared because multiple computers connect to a given network and take turns sending packets. FDDI is known as a ring because the network forms a cycle that starts at one computer, passes through all others computers, and ends back at the source.**

透過 token 的傳遞來控制輪到哪一台電腦發送資料，整體流程如下: ( 由GPT 生成 )

1. **初始化**：每個設備（如電腦或其他網絡設備）都會連接到光纖環路中，並等待令牌的到來。
2. **令牌傳遞**：在網絡中，會有一個特殊的數據包（書中稱為 token）在網絡中循環傳遞。令牌是控制網絡訪問的信號，只有持有令牌的設備才能發送數據。
3. **數據傳輸**：當某台設備獲得令牌時，它會將數據包傳送到環中的下一個設備。如果目的設備在網絡中，它會接收到數據並將數據包傳遞給下一台設備，直到數據回到源頭。
4. **自我修復**：如果環路中的某一段故障（例如，光纖被斷開），FDDI會通過自動重新配置網絡來繞過故障區域，保持網絡的連接。

優點：
- **抗干擾能力強**：使用光纖作為傳輸介質，FDDI能有效避免電磁干擾，並適用於要求高穩定性和長距離傳輸的環境。
- **較長的傳輸距離**：相比其他傳輸介質（如銅線），光纖的傳輸距離更長。
- **自我修復能力**：FDDI網絡支持自動修復功能，能夠在設備故障時保持網絡運行。

缺點：
- **成本較高**：光纖網絡的建設和維護成本相對較高。
- **逐漸被取代**：隨著以太網技術的發展，特別是光纖以太網（如Gigabit Ethernet）和無線網絡技術的普及，FDDI已經不再是主流技術。

---

![img - figure of FDDI ring](https://i.imghippo.com/files/aUjC3470fEE.jpg)
- 圖片來自於書中

> **Unless an error has occurred, an FDDI hardware does not need both rings. In fact, an FDDI interface behaves like any token passing network interface until an error occurs. The interface examines all packets that circulate around the ring, comparing the destination address in each packet to the computer's address. The interface keeps a copy of any packet destined for the local computer, but also forwards the packet around the ring.**

每個電腦會透過比較地址的方式來確認這個資料是否是給自己，以此來決定是否接收。

通常而言第二個環是不會被使用的，直到某一台設備出現了故障。當檢測到類似的錯誤發生時，就會直接迴轉! 此時第二個還被啟用，如圖:

![img - erreo when FDDI fail to transmit data](https://i.imghippo.com/files/HIP1558OwA.jpg)
- 圖片來自於書本中

> **When FDDI hardware detects a failure on the network, it automatically loops data across the backup ring to permit communication among remaining stations.**

## WAN Technologies: ARPANET

> **One of the oldest wide area technologies, the ARPANET, was funded by ARPA, the Advanced Research Projects Agency. ARPA awarded a contract for the development of the ARPANET to Bolt, Beranek and Newman of Cambridge, MA in the fall of 1968. By September 1969, the first pieces of the ARPANET were in place.**

最早出現的 WAN ( 廣域網 ) 由 ARPA 這個機構進行贊助，並命名為 ARPANET 。

> **The ARPANET served as a testbed for much of the research in packet-switching. In addition to its use for network research, researchers in several universities, military bases, and government labs regularly used the ARPANET to exchange files and electronic mail and to provide remote login among their sites. In 1975, control of the network was transferred from ARPA to the U.S. Defense Communications Agency (DCA). The DCA made the ARPANET part of the Defense Data Network (DDN), a program that provides multiple networks as part of a world-wide communication system for the Department of Defense.**

最初 ARPANET 網路大多用於 "大學研究" 、 "軍用基地" 、 "政府的實驗室" 。

在 1975 年 網路的控制權由 ARPA 這個機構轉移到 美國國防通訊局(DCA) ， 後來 DCA 將 ARPANET 納入了 國防數據網路 (DDN) 的一部分。

1983年，美國的國防部將 ARPANET 劃分為兩個相互連接的網路，讓 ARPANET 繼續作為研究用途，同時創建 MILNET 作為軍事用途。

MILNET 僅限於處裡非機密數據，因為它不被認為是安全的。雖然正常情況下 ARPNA 和 MILNET 會互相轉發流量，但設有控制措施可以中斷兩者間的連線。 許多公司也開始建立私有的網路。

> **In 1983, the Department of Defense partitioned the ARPANET into two connected networks, leaving the ARPANET for experimental research and forming the MILNET for military use. MILNET was restricted to unclassified data because it was not considered secure. Although under normal circumstances, both ARPANET and MILNET agreed to pass traffic to each other, controls were established that allowed them to be disconnected?. Because the ARPANET and MILNET used the same hardware technology, our description of the technical details apply to both. In fact, the technology was also available commercially and was used by several corporations to establish private packet switching networks.**

也因為 ARPANET 廣泛的被研究等， ARPANET 對於網路的架構有著深遠的影響。 你可以想像 ARPANET 是由一個主幹網路和很多小網路所組成的 ( 小網路圍繞著主幹網路構建 )，因此當網路變得很大的時候，不利於過展也不靈活。

這種單一的骨幹架構現今扔然可以在某些網路協議中被看到，如我剛剛所說這種設計架構不利於優雅的容納新的網路。

> **Because the ARPANET was already in place and used dily by many of the researchers who developed the Internet architecture, it had a profound effect on their work. They came to think of the ARPANET as a dependable wide area backbone around which the Internet could be built. The influence of a single, central wide area backbone is still painfully obvious in some of the Internet protocols that we will discuss later, and has prevented the Internet from accommodating additional backbone networks gracefully.**

> **Because the ARPANET was originally built as a single, independent network to be used for research, its protocols and addressing structure were designed without much thought given to expansion. By the mid 1970's, it became apparent no single network would solve all communication problems, and ARPA began to investigate satellite and packet radio network technologies. This experience with a variety of network technologies led to the concept of an internetwork.**

在 1970年代，去中心化的網路問世，因為人們意識到 "單一的網路沒辦法解決所有的需求"。

## Other Technologies Over Which TCPIIP Has Been Used

書中討論完 WAN Technologies 過後，就是一連串的古老知識 (NSFNET)等，我認為不必要理解，因為現今的網路構造不是那樣，它用於早期的美國。

> **Much of the success of the TCPm protocols lies in their ability to accommodate almost any underlying communication technology.**

TCP/IP 的成功是因為它幾乎可以容納在任何硬體架構、任何協議當中。