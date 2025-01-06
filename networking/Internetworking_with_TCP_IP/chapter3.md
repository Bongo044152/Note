# Chapter 3 : Internetworking Concept And Architectural Model

## **Introduction**

本章討論:

- **如何使各種硬體設備無溝通障礙，並使不同的網路技術運作起來更像整體**

## **Application-Level Interconnection**

如何隱藏底層的運作邏輯非常重要，就像使用者介面: "使用者不需要知道背後的程式內容與運作原理，只需要知道如何與介面互動即可" 。

對於網路而言也是一樣的，如果需要探討底層的東西會變得過於複雜，而且不同的網路會有自己不同的技術、實現方式、硬體設備... 因此如果網際網路採用這種方式 ( 當數據傳輸過去，你需要指揮各種硬體該如何工作 ) 將會變得非常複雜且不易擴展。

但是! 隨著需求的增加，"單一一種網路配置方式沒辦法滿足所有的需求"。

工程師們想到兩種方式設法去隱藏底層的細節:
1. 使用應用程式來做為不同設備間的溝通方式:

> **Designers have taken two different approaches to hiding network details, using application programs to handle heterogeneity or hiding details in the operating system.**

每個位於該設備的應用程式都可以理解該硬體的運作、操作方式、網路運作方式並且與其他設備的應用程式進行溝通。

> **In such systems, an application-level program, executing on each computer in the network, understands the details of the network connections for that computer, and interoperates across those connections with application programs on other computers.**

書本上以郵件傳輸為例:

如果我有一個電子郵件系統，該系統由好幾個應用程式完成 ( 藉此來完成訊息的傳遞 ) ，這些應用程式與其它應用程式互相溝通。

> **For example, some electronic mail systems consist of mail programs that are each configured to forward a memo to a mail program on the next computer. The path from source to destination may involve many different networks, but that does not matter as long as the mail systems on all the machines cooperate by forwarding each message.**

看起來使用應用程式是一個很簡單、很直覺的方式來影藏底層的細節，但是這種方式有一些限制:

1. 添加一個新的功能則需要修改應用程式的內容
2. 添加一個新的硬體需要對其專門設計一個應用程式

> **Using application programs to hide network details may seem natural at first, but such an approach results in limited, cumbersome communication. Adding new functionality to the system means building a new application program for each computer.<br>Adding new network hardware means modifying existing programs (or creating new programs) for each possible application. On a given computer, each application program must understand the network connections for the computer, resulting in duplication of code.**

隨著使用者的需求增加，你不可能都寫一堆應用程式來滿足所有；並且如果在傳輸資料的過程中其中一個應用程式出現了錯誤! 則傳輸失敗，並且其他電腦不知道發生了什麼事。

## **Network-Level Interconnection**

既然前面的方法行不通 ( 即已應用作為出發條件不可行 )，那麼以 "網路" 層面作為出發點 ?

與前面的應用不同的低方在於: "網路層即互聯(network-level interconnection)" 的方式是指網路的基礎層面上進襲澃傳輸，而不依賴於特定的應用程式來處理通信。 它是一種機制，能夠將小數據包從源頭直接傳送到最終目的地，而不需要經過中間的應用程式。 ( 應用程式的設計方式並非最佳實踐 )

1. 網路層級直接映射到底層的網路硬體，傳輸會更加高效。
2. 對於應用程式而言，處裡的是 OSI 模型的最上層，而對於中間設備傳輸訊息的目的: 你不需要了解內容，要做的只是將資訊傳到正確的設備手上即可。
3. 使整個網路變得更加彈性
4. 透過在網路層添加新的技術，可以達到更新的效果。

