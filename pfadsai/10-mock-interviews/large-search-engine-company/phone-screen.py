# Phone Screen

# This phone screen will consist of a non-technical series of questions about you and the company, and then a second half of a simple technical question to be coded out

# Non-Technical Questions
# Answer the following questions (2-5 minute responses) technical answers not required, more interested in hearing about your reasoning
# Give me some quick background about you (go over your resume)
# Why do you want to work here?
# What's your favorite programming language and why?
# Where do you see yourself in 5 years?
# Do you have any questions about the company for me?

# Solution
# There aren't really any "correct" answers here, just make sure you're prepared to answer the following questions about the company you're interviewing with. Be honest, friendly and ready to defend any statements you make with logical arguments to back them up. Note, you should ALWAYS have follow-up questions.

# Technical Questions
# Answer the following question in the Markdown cell below. It's important to note that the cell below does NOT have syntax highlighting, its common in a phone screen interview to be given a text editor hich doesn't have anything more than basic text support

# Write a function that computes the Nth fibonacci number

# Solution
# There's many ways to answer this question, you might be required to solve it multiple ways and discuss some pros and cons of each way. Listed below are various solutions

## Example 1: Using looping technique
def fib(n):

    a,b = 1,1
    for i in range(n-1):
        a,b = b,a+b
    return a

print fib(7)

# Using recursion
def fibR(n):
    if n==1 or n==2:
        return 1
    return fib(n-1)+fib(n-2)

print fibR(7)

## Example 3: Using generators
a,b = 0,1
def fibI():
    global a,b
    while True:
        a,b = b, a+b
        yield a
f=fibI()
f.next()
f.next()
f.next()
f.next()
f.next()
f.next()
print f.next()


## Example 4: Using memoization
def memoize(fn, arg):
    memo = {}
    if arg not in memo:
        memo[arg] = fn(arg)
    return memo[arg]

## fib() as written in example 1.
fibm = memoize(fib,7)
print fibm

## Example 5: Using memoization as decorator
class Memoize:
    def __init__(self, fn):
        self.fn = fn
        self.memo = {}
    def __call__(self, arg):
        if arg not in self.memo:
            self.memo[arg] = self.fn(arg)
            return self.memo[arg]

@Memoize
def fib(n):
    a,b = 1,1
    for i in range(n-1):
        a,b = b,a+b
    return a
print fib(7)
# 13
# 13
# 13
# 13
# 13

# Below is a table depicting averaged relative performance time in seconds over 10 runs to caluclate the 15000th fibonacci number.
# Fib(n=15000)
# loops   recursion   generators  memoization memoization as decorator
# 45  87  58  44  43
# 47  88  58  42  42
# 51  92  60  44  43
# 43  87  58  42  43
# 48  92  61  42  44
# 45  87  59  43  44
# 44  85  57  42  44
# 44  87  62  43  43
# 48  86  59  42  43
# 45  91  61  45  45
# 46  88.2    59.3    42.9    43.4 (Avg)