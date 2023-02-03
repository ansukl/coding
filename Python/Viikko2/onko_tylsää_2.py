"""
COMP.CS.100 Viikko 2 ohjelma 2
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    word = ""

    invalid_input = True

    while invalid_input:
        word = input("Answer Y or N: ")

        if word == "y" or word == "Y" or word == "n" or word == "N":
            invalid_input = False

        else:
            print("Incorrect entry.")

    print("You answered", word)


if __name__ == "__main__":
    main()