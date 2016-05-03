Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Asymptotic Analysis: A very limited overview.
This is a means of discussing the general efficiency of an an algorithm. When discussing the time complexity of an algorithm, we use the positive integer n to represent the size of the data set it processes. To evaluate the actual algorithm, we must ignore machine-dependent constants (i.e.: think about the number of instructions being executed, not about how fast a certain machine can execute them) and look at its growth rate as n approaches ∞ (i.e.: how does the it grow as a function of time—especially as n gets large?).

Here are the big terms you need to know:
f(n) = Θ(g(n))
f(n) is Theta of g(n) if and only if there exists some positive constants c1, c2, and n0 such that c1•g(n) ≤ f(n) ≤ c2•g(n) whenever n > n0. In short, f(n) is bounded both above and below by g(n) because after some point n0, f(n) and g(n) have the same growth rate.
f(n) = O(g(n))
f(n) is O ("oh" or "big oh") of g(n) if and only if there exists some positive constants c and n0 such that f(n) ≤ c•g(n) whenever n > n0. In short, f(n) is bounded above by g(n) because after some point n0, g(n) will always grow at a larger asymptotic growth rate than f(n).
f(n) = Ω (g(n))
f(n) is Omega ("big omega") of g(n) if and only if there exists some positive constants c and n0 such that c•g(n) ≤ f(n) whenever n > n0. In short, f(n) is bounded below by g(n) because after some point n0, f(n) will always grow at a larger asymptotic growth rate than g(n).

The term Θ(1) time, or "constant time", is used to refer to fundamental operations that take a constant amount of time to execute (e.g.: reading a single value, performing a comparison between 2 values, checking a condition, etc.).

At a very basic level, you need to think about how many instructions your algorithm must execute in the best and worst case scenarios when processing n pieces of data. Then determine the function(s) that your algorithm is bounded above and below by, disregarding any leading constants (e.g.: 1/2, 2, etc.) or lower-order terms; basically, you don't hang on to anything that doesn't directly impact the growth rate of f(n), and you only want to retain the term that has the greatest impact on growth rate (e.g.: if f(n) = 3n7 + n + 2, then f(n) is O(n7). For example:
for(int i = 0; i < n; i++){
    for(int j = 0; j < n/2; j++){
        // Θ(1) operation
        // Θ(1) operation
        // Θ(1) operation
    }
}
In the nested loop above, there are 3 constant time operations that will be performed n × n/2 times as a result of the nested loops. Because f(n) = 3 × n × n/2 = 3/2 × n2, our code is O(n2).
Resource: Algorithms Sequential & Parallel: A Unified Approach.

Primality Algorithms
A prime number is a natural number greater than 1 that is only divisible by 1 and itself (though 1 is not a prime). A primality algorithm is an algorithm for determining if some number, n, is prime. The most basic way to do this is to iterate through each integer i (where 1 < i < n) and determine if it evenly divides n; if i is an even divisor of n, then n is not prime. While this algorithm is O(n), there are a number of optimizations you can perform that will reduce it to O(n1/2) (even that can be slightly improved upon, though we will not discuss it here). What are you waiting for? Get started on today's challenge! And, when you're done, be sure to check the Editorial for a comparison of four primality algorithms.