fn main() {

    // 流程控制
    println!("function \"condition\" run...");
    condition();
    println!("\n---------------------\n");
    // 函式呼叫、參數傳遞
    println!("function \"test\" run...");
    test(666);
    println!("\n---------------------\n");
    // 區塊表達式 ( 類似函式但是不能使用 return )
    println!("function \"expression\" run...");
    expression();
    println!("\n---------------------\n");

    // 函式返回值
    println!("function_return1 retunr valus : {}", function_return1());
    println!("function_return2 retunr valus : {}", function_return2());

    // 函式相套
    println!("\n---------------------\n");
    println!("function \"my_fn\" run...");
    my_fn();
}

fn condition() {
    let food = "tricolor beans";

    // 當你括弧用習慣之後，突然跟你說不用括弧，你會不會超不習慣的？
    if food == "cookie" {
        println!("yummy");
    } else if food == "tricolor beans" {
        println!("yuck!");
    } else {
        println!("where is my cookie?");
    }
}

fn test(x: i32) {
    println!("Test has been called...");
    println!("The value of x is: {}", x);
}


fn expression() {

    let condition = true;
    let y = {
        let x = 3;
        if condition {
            x + 1
        } else {
            x - 1
        }
    };

    println!("The value of y is: {}", y);
}

fn function_return1() -> i32 {
    5 // 並沒有 ";" 
}

fn function_return2() -> i32 {
    return 5;
}

fn my_fn() {
    fn inner_fn() {
        println!("幹你 ..... ");
    }

    inner_fn(); // 這裡呼叫 inner_fn
}