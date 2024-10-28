use  std::io; // import the io module

fn main() {
    println!("Please enter something:");
    let mut user_input = String::new();
    io::stdin().read_line(&mut user_input).expect("Failed to read line");
    println!("You entered: {}", user_input);

    // 和 C 語言不同的地方是
    let x: i8 = 5;
    let y: u8 = 10;
    // let z: u8 = x + y; // 會出錯，因為 x 是 i8，y 是 u8，兩個數字型態不同
    // 如果要修正
    let z: u8 = x as u8 + y; // 使用 as 來轉換數字型態
    println!("z = {}", z);

    // rust 允許利用下底線劃分數字
    let large_number = 127_000; // 這裡的 large_number 是 127000
    println!("The large number is: {}", large_number);

    let _i32max = i32::MAX; // rust 允許我們這樣做

    // 以下寫法皆相同
    let _x = 5_i8;
    let _x = 5i8;
    let _x = 5 as i8;
    let _x = 5_i32 as i8;
    let _x: i8 = 5;

    // 輸入格式轉換
    let mut user_input = String::new();
    io::stdin().read_line(&mut user_input).expect("Failed to read line");
    let user_input = user_input.trim(); // 去掉換行符與空白符號
    let user_input: i32 = user_input.parse().unwrap(); // 將字串轉換成整數
    let result = user_input * 2;
    println!("The result is: {}", result);
}
