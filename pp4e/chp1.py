bob = ['Bob Smith', 42, 37500.0, 'software']
sue = ['Sue Max', 22, 20000, 'model']

people = [bob, sue]

pays = [person[2] for person in people]
#print(pays)

print(sum(person[2] for person in people))

people.append(['Tom Sox',30,123100,None])

for person in people:
    print(person[0])
