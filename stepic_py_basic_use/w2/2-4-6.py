# -*- coding: utf-8 -*-
# Вам дана в архиве (ссылка) файловая структура, состоящая из директорий и файлов.
# https://stepic.org/media/attachments/lesson/24465/main.zip

# Вам необходимо распаковать этот архив, и затем найти в данной в файловой структуре все директории, в которых есть хотя бы один файл с расширением ".py".

# Ответом на данную задачу будет являться файл со списком таких директорий, отсортированных в лексикографическом порядке.

# Для лучшего понимания формата задачи, ознакомьтесь с примером.
# Пример архива https://stepic.org/media/attachments/lesson/24465/sample.zip
# Пример ответа https://stepic.org/media/attachments/lesson/24465/sample_ans.txt

# unzip main.zip
# find main/ -type f -name "*.py" | xargs -I{} dirname {}|sort|uniq

import os.path

with open('2-4-6.list', 'w') as f:
    f.write("\n".join(sorted([dir.replace('\\', '/').replace('./main', 'main') for dir, _, dirfiles in os.walk('./main') if len([file for file in dirfiles if os.path.splitext(file)[1] == '.py']) > 0])))