// Write a function fib which takes a single i32 argument n < 90 and returns n's Fibonacci number (now in i64).

// Looks familiar, huh? Try to use for loop now.

// Sample Input 1:

// 1

// Sample Output 1:

// 1


// Sample Input 2:

// 7

// Sample Output 2:

// 13

fn fib(n: i32) -> i64 {
    let (mut cur, mut next) = (0i64, 1i64);

    for _ in 0i32..n {
        let tmp = cur + next;
        cur = next;
        next = tmp;
    }

    cur
}

fn main() {
   for i in 2..40 {
     println!("fib({}) = {}",i, fib(i));
   }
}