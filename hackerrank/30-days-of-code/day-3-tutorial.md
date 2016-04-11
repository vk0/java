Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Boolean
A logical statement that evaluates to true or false. In some languages, true is interchangeable with the number 1 and false is interchangeable with the number 0.

Conditional Statements
These are a way of programming different workflows depending on some boolean condition. The if-else statement is probably the most widely used conditional in programming, and its workflow is demonstrated below:
332px-If-Then-Else-diagram.svg.png
Image Source: Wikipedia(Conditional Statements)

The basic syntax used by Java (and many other languages) is:
if(condition){
    // do this if 'condition' is true
}
else{
    // do this if 'condition' is false
}
You can also use an if without an else, or follow an if(condition) with else if(secondCondition) if you have a second condition that only need be checked when condition is false. If the if (or else if) condition evaluates to true, any other sequential statements connected to it (i.e.: else or an additional else if) will not execute.

Logical Operators
Customize your condition checks by using logical operators. Here are the three to know:
OR (||), also known as logical disjunction
AND (&&), also known as logical conjunction
NOT (!), also known as negation

Here are some usage examples:
// if A is true and B is true, then C
if(A && B){
    C;
}

// if A is true or B is true, then C
if(A || B){
    C;
}

// if A is false (i.e.: not true), then B
if(!A){
    B;
}

Another great operator is the ternary operator for conditional statements (? :). Let's say we have a variable, v, and a condition, c. If the condition is true, we want v to equal a; if the condition is false, we want v to equal b. We can write this with the following simple statement:
v = c ? a : b;

Switch Statement
This is a great control structure for when your control flow depends on a number of known values. Let's say we have a variable, condition, whose possible values are val0, val1, val2, and each value has an action to perform (which we will call behavior). We can switch between actions with the following code:
switch (condition) {
    case val0:  behavior0;
                break;
    case val1:  behavior1;
                break;
    case val2:  behavior2;
                break;
    default:    behavior;
                break;
}
Note: Unless you include break; at the end of each case statement, the statements will execute sequentially. Also, while it's good practice to include a default: case (even if it's just to print an error message), it's not strictly necessary.

Additional Language Resources
C++ Statements and Flow Control
Python Control Flow Tools
