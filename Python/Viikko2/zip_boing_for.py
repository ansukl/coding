"""
COMP.CS.100 Viikko 2 ohjelma 6
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    choice = int(input("How many numbers would you like to have? "))

    for repetition_counter in range(1, choice + 1):
        if repetition_counter % 3 == 0 and repetition_counter % 7 == 0:
            print("zip boing")

        elif repetition_counter % 3 == 0:
            print("zip")

        elif repetition_counter % 7 == 0:
            print("boing")

        else:
            print(repetition_counter)


if __name__ == "__main__":
    main()
