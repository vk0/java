# # -*- coding: utf-8 -*-
# Objective
# Today, we're delving into Inheritance. Check out the Tutorial tab for learning materials and an instructional video!

# Task
# You are given two classes, Person and Student, where Person is the base class and Student is the derived class. Completed code for Person and a declaration for Student are provided for you in the editor. Observe that Student inherits all the properties of Person.

# Complete the Student class by writing the following:

# A Student class constructor, which has 44 parameters:
# A string, firstNamefirstName.
# A string, lastNamelastName.
# An integer, idid.
# An integer array (or vector) of test scores, scoresscores.
# A char calculate() method that calculates a Student object's average and returns the grade character representative of their calculated average:
# Grading.png

# Input Format

# The locked stub code in your editor calls your Student class constructor and passes it the necessary arguments. It also calls the calculate method (which takes no arguments).

# You are not responsible for reading the following input from stdin:
# The first line contains firstNamefirstName, lastNamelastName, and idid, respectively. The second line contains the number of test scores. The third line of space-separated integers describes scoresscores.

# Constraints

# 4≤|firstName|,|lastName|≤104≤|firstName|,|lastName|≤10
# |id|≡7|id|≡7
# 0≤score,average≤1000≤score,average≤100
# Output Format

# This is handled by the locked stub code in your editor. Your output will be correct if your Student class constructor and calculate() method are properly implemented.

# Sample Input

# Heraldo Memelli 8135627
# 2
# 100 80
# Sample Output

#  Name: Memelli, Heraldo
#  ID: 8135627
#  Grade: O
# Explanation

# This student had 22 scores to average: 100100 and 8080. The student's average grade is (100+80)2=90(100+80)2=90. An average grade of 9090 corresponds to the letter grade OO, so our calculate() method should return the character'O'.


class Person:
    def __init__(self, firstName, lastName, idNumber):
        self.firstName = firstName
        self.lastName = lastName
        self.idNumber = idNumber
    def printPerson(self):
        print("Name:", self.lastName + ",", self.firstName)
        print("ID:", self.idNumber)


class Student(Person):
    def __init__(self, firstName, lastName, idNum, scores):
            Person.__init__(self, firstName, lastName, idNum)
            self.temp = [int(x) for x in scores]
            self.score = sum(self.temp)/len(self.temp)
    def calculate(self):
        if self.score < 40:
            return 'T'
        elif self.score >= 40 and self.score < 55:
            return 'D'
        elif self.score >= 55 and self.score < 70:
            return 'P'
        elif self.score >= 70 and self.score < 80:
            return 'A'
        elif self.score >= 80 and self.score < 90:
            return 'E'
        elif self.score >= 90 and self.score <= 100:
            return 'O'

line = input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]
numScores = int(input()) # not needed for Python
scores = input().split()
s = Student(firstName, lastName, idNum, scores)
s.printPerson()
print("Grade:", s.calculate())


# class Student(Person):
#     def __init__(self, firstName, lastName, idNum, scores):
#             Person.__init__(self, firstName, lastName, idNum)
#             self.temp = [int(x) for x in scores]
#             self.score = sum(self.temp)/len(self.temp)
#     def calculate(self):
#         if self.score < 40:
#             return 'T'
#         elif self.score >= 40 and self.score < 55:
#             return 'D'
#         elif self.score >= 55 and self.score < 70:
#             return 'P'
#         elif self.score >= 70 and self.score < 80:
#             return 'A'
#         elif self.score >= 80 and self.score < 90:
#             return 'E'
#         elif self.score >= 90 and self.score <= 100:
#             return 'O'