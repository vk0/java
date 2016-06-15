# Represent a small bilingual lexicon as a Python dictionary in
# the following fashion
# {"merry":"god", "christmas":"jul", "and":"och", "happy":gott",
# "new":"nytt", "year":"år"}
# and use it to translate your Christmas cards from English into Swedish.
#
# That is, write a function translate() that takes a list of English words and
# returns a list of Swedish words.


dictionary = {"merry": "god", "christmas": "jul", "and": "och", 
                "happy": "gott", "new": "nytt", "year": "år"}


def translate(english):
    swedish = []
    for word in english:
        swedish += [dictionary[word.lower()]]
    return swedish

# test
print("Translate ['Merry', 'christmas', 'and', 'happy', 'new', 'year']")
print(translate(['Merry', 'christmas', 'and', 'happy', 'new', 'year']))
