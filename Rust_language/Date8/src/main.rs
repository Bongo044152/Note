struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

fn main() {
    // --snip--

    let user1 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_count: 1,
    };

    let _user2 = User {
        active: user1.active,
        username: user1.username,
        email: user1.email.clone(),
        sign_in_count: user1.sign_in_count,
    };

    // let temp = user1.username; move occurs because `user1.username` has type `String`, which does not implement the `Copy` trait
    // 即表示所有權被轉移
    let temp = user1.active; // bool 屬於原生資料，因此沒有所有權的問題
    println!("{temp}");
    let temp = user1.email; // 複製字串不會有事，因為 user1 依然保留所有權
    println!("{temp}");

    let _user3 = User {
        email: String::from("s3312543@gmail.com"),
        .._user2
    };

    // let temp = _user2.username; 所有權再次轉移 _user2.username -> _user3.username

    let color = Color(255,255,255);
    println!("color is : ( {}, {}, {} )", color.0, color.1, color.2);

    class_like_this();
}

struct Color(u8, u8, u8);
// struct Point(i32, i32, i32);



struct Triangle(u16, u16, u16);
impl Triangle {
    fn is_right_triangle(&self) -> bool {
        let Triangle(a, b, c) = self;

        let mut arr = [a, b, c];

        // simple bubble sort
        for i in 1..arr.len() {
            if arr[i-1] > arr[i] {
                let temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
            }
        }

        arr[0].pow(2) + arr[1].pow(2) == arr[2].pow(2)
    }

    fn _creat_triangle(size: u16) -> Self {
        // Triangle 是一個元組結構體，它的字段並沒有具名，而是直接以位置來區分
        // 因此不可以
        // Self { size, size, size }
        // 而是改成以下形式
        Triangle(size, size, size)

    }
}
fn class_like_this() {

    let simple_trangle = Triangle(1,2,3);
    if simple_trangle.is_right_triangle() {
        println!("this is a right angle triangle");
    }
    else {
        println!("this is not a rigth angle triangle");
    }

}