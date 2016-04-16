Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Map
This is an interface that provides a blueprint for data structures that take (Key, Value) pairs and map Keys to their associated Values. The implementation is done by implementing classes such as HashMap or LinkedHashMap. Consider the following code:
Map myMap<String,String>; // declare a String to String map
myMap = new HashMap<String,String>(); // initialize it as a new String to String HashMap
myMap = new LinkedHashMap<String,String(); // change myMap to be a new (completely different) String to String LinkedHashMap instead

Here are a few Map methods you will find helpful for this challenge:
containsKey(Object key): Returns true if the map contains a mapping for key; returns false if there is no such mapping.
get(Object key): Returns the value to which the key is mapped; returns null if there is no such mapping.
put(K key, V value): Adds the (Key, Value) mapping to the Map; if the Key is already in the map, the Value is overwritten.

Example
The code below:
// Create a Map of String Keys to String Values, implemented by the HashMap class
Map<String,String> myMap = new HashMap<String,String>();

myMap.put("Hi", "Bye"); // Adds ("Hi","Bye") mapping to myMap
System.out.println(myMap.get("Hi")); // Print the Value mapped to from "Hi"
myMap.put("Hi", "Bye!"); // Replaces "Bye" mapping from "Hi" with "Bye!"
System.out.println(myMap.get("Hi")); // Print the Value mapped to from "Hi"
produces the following output:
Bye
Bye!
It is not necessary to declare myMap as type Map; you can certainly declare it as a HashMap (the instantiated type).

Additional Language Resources
Python Dictionary Documentation
C++ Unordered Map Documentation, Map Constructor
C# Dictionary Documentation