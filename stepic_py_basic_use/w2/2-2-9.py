# -*- coding: utf-8 -*-
# Алиса владеет интересной информацией, которую хочет заполучить Боб.
# Алиса умна, поэтому она хранит свою информацию в зашифрованном файле.
# У Алисы плохая память, поэтому она хранит все свои пароли в открытом виде в текстовом файле.

# Бобу удалось завладеть зашифрованным файлом с интересной информацией и файлом с паролями, но не смог понять какой из паролей ему нужен. Помогите ему решить эту проблему.

# Алиса зашифровала свою информацию с помощью библиотеки simple-crypt.
# Она представила информацию в виде строки, и затем записала в бинарный файл результат работы метода simplecrypt.encrypt.

# Вам необходимо установить библиотеку simple-crypt, и с помощью метода simplecrypt.decrypt узнать, какой из паролей служит ключом для расшифровки файла с интересной информацией.

# Ответом для данной задачи служит расшифрованная интересная информация Алисы.

# Файл с информацией https://stepic.org/media/attachments/lesson/24466/encrypted.bin
# Файл с паролями https://stepic.org/media/attachments/lesson/24466/passwords.txt

# Примечание:
# Для того, чтобы считать все данные из бинарного файла, можно использовать, например, следующий код:

# with open("encrypted.bin", "rb") as inp:
#     encrypted = inp.read()


# Примечание:
# ﻿Работа с файлами рассмотрена в следующем уроке, поэтому вы можете вернуться к этой задаче после просмотра следующего урока.

from simplecrypt import encrypt, decrypt

def decrypt_file(file_name, key):
    with open(file_name, 'rb') as inp:
        encrypted = inp.read()
    dec = decrypt(key, encrypted)
    print("decrypted text: %s" % dec)

passwords = [line.rstrip('\n') for line in open('passwords.txt')]
for i in passwords:
 try:
     print(i)
     decrypt_file("encrypted.bin", i)
 except:
     pass

# // RVrF2qdMpoq6Lib
# // Alice loves Bob