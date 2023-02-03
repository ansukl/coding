"""
COMP.CS.100 Tehtävä 3.6.1 MacDonald
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def print_verse(first_animal, sound):
    """Prints a verse of the song.

    :param first_animal: string, the first animal mentioned.
    :param sound: string, the sound the animal makes.
    """
    print("Old MACDONALD had a farm")
    print("E-I-E-I-O")
    print(f"And on his farm he had a {first_animal}")
    print("E-I-E-I-O")
    print(f"With a {sound} {sound} here")
    print(f"And a {sound} {sound} there")
    print(f"Here a {sound}, there a {sound}")
    print(f"Everywhere a {sound} {sound}")
    print("Old MacDonald had a farm")
    print("E-I-E-I-O")


def main():
    print_verse("cow", "moo")
    print()

    print_verse("pig", "oink")
    print()

    print_verse("duck", "quack")
    print()

    print_verse("horse", "neigh")
    print()

    print_verse("lamb", "baa")


if __name__ == "__main__":
    main()
