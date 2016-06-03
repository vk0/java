// Installing Rust

// You can follow these instructions to install Rust. Simplest way is to run this command line on Linux or Mac ﻿OS﻿:

// $ curl -L https://static.rust-lang.org/rustup.sh | sh

// Now create a main.rs file with the following code

fn main() {
    println!();
}

// Compile and run it using:

$ rustc main.rs


// What message do you see?

main.rs:2:5: 2:16 error: unexpected end of macro invocation
main.rs:2     println!();
              ^~~~~~~~~~~