# In English, the present participle is formed by adding the suffix -ing to 
# the infinite form: go -> going. 
# A simple set of heuristic rules can be given as follows:
# - If the verb ends in e, drop the e and add ing (if not exception: 
# be, see, flee, knee, etc.)
# - If the verb ends in ie, change ie to y and add ing
# - For words consisting of consonant-vowel-consonant, double the final 
# letter before adding ing
# - By default just add ing
# Your task in this exercise is to define a function make_ing_form() which 
# given a verb in infinitive form returns its present participle form. 
# Test your function with words such as lie, see, move and hug. 
# However, you must not expect such simple rules to work for all cases.

vowels = "aeiou"
cons = "bcdfghjklmnpqrstvwxyz"

def make_ing_form(verb):
    l = len(verb)

    if verb.endswith('ie'):
        return verb[:l - 2] + 'ying'
    elif verb.endswith('e') and verb not in ['be', 'see', 'flee', 'knee']:
        return verb[:l - 1] + 'ing'
    elif verb[l-1] in cons and verb[l-2] in vowels and verb[l-3] in cons:
        return verb + verb[l-1] + 'ing'
    else:
        return verb + 'ing'

# test
print(make_ing_form('lie'))
print(make_ing_form('see'))
print(make_ing_form('hug'))
print(make_ing_form('move'))
