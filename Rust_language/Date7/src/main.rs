fn main() {
    
    let mut string = String::from("Hello, world!"); // 原生數組
    println!("原本的 string: {string}");
    let slice = slice_method(&string, 5); // 切片
    println!("切片引用: {slice}");

    // 當資料發生改變過後，之前的引用不應該再被訪問
    string.push_str(" banana~"); // 增添內容
    string.clear(); // 清空原生數組
    // println!("slice: {slice}"); 錯誤的使用，因為擁有者已經更改了資料內容

    let a = &mut string; // a 是一個可變引用
    a.push_str("Hello, World!"); // a 修改了資料內容
    println!("透過可變引用修改: {string}");

    let b = &string; // b 是一個不可變引用
    println!("不可變引用: {b}"); // 這裡可以正常訪問，因為認定 a 的作用域結束，超神奇的!
}

fn slice_method(string: &String, length: usize) -> &str {
    // return the substring of length
    &string[0..length]
}
