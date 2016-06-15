# Write a program that given a text file will create a new text file 
# in which all the lines from the original file are numbered from 1 to n 
# (where n is the number of lines in the file).

def number_lines(file_name):
    lines = []

    file = open(file_name, 'r')
    for line in file:
        lines.append(line)
    file.close()

    new_file_name = "new_" + file_name

    new_file = open(new_file_name, 'w')
    for n, line in enumerate(lines):
        new_file.write(str(n + 1) + " " + line)

# test
number_lines("sample.txt")
