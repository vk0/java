Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate). When you're done reading, we recommend you spend some time experimenting with regular expressions using Rubular.

Regular Expressions (RegEx)
This is a means of describing a set of strings using a subset of common characteristics. For example, the common characteristics of aaa, aba, and aca are that they all start and end with the letter a.

Regular expressions add a level of abstraction to strings that makes it easier to search and manipulate text. While they can seem very confusing at first, the syntax for regular expressions is pretty standard across different programming languages (so knowledge of RegEx is universally applicable).

Character Classes
This is not a class in the traditional sense, but rather a term that refers to a set of one or more characters that can be used to match a single character from some input string. Here are the basic forms:
Enclosed within square brackets. Specify the what you'd like your expression to match within square brackets; for example, [a-f] will match any lowercase a through f character.
Predefined: \ followed by a letter. For example, \d for matching digits (0-9) or \D for matching non-digits. There are also additional predefined character classes that are followed by a set of curly braces, such as \p{Punct} which matches punctuation (i.e.: !"#$%&'()*+,-./:;<=>?@[]^_`{|}~).

Some key constructs to know are:
. The period will match any character; it does not have to be a letter.
+ When appended to a character or character class, it means 'one or more instances of the previous character'.
* When appended to a character or character class, it means 'zero or more instances of the previous character'.
^ if this is before a character class, it means you're matching the first character; however, if this is the first character inside a bracketed character class, it means negation/not. For example, ^[a].+ or ^a.+ matches any consecutive sequence of 2 or more characters starting with the letter a, and ^[^a].+ matches any consecutive sequence of 2 or more characters not starting with a.
$ When appended to a character or character class, it means 'ends with the previous character'. For example, .+a$ will match a sequence of 2 or more characters ending in a.

Java's Pattern class documentation is a really handy reference for predefined character classes, but there are also many other RegEx resources available throughout the internet.

Coding With RegEx
When using regular expressions in your code, you need to remember that the \ character is an escape character. This means that whenever \ is occurs in a string (or as part of a char), it's a sort of flag indicating you may be trying to write a special instruction.

For example, when printing a string containing the newline character (\n); the backslash tells the compiler that you're writing a special instruction, and the n immediately following it indicates that your instruction is that it be a newline character. If your intent is to have the literal backslash character in your string, then you must write it as \\. When writing a RegEx string in code, you need your predefined character classes to be part of the string so you must precede them with an additional backslash. For example, a string intended to be used as a regex containing the \d character class must be written as "\\d".

For Java, the important classes to know are Pattern and Matcher. A Pattern object is a compiled representation of a regular expresson. To create a Pattern object, you must invoke one of its static compile methods (usually Pattern.compile(String regex)). You must then create a Matcher object that matches your Pattern object (compiled RegEx) to the String you want to check. To do this, you must invoke Pattern's matcher method on your Pattern object and assign it to a variable of type Matcher. Once created, a Matcher object can be used to perform matching operations.
// This will match a sequence of 1 or more uppercase and lowercase English letters as well as spaces
String myRegExString = "[a-zA-Z\\s]+";

// This is the string we will check to see if our regex matches:
String myString = "The quick brown fox jumped over the lazy dog...";

// Create a Pattern object (compiled RegEx) and save it as 'p'
Pattern p = Pattern.compile(myRegExString);

// We need a Matcher to match our compiled RegEx to a String
Matcher m = p.matcher(myString);

// if our Matcher finds a match
if( m.find() ) {
    // Print the match
    System.out.println( m.group() );
}

The code above prints:
The quick brown fox jumped over the lazy dog
Notice that the ellipsis (...) at the end of the myString was not printed as part of the match; that is because myRegExString only matches lowercase and uppercase English letters and spaces—not punctuation. Thus, the ellipsis serves as a boundary for the end of our matched text.

For a string with more parts, you could do something like the following code which matches strings of one or more sequential alphanumeric characters:
String s = "Hello, Goodbye, Farewell";
Pattern p = Pattern.compile("\\p{Alpha}+");
Matcher m = p.matcher(s);

while( m.find() ){
    System.out.println(m.group());
}

This loops through the string, finds each match, and prints it:
Hello
Goodbye
Farewell

String Functions
Regular expressions can be pretty confusing, especially to new coders. Fortunately, there are still some workarounds using simpler regular expressions that you may find a little easier to use. If you know something about the structure of the strings you'll be working with (i.e.: that they all follow the same format), you can use a split method (e.g.: String.split(String regex) in Java, strtok in C++, str.split() in Python, split in Ruby, etc.). If you're able to section/cut your input string into components, then you can choose the pieces you want to use. For example, the code below splits two strings at a delimiter (a comma followed by a space) and puts whatever falls between the delimiter into an array:

String s1 = "Hello, Goodbye, Farewell";
String s2 = "Hola, Adios, Hasta Luego";

String myDelimiter = ", ";

String[] s1array = s1.split(myDelimiter);
String[] s2array = s2.split(myDelimiter);

System.out.println("s1array[0]: " + s1array[0]);
System.out.println("s1array[1]: " + s1array[1]);
System.out.println("s1array[2]: " + s1array[2]);
System.out.println("s2array[0]: " + s2array[0]);
System.out.println("s2array[1]: " + s2array[1]);
System.out.println("s2array[2]: " + s2array[2]);

The above code prints:
s1array[0]: Hello
s1array[1]: Goodbye
s1array[2]: Farewell
s2array[0]: Hola
s2array[1]: Adios
s2array[2]: Hasta Luego

Note: This only really makes sense to do when you know that the input strings follow a uniform format. You may also find the replaceAll method helpful when using this approach.

Additional Resources
The Java Tutorials - Lesson: Regular Expressions
Practice RegEx with Rubular
