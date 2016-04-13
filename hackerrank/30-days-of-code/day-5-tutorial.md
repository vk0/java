Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate). As you code more, you may see these loops implemented in different ways than are shown here.

For Loop
This is an iterative loop that is widely used. The basic syntax is as follows:
for (initialization; termination; increment) {
    ...
}
The initialization component is the starting point in your iteration, and your code for this section will typically be int i = 0. When we declare and initialize int i in the loop like this, we are creating a temporary variable that exists only inside this loop for the purposes of iterating through the loop; once we finish iterating and exit (or break) the loop, i is deleted and can be declared elsewhare in our program.

The termination component is the condition which, once met, you would like to exit (or break) the loop and proceed to the next line in your code. This is the ending point fr your loop, and is typically written as i < endValue, where i is the variable from the initialization section and endValue is some variable holding the stopping point for your iteration.

The increment component is executed each time the end of the code inside the loop's brackets is reached, and should generally be some modification on the initialization variable that brings it closer to the termination variable. This will typically be i++. The ++ operator is also called the post-increment operator, and it will increment a variable by 1 after a line executes (for more detail and an example, see the While section).

To recap, this sample code:
int endOfRange = 4;
for(int i = 0; i < endOfRange; i++){
    System.out.println(i);
}
produces this output:
0
1
2
3

While Loop
This type of loop requires a single boolean condition and continues looping as long as that condition continues to be true. Each time the the end of the loop is reached, it loops back to the top and checks if the condition is still true. If it's true, the loop will run again; if it's false, then the program will skip over the loop and continue executing the rest of the code.

Much like in the For section, the code below prints the numbers 0 through 3. Notice that we are using the post-increment operator on min:
int min = 0;
int max = 4;
while(min < max){
    System.out.println(min++);
}
Once min ≥ max, the boolean condition (min < max) evaluates to false and the loop is broken. The line System.out.println(min++); is a compact way of writing:
System.out.println(min);
min = min + 1;

Do-While Loop
This is a variation on the While loop where the condition is checked at the end of the brackets. Because of this, the content between the brackets is guaranteed to always be executed at least once:
do{
    // this will execute once
    // it will execute again each time while(condition) is true
} while(condition);

Unlabeled Break
You may recall the word break; from our previous discussion of Switch Statements. It will break you out of a loop even if the loop's termination condition still holds true.

Additional Language Resources
C++ Loops
Python While Statement