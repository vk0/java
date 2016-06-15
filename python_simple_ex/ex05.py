# Write a function translate() that will translate a text into "rovarspraket" (Swedish for "robber's language"). That is, double every consonant and place an occurrence of "o" in between. For example, translate("this is fun") should return the string "tothohisos isos fofunon".

import string

cons = "bcdfghjklmnpqrstvwxyz"

def translate(text):
    res = ""

    for ltr in text:
        if ltr.lower() in cons:
            res += ltr + "o" + ltr
        else:
            res += ltr
    return res

# test
print(translate("this is fun"))
