Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Radix (Base)
The number of digits that can be used to represent a number in a positional number system. The decimal number system (base-10) has 10 digits (0,1,2,3,4,5,6,7,8,9); the binary (base-2) number system has 2 digits (0,1).

We think in terms of base-10, because the decimal number system is the only one many people need in everyday life. For situations where there is a need to specify a number's radix, number n having radix r should be written as (n)r.

Binary to Decimal Conversion
In the same way that (840)10 = (8 × 102) + (4 × 101) + (0 × 100) = 800 + 40 + 0 = 840, a binary number having k digits in the form of dk-1dk-2 … d2d1d0 can be converted to decimal by summing the result for each di × 2i where 0 ≤ i ≤ k-1, i=k-1 is the most significant bit, and i=0 is the least significant bit.

For example: (1011)2 → (?)10 is evaluated as (1 × 23)+(0 × 22)+(1 × 21)+(1 × 20) = 8 + 0 + 2 + 1 = (11)10

Decimal to Binary Conversion
To convert an integer from decimal to binary, repeatedly divide your base-10 number, n, by 2. The dividend at each step i should be the result of the integer division at each step i-1. The remainder at each step of division is a single digit of the binary equivalent of n; if you then read each remainder in order from the last remainder to the first (demonstrated below), you have the entire binary number.

For example: (4)10 → (?)2. After performing the steps outlined in the above paragraph, the remainders form (100)2 (the binary equivalent of (4)10) when read from the bottom up:
4 ÷ 2 = 2 remainder 0 ↑
2 ÷ 2 = 1 remainder 0 ↑
1 ÷ 2 = 0 remainder 1 ↑

This can be expressed in pseudocode as:
while(n > 0):
    remainder = n%2;
    n = n/2;
    Insert remainder to front of a list or push onto a stack

Print list or stack

Many languages have built-in functions for converting numbers from decimal to binary. To convert an integer, n, from decimal to a String of binary numbers in Java, you can use the Integer.toBinaryString(n) function.

Note: The algorithm discussed here is for converting integers; converting fractional numbers is a similar (but different) process.