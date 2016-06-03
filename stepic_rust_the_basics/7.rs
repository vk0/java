// Standard Input

// Read two numbers from stdin (separated by a single space). Write their sum to stdout (using println!).

// Sample Input:

// 2 5

// Sample Output:

// 7

use std::io;
fn main() {
    let mut numbers = String::new();
    let mut sum = 0;

    io::stdin().read_line(&mut numbers).ok().expect("read error");

    let numbers: Vec<i32> = numbers
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();

    for num in numbers {
        sum = sum + num;
        // println!("{}", num);
    }
    println!("{}", sum);
}