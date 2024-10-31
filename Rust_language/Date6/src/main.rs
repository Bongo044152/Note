fn main() {
    // loop in rust
    learn_loop1();
    // breek specify loop by using tag
    learn_loop2();
    // while loop in rust
    learn_whileloop();
    // for loop in rust -> just like python
    learn_forloop1();
    learn_forloop2();
}

fn learn_loop1() {
    let mut x = 10;

    loop {
        if x > 1_000 {
            break;
        }
        else{
            x += 1;
        }
    }
    println!("got value of x: {x} in learn_loop1");
}

fn learn_loop2() {
    let mut x = 10;

    // tag the loop
    'outer: loop {
        loop {
            if x > 1_000 {
                continue 'outer; // continue outer loop
            }
            else if x % 300 == 0{
                x += 1;
                break; // break inner loop
            }
            else if x == 999 {
                break 'outer; // break outer loop
            }
            else{
                x += 1;
            }
        }
        println!("Hello my friend !!");
    }

    println!("got value of x: {x} in learn_loop2");
}

fn learn_whileloop() {
    let mut x = i8::MIN;

    while x < 1_00 {
        x += 1;
    }
    println!("got value of x: {x} in learn_whileloop");
}

fn learn_forloop1() {
    println!("learn_forloop1 start...");
    for num in 1..6 {
        print!("{num} ");
    }
    println!();
    
    // reverst
    for num in (1..6).rev() {
        print!("{num} ");
    }
    println!();
}

fn learn_forloop2() {
    println!("learn_forloop2 start...");
    let arr = [1, 2, 3, 4, 5];
    for num in arr {
        print!("{num} ");
    }
    println!();
}