"""
COMP.CS.100 Tehtävä 3.6.2 Yogi Bear
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def repeat_name(name, number):
    """Prints the bear's name as many times as specified.

    :param name: string, the bear's name.
    :param number: int, how many times the name is repeated.
    """
    for i in range(0, number):
        print(f"{name}, {name} Bear")


def verse(sentence, name):
    """Prints the given sentence and a name.

    :param sentence: string, the sentence that is printed.
    :param name: string, the bear's name.
    """
    print(sentence)
    print(f"{name}, {name}")
    print(sentence)

    repeat_name(name, 3)
    print(sentence)
    repeat_name(name, 1)


def main():
    verse("I know someone you don't know", "Yogi")
    print()

    verse("Yogi has a best friend too", "Boo Boo")
    print()

    verse("Yogi has a sweet girlfriend", "Cindy")


if __name__ == "__main__":
    main()
