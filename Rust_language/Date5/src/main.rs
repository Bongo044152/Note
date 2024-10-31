use rand::Rng;
use std::cmp::Ordering;
use std::io;

// Write a program that generates a random number between 1 and 100 and asks the user to guess it. The program should tell the user if their guess is too high, too low, or correct. The program should continue to ask the user for guesses until they guess the correct number.

fn main() {

    // _guess_game1();
    _guess_game2();
}

fn _guess_game1() {

    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1..=100); // 1 - 100 或者 1.0..1e2 則是返回 f32
    // 可以直接指定而非使用 println!("The secret number is: {}", secret_number);
    println!("The secret number is: {secret_number}");

    println!("Please input your guess.");
    let mut guess = String::new();

    io::stdin()
    .read_line(&mut guess)
    .expect("Failed to read line");

    println!("You guessed: {guess}");

    // The parse method on strings converts a string to another type.
    // Here, we use it to convert from a string to a number.
    // We need to tell Rust the exact number type we want by usinglet guess: u32 . 
    // The colon ( : ) after guess tells Rust we’ll annotate the variable’s type.

    let guess: u32 = guess.trim().parse().expect("Please type a number!");

    // The cmp method compares two values and can be called on anything that can be compared.
    // It takes a reference to whatever you want to compare with: 
    // here it’s comparing guess to secret_number .

    // Then it returns a variant of the Ordering enum we brought into scope with the use statement.
    // We use a match expression to decide what to do next based on which
    // variant of Ordering was returned from the call to cmp 
    // with the values in guess and secret_number .
    match guess.cmp(&secret_number) {
        Ordering::Less => println!("Too small!"),
        Ordering::Greater => println!("Too big!"),
        Ordering::Equal => println!("You win!"),
    } 
}
    
fn _guess_game2() {

    println!("Guess the number!");

    let secret_number = rand::thread_rng().gen_range(1..=100); // 1 - 100 或者 1.0..1e2 則是返回 f32

    loop {
        println!("Please input your guess.");
        let mut guess = String::new();
    
        io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");

        // Remember that parse returns a Result type and Result is an enum
        // that has the variants Ok and Err . We’re using a match expression here, as we did with the
        // Ordering result of the cmp method.
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break; // end of the game -> using "break"
            },
        }
    }
}