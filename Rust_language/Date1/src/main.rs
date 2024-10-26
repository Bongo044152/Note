fn main() {
    let x = 4;
    println!("x = {}", x);

    // this will not cause an error, while variable is declared twice
    let x = 5;
    println!("x = {}", x);
    let x = x+1;
    println!("x = {}", x);

    // rust 語言中，如果要像第12行那樣更改數值，必須要事先聲明 mut -> multiple
    // 如果沒有事先聲明編譯器會叫!
    let mut y = 9;
    println!("y = {}", y);
    y = 10;
    println!("y = {}", y);

    // 沒有聲明 mut
    let z = 10;
    println!("z = {}", z);
    // z = 20; <- 這會引發錯誤

    // 執行多餘的步驟
    let mut a = 15;
    a = 20; // 為什麼不要一開始就決定好? rust 會這樣警告你，因為實際上你只需要 let a = 20; 即可
    println!("a = {}", a);

    // 宣告一個變數但是不使用!
    let b = 9; // 他還是會警告你! 爽不爽!

    let _c = 9; // 這是預設不會被使用的變數，加上 _ 表示
}
