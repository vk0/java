import shelve
from person import Person
from manager import Manager

bob = Person('Bob smith', 42, 30000, 'soft')
sue = Person('Sue Jones', 45, 40000, 'hard')
tom = Manager('Tom Dom', 50, 50000)

db = shelve.open('class-shelve')
db['bob'] = bob
db['sue'] = sue
db['tom'] = tom
db.close()