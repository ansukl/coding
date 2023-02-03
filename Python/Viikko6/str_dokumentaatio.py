"""
COMP.CS.100 Tehtävä 6.8 Isot alkukirjaimet paikoilleen
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def capitalize_initial_letters(string):
    """Uses the capitalize method to return the string with the first
    character capitalized and the rest lowercased.

    :param string: str, user input.
    :return: str, user input with first letter capitalized and rest lowercased.
    """
    if string == "":
        print(string)

    words = string.split(" ")
    capitalized_list = []

    for word in words:
        capitalized = word.capitalize()
        capitalized_list.append(capitalized)

    capitalized_words = " ".join(capitalized_list)
    return capitalized_words


def main():

    string = input()
    capitalize_initial_letters(string)


if __name__ == "__main__":
    main()
