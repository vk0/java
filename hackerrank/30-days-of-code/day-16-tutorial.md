Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

String to Integer
Many languages offer some functionality for parsing an integer value from a string token. Here are a few languages and their respective integer parsing functions:

Java: Integer.parseInt(token)
C++: stoi(token)
Python: int(token)
Ruby: Integer(token)

Each of these functions will raise an error (i.e.: throw an exception) when the argument passed as the token parameter cannot be converted to an integer. Most languages have built-in exception handling methods such as try-catch or begin-rescue that enable you to code specific behaviors to handle execution issues.

Exceptions
If your code attempts to perform an action that cannot be completed, the flow of control is halted and an exception is thrown. This means that an Exception object is created as a response to this unusual condition. The control flow is then transferred (or handed off) to an exception handler. By anticipating and writing handlers for exceptional conditions in your program's logic, you can resolve the issue that raised the exception and your program can continue executing. A program "crash" is generally the result of an unhandled exception.

Exception handling is expensive, meaning it takes a lot of behind-the-scenes work for your program to stop everything and figure out how an exceptional scenario should be handled. Under normal circumstances, you can avoid the need to handle many kinds of exceptions by anticipating and coding for all possible scenarios.

Managing Exceptions: try
The try block is like a staging area for potentially error-raising code. If your program is unable to execute the code inside a try block, it throws an exception and tries to find an exception handler to salvage the situation. The syntax is as follows:
try{
    // write exception-throwing code here
}

Managing Exceptions: catch
A catch block should always immediately follow a try block, and looks like a sort of mini-function. It must take some type of exception (either Exception or one of its subclasses) as a parameter, and it looks like this:
catch(Exception e){
    // write exception handling logic here
}
Part of writing good code is knowing, circumventing, and anticipating exactly what type of exceptions your instructions might throw, but if your parameter is of type Exception, it will catch any exception that is a subclass of Exception. If the code in your try block has the potential to throw more than one type of exception, you can have multiple catch blocks to catch each type of anticipated exception.

Managing Exceptions: finally
The finally block immediately follows the catch block, and will always execute when the try block exits—regardless of whether or not an exception is thrown. The finally block is optional, and generally used for cleanup code.

Managing Exceptions: try with resources
This is useful when you are using a resource that must be opened/closed (anything that implements java.lang.AutoCloseable or java.io.Closeable), such as a Scanner or BufferedReader. While you will likely never need try-with-resources blocks for our challenges, it's still worth knowing about.
try(Scanner scan = new Scanner();){
    // use scanner to do something that potentially throws an exception
}

Example
The code below demonstrates how the try, catch, and finally blocks handle errors in bad code:
import java.util.*;

class Solution{
    LinkedList<String> list;
    int[] intArray = new int[4];

    // For testing Null Pointer Exception
    Solution(){
        this.list = null;
    }

    // For testing Index Out of Bounds
    Solution(String str){
        this.list = new LinkedList<String>();
        list.add(str);
    }

    void exceptionDemo(int i, String str){

        try{
            // throws ArrayIndexOutOfBoundsException if index > intArray.length
            int myInt = intArray[i];

            // throws a NullPointerException if 'list' doesn't point to an actual list object
            list.indexOf(str);
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.err.println( "The following index is out-of-bounds: " + e.getMessage() );
        }
        catch(NullPointerException e){
            System.err.println( "Oh no! You tried to perform an operation on an object whose value is null!" );
        }
        finally{
            System.out.println("This is printing regardless of whether or not the program finishes executing.");
        }
        System.out.println("The program was able to continue execution!\n");
    }

    public static void main(String[] args) {
        // creates a Solution object whose 'list' instance variable points to null:
        Solution sNullList = new Solution();
        // attempt to access an element of the null list, throws Exception
        sNullList.exceptionDemo(1, "x");

        // creates a Solution object whose 'list' instance variable points to a list containing 1 element ("x"):
        Solution sNotNullList = new Solution("x");
        // attempt to access an invalid index of 'intArray' instance variable, throws Exception
        sNotNullList.exceptionDemo(100, "x");
    }
}
Produces the following output:
Oh no! You tried to perform an operation on an object whose value is null!
This is printing regardless of whether or not the program finishes executing.
The program was able to continue execution!

The following index is out-of-bounds: 100
This is printing regardless of whether or not the program finishes executing.
The program was able to continue execution!
If you were to comment out the first catch block:
catch(ArrayIndexOutOfBoundsException e){
    System.err.println( "The following index is out-of-bounds: " + e.getMessage() );
}
Your output would be:
Oh no! You tried to perform an operation on an object whose value is null!
This is printing regardless of whether or not the program finishes executing.
The program was able to continue execution!

This is printing regardless of whether or not the program finishes executing.
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 100
    at Solution.exceptionDemo(Solution.java:22)
    at Solution.main(Solution.java:48)
If you were to comment out the second catch block:
catch(NullPointerException e){
    System.err.println( "Oh no! You tried to perform an operation on an object whose value is null!" );
}
Your output would be:
This is printing regardless of whether or not the program finishes executing.
Exception in thread "main" java.lang.NullPointerException
    at Solution.exceptionDemo(Solution.java:25)
    at Solution.main(Solution.java:43)