Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Strings and Characters
As we've mentioned previously, a String is a sequence of characters. In the same way that words inside double quotes signify a String, a single letter inside single quotes signifies a character. Each character has an ASCII value associated with it, which is essentially a numeric identifier. The code below creates a char variable with the value c, and then prints its ASCII value.
char myChar = 'c'; // create char c
System.out.println("The ASCII value of " + myChar + " is: " + (int) myChar);
Output:
The ASCII value of c is: 99

Observe the (int) before the variable name in the code above. This is called casting, which is a method of representing one thing as another. Putting a data type inside parentheses right before a variable is essentially saying: "The next thing after this should be represented as this data type".

Hint: You may find the String.toCharArray method helpful in this challenge.