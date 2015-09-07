import requests
inf = open('dataset_3378_3.txt', 'r')
url = inf.readline().strip()
r = requests.get(url)
first = r.text
def crawler(url):
    req = requests.get('https://stepic.org/media/attachments/course67/3.6.3/'+url)
    if "We" in req.text:
        print(req.text)
    else:
        crawler(req.text)

crawler(first)