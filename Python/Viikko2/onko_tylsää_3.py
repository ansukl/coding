"""
COMP.CS.100 Viikko 2 ohjelma 10
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    word = input("Bored? (y/n) ")

    invalid_input = True

    while invalid_input:

        if word != "n" or word != "N":

            if word == "y" or word == "Y":
                invalid_input = False

            elif word == "n" or word == "N":
                word = input("Bored? (y/n) ")

            else:
                print("Incorrect entry.")
                word = input("Bored? (y/n) ")

    print("Well, let's stop this, then.")


if __name__ == "__main__":
    main()
