fn main() {
    // tuple <- 類型可以不相同
    let x: (i32, bool, &str) = (10, true, "水嗎?");
    // 輸出tuple的內容
    println!("( {}, {}, {} )", x.0, x.1, x.2);

    // 更改tuple的內容
    let mut y = (10, true, "水嗎?"); // 必須要先生名 mut，表示這是一個可變的變量
    y.0 = 20;
    println!("( {}, {}, {} )", y.0, y.1, y.2);

    // array <- 強制類型必須相同
    let arr = [1, 2, 3, 4, 5];
    // 輸出array的內容
    println!("array: {:?}", arr);
    // 索引訪位
    println!("arr[0]: {}", arr[0]); // 值得一提的是，arr[index]; 其中 index 資料型態是 usize

    // array 的大小被確定，不可以宣告為空
    // let arr: [i32; 5] = []; // <- 這會導致錯誤
}
