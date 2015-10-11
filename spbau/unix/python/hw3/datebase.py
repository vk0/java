#!/usr/bin/python

class student(object):
	def __init__(self, name):
		self.__name = name
		self.__grades = []

	def append(self, grade):
		self.__grades.append(grade)

	def extend(self, grades):
		self.__grades.extend(grades)

	def gpa(self):
		if len(self.__grades) == 0:
			return 0
		return (sum(self.__grades)/len(self.__grades))

	def __str__(self):
		string = self.__name + ': '
		for grade in self.__grades:
			string += str(grade) + ' '
		return string

	def __repr__(self):
		return self.__str__()

class datebase(object):
	def __init__(self, fname):
		f = open(fname, 'r')
		lines = f.readlines()
		self.__students = []
		for line in lines:
			temp = line.split(':')
			if len(temp) >= 1:
				st = student(temp[0])
				if len(temp) > 1:
					temp = temp[1].split()
					for grade in temp:
						st.append(int(grade))
				self.__students.append(st)
		f.close()

	def append(self, student):
		self.__students.append(student)

	def extend(self, students):
		self.__students.extend(students)

	def beststudent(self):
		if len(self.__students) == 0:
			return None
		stud = self.__students[0]
		for st in self.__students:
			if st.gpa() > stud.gpa():
				stud = st
		return stud

	def beststudents(self):
		res = []
		best = self.beststudent()
		if best:
			for st in self.__students:
				if best.gpa() == st.gpa():
					res.append(st)
		return res

	def savetofile(self, fname):
		f = open(fname, 'w')
		f.write(self.__str__())
		f.close()

	def __str__(self):
		string = ""
		for index in xrange(len(self.__students)):
			string += self.__students[index].__str__()
			if index != (len(self.__students)-1):
				string += '\n'
		return string

	def __repr__(self):
		return self.__str__()

fname = raw_input('enter filename:')
base = datebase(fname)
print base

print base.beststudents()
