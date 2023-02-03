"""
COMP.CS.100 Viikko 2 ohjelma 4
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    number = int(input("Choose a number: "))

    repetition_counter = 1
    result = 0

    while result < 100:
        result = repetition_counter * number
        print(repetition_counter, "*", number, "=", result)
        repetition_counter += 1


if __name__ == "__main__":
    main()
