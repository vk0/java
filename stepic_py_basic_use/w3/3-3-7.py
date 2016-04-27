# -*- coding: utf-8 -*-
# Вашей программе на вход подается ссылка на HTML файл.
# Вам необходимо скачать этот файл, затем найти в нем все ссылки вида <a ... href="..." ... > и вывести список сайтов, на которые есть ссылка.

# Сайтом в данной задаче будем называть имя домена вместе с именами поддоменов. То есть, это последовательность символов, которая следует сразу после символов протокола, если он есть, до символов порта или пути, если они есть.﻿

# Сайты следует выводить в алфавитном порядке.

# Пример HTML файла:

# <a href="http://stepic.org/courses">
# <a href='https://stepic.org'>
# <a href='http://neerc.ifmo.ru:1345'>
# <a href="ftp://mail.ru/distib" >
# <a href="ya.ru">
# <a href="www.ya.ru">

# Пример ответа:

# mail.ru
# neerc.ifmo.ru
# stepic.org
# www.ya.ru
# ya.ru

import requests
import re
# url = input()
url = "http://ya.ru"

res = requests.get(url)
# print(res.status_code)
# print(res.headers['Content-Type'])
# print(res.url)
html = res.text
# links = re.findall('"((http|ftp)s?://.*?)"', html)
# print(links)

regexp_link = r'''</?a((s+w+(s*=s*(?:".*?"|'.*?'|[^'">s]+))?)+s*|s*)/?>w+</a>'''
pattern = re.compile(regexp_link)
links = re.findall(pattern, html)

#print all matches
print(links)

# link_list = re.findall(r"(?<=href=\").+?(?=\")|(?<=href=\').+?(?=\')", html)
# link_list = re.findall(r'href=[\'"]?([^\'" >]+)', html)
# # for url in link_list:
# print(link_list)


# linkregex = re.compile('<a\s*href=[\'|"](.*?)[\'"].*?>')
# links = linkregex.findall(html)
# # links = re.findall(r"<a.*?\s*href=\"(.*?)\".*?>(.*?)</a>", html)
# print(links)
# for link in links:
    # print('href: %s, HTML text: %s' % (link[0], link[1]))