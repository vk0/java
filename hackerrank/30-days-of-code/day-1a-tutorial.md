Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).


Data Types
Data types define and restrict what type values can be stored in a variable, as well as set the rules for what types of operations can be performed on it.

Primitive Data Types
Java has 8 primitive data types: byte, short, int, long, float, double, boolean, and char. For most challenges, you'll only need to concern yourselves with ints (e.g.: 1, 2, 3, etc.) and doubles (e.g.: 1.0, 2.5, 3.9, etc.). Another important data type we mentioned yesterday is the String class, whose objects are immutable strings of characters.

Scanner
Yesterday, we discussed Scanner's next, nextLine, hasNext, and hasNextLine methods. Scanner also has readNext/hasNext methods for different data types, which is very helpful when you know exactly what type of input you'll be reading. The next methods scan for tokens (you can think of this as a word), and the nextLine methods reads from the Scanner's current location until the beginning of the next line. For example, nextInt() will scan the next token of input as an int, and nextDouble() will scan the next token of input as a double.
Each line of multi-line input contains an invisible separator indicating that the end of a line of input has been reached. When you use Scanner functions that read tokens (e.g.: next(), nextInt(), etc.), the Scanner reads and returns the next token. When you read an entire line (i.e.: readLine()), it reads from the current position until the beginning of the next line. Because of this, a call to nextLine() may return an empty string if there are no characters between the end of the last read and the beginning of the next line. For example, given the following input:
a b c
d e
f
g
The breakdown below shows how the following sequence of calls to a Scanner object, scan, will read the above input:
A call to scan.next(); will return the next token, a.
A call to scan.next(); will return the next token, b.
A call to scan.nextLine(); will return the next token, c. Observe that the scanner reads a space and a letter, because it's reading from the end of the last token until the beginning of the next line.
A call to scan.nextLine(); will return the contents of the next line, d e.
A call to scan.next(); will read and return the next token, f.
A call to scan.nextLine(); will return everything after f until the beginning of the next line; because there are no characters there, it returns an empty String.
A call to scan.nextLine(); will return g.

Additive Operator
The + operator is used for mathematical addition and String concatenation (i.e.: combining two Strings into one new String). If you add the contents of two variables together (e.g.: a + b), you can assign their result to another variable using the assignment operator (=). You can also pass the result to a function instead of assigning it to a variable; for example, if a = 1 and b = 2, System.out.println(a+b); will print 3 on a new line.