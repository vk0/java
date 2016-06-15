# A certain childrens game involves starting with a word in a particular
# category. Each participant in turn says a word, but that word must begin
# with the final letter of the previous word. Once a word has been given, it
# cannot be repeated. If an opponent cannot give a word in the category, they
# fall out of the game. For example, with "animals" as the category,
# Child 1: dog
# Child 2: goldfish
# Child 1: hippopotamus
# Child 2: snake
# ...
# Your task in this exercise is as follows: Take the following selection of 70
# English Pokemon names (extracted from Wikipedia's list of Pokemon
# http://en.wikipedia.org/wiki/List_of_Pokémon) and generate the/a sequence
# with the highest possible number of Pokemon names where the subsequent name
# starts with the final letter of the preceding name. No Pokemon name is
# to be repeated.
#
# audino bagon baltoy banette bidoof braviary bronzor carracosta charmeleon
# cresselia croagunk darmanitan deino emboar emolga exeggcute gabite
# girafarig gulpin haxorus heatmor heatran ivysaur jellicent jumpluff kangaskhan
# kricketune landorus ledyba loudred lumineon lunatone machamp magnezone mamoswine
# nosepass petilil pidgeotto pikachu pinsir poliwrath poochyena porygon2
# porygonz registeel relicanth remoraid rufflet sableye scolipede scrafty seaking
# sealeo silcoon simisear snivy snorlax spoink starly tirtouga trapinch treecko
# tyrogue vigoroth vulpix wailord wartortle whismur wingull yamask


def get_next_index(lastletter, names):
    for index, name in enumerate(names):
        if name.startswith(lastletter):
            return index
    return False


def find_best_sequence(names):
    best_sequence = []

    for name in names:
        current_sequence = []
        free_names = names[:]
        current_name = name

        current_sequence.append(current_name)
        free_names.pop(free_names.index(current_name))

        index = get_next_index(current_name[-1], free_names)

        while index:
            current_name = free_names[index]
            current_sequence.append(current_name)
            free_names.pop(index)
            index = get_next_index(current_name[-1], free_names)

        if len(current_sequence) > len(best_sequence):
            best_sequence = current_sequence[:]

    return best_sequence


def get_pokemon_names(file_name):
    pokemon_names = []
    with open(file_name, 'r') as file:
        for line in file:
            pokemon_names += line.rstrip().split()


best_sequence = find_best_sequence(get_pokemon_names("pokemons.txt"))
for word in best_sequence:
    print(word)
print(len(best_sequence))
