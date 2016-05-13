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
res = requests.get(input().rstrip())
linkset = set()

if res.status_code == 200:

    pattern = re.compile(r'(?:<a.+?href=.)(\w.+?)(?:[\S\s]>)', re.IGNORECASE)
    pattern2 = re.compile(r'^(?:\w+://|\b)(.+?)(?:["\'\ ].*|[/:].*|\b)$', re.IGNORECASE)
    match = pattern.findall(res.text)

    for i in match:
        match2 = pattern2.findall(i)
        linkset.add(match2[0])

for i in sorted(list(linkset)):
    print(i)