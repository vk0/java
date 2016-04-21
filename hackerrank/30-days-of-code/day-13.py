# -*- coding: utf-8 -*-
# Objective
# Today, we're taking what we learned yesterday about Inheritance and extending it to Abstract Classes. Because this is a very specific Object-Oriented concept, submissions are limited to the few languages that use this construct. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# Given a Book class and a Solution class, write a MyBook class that does the following:

# Inherits from Book
# Has a parameterized constructor taking these 33 parameters:
# string titletitle
# string authorauthor
# int priceprice
# Implements the Book class' abstract display() method so it prints these 33 lines:
# Title:Title:, a space, and then the current instance's titletitle.
# Author:Author:, a space, and then the current instance's authorauthor.
# Price:Price:, a space, and then the current instance's priceprice.
# Note: Because these classes are being written in the same file, you must not use an access modifier (e.g.: publicpublic) when declaring MyBook or your code will not execute.

# Input Format

# You are not responsible for reading any input from stdin. The Solution class creates a Book object and calls the MyBook class constructor (passing it the necessary arguments). It then calls the display method on the Book object.

# Output Format

# The void display()void display() method should print and label the respective titletitle, authorauthor, and priceprice of the MyBook object's instance (with each value on its own line) like so:

# Title: $title
# Author: $author
# Price: $price
# Note: The $$ is prepended to variable names to indicate they are placeholders for variables.

# Sample Input

# The following input from stdin is handled by the locked stub code in your editor:

# The Alchemist
# Paulo Coelho
# 248
# Sample Output

# The following output is printed by your display() method:

# Title: The Alchemist
# Author: Paulo Coelho
# Price: 248

from abc import ABCMeta, abstractmethod
class Book(object, metaclass=ABCMeta):
    def __init__(self,title,author):
        self.title=title
        self.author=author
    @abstractmethod
    def display(): pass


class MyBook(Book):
    def __init__(self, title, author, price):
        Book.__init__(self, title, author)
        self.price = price

    def display(self):
        print('Title: ' + self.title)
        print('Author: ' + self.author)
        print('Price:', self.price)

title=input()
author=input()
price=int(input())
new_novel=MyBook(title,author,price)
new_novel.display()