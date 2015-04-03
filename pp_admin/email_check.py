import re

def check_email(email):
    if len(email) > 7:
        if re.match("^.+\\@(\\[?)[a-zA-Z0-9\\-\\.]+\\.([a-zA-Z]{2,3}|[0-9]{1,3})(\\]?)$", email) != None:
            return "Fail"
    return "OK"

ok = check_email('ekoz@yandex-team.ru')
print ok
