# 概要

1. rust 的資料型態

## 1. rust 的資料型態

1. 整數

- i8, i16, i32, i64, i128
- u8, u16, u32, u64, u128

2. 浮點數

- f32, f64 : 單精度浮點數，雙精度浮點數

3. 布林值

- bool : true, false ( 本質上是 0 和 1 )

4. 字串

- &str : 字串切片，不可變的
- String : 字串，可變的

5. 元組

- (i32, f64, bool) : 元組的元素型態可以不同
```rs
let tup: (i32, f64, u8, bool, &str) = (500, 6.4, 1, true, "hello");
// 輸出tuple
println!("( {}, {}, {}, {}, {} )", tup.0, tup.1, tup.2, tup.3, tup.4);
```

6. 陣列

- [T; N] : T 是陣列的元素型態，N 是陣列的長度