# Вам дано описание наследования классов в следующем формате.
# <имя класса 1> : <имя класса 2> <имя класса 3> ... <имя класса k>
# Это означает, что класс 1 отнаследован от класса 2, класса 3, и т. д.

# Или эквивалентно записи:

# class Class1(Class2, Class3 ... ClassK):
#     pass

# Класс A является прямым предком класса B, если B отнаследован от A:

# class B(A):
#     pass



# Класс A является предком класса B, если

#     A = B;
#     A - прямой предок B
#     существует такой класс C, что C - прямой предок B и A - предок C


# Например:

# class B(A):
#     pass

# class C(B):
#     pass

# # A -- предок С



# Вам необходимо отвечать на запросы, является ли один класс предком другого класса

# Важное примечание:
# Создавать классы не требуется.
# Мы просим вас промоделировать этот процесс, и понять существует ли путь от одного класса до другого.
# Формат входных данных

# В первой строке входных данных содержится целое число n - число классов.

# В следующих n строках содержится описание наследования классов. В i-й строке указано от каких классов наследуется i-й класс. Обратите внимание, что класс может ни от кого не наследоваться. Гарантируется, что класс не наследуется сам от себя (прямо или косвенно), что класс не наследуется явно от одного класса более одного раза.

# В следующей строке содержится число q - количество запросов.

# В следующих q строках содержится описание запросов в формате <имя класса 1> <имя класса 2>.
# Имя класса – строка, состоящая из символов латинского алфавита, длины не более 50.
# Формат выходных данных

# Для каждого запроса выведите в отдельной строке слово "Yes", если класс 1 является предком класса 2, и "No", если не является.

# Sample Input:

# 4
# A
# B : A
# C : A
# D : B C
# 4
# A B
# B D
# C D
# D A

# Sample Output:

# Yes
# Yes
# Yes
# No

classspace = {}
parent_t = False

def create(n_class, parent):
    global classspace
    classspace.update({n_class: {'parent': parent}})
    return

def isParent(parent, n_class):
    if (classspace[n_class]['parent'] == None):
        # print("No")
        return
    elif (classspace[n_class]['parent'].count(parent) > 0):
        global parent_t
        parent_t = True
        return
    else:
        for i in range(len(classspace[n_class]['parent'])):
            isParent(parent, classspace[n_class]['parent'][i])


for _ in range(int(input())):
    strclass = input().split()
    if (len(strclass) == 1):
        create(strclass[0], None)
    else:
        create(strclass[0], strclass[2:])

for _ in range(int(input())):
    parent_t = False
    a = input().split()
    if (a[0] == a[1]):
        print("Yes")
    else:
        isParent(*a)
        if (parent_t):
            print("Yes")
        else:
            print("No")