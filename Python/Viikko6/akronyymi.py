"""
COMP.CS.100 Tehtävä 6.7 Akronyymin muodostaminen
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def create_an_acronym(name):
    """Creates an acronym of the user input by splitting the string at the
    spaces and adding the uppercase first letter of each word to a new
    variable.

    :param name: str, user input.
    :return: str, the acronym created based on the input.
    """
    acronym = ""

    words = name.split(" ")
    for word in words:
        acronym += word[0].upper()

    return acronym


def main():

    name = input()
    create_an_acronym(name)


if __name__ == "__main__":
    main()