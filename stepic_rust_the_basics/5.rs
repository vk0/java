// If and Functions

// Write a function fib which takes a single i32 argument n < 10 and returns n's Fibonacci number (also i32).

// Try to use recursion.

// Sample Input 1:

// 1

// Sample Output 1:

// 1


// Sample Input 2:

// 7

// Sample Output 2:

// 13

fn fib(n: i32) -> i32 {
    match n {
        0 => 0,
        1 => 1,
        _ => fib(n - 1) + fib(n - 2)
    }
}

fn main() {
   for i in 2..40 {
     println!("fib({}) = {}",i, fib(i));
   }
}