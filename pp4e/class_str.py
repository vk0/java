class Person:
    def __init__(self, name, age, pay=0, job=None):
        self.name = name
        self.age = age
        self.pay = pay
        self.job = job
    def __str__(self):
        for i in self.__dict__:
            print(i)
            return '<%s => %s' % (self.__class__.__name__, self.name)

tom = Person('Tom', 50)
print(tom)