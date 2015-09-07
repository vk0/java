import requests
inf = open('dataset_3378_2.txt', 'r')
url = inf.readline().strip()
r = requests.get(url)
print(len(r.text.splitlines()))