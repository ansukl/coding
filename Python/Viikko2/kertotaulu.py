"""
COMP.CS.100 Viikko 2 ohjelma 3
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    number = int(input("Choose a number: "))

    repetition_counter = 1
    while repetition_counter <= 10:
        print(repetition_counter, "*", number, "=", repetition_counter * number)
        repetition_counter += 1


if __name__ == "__main__":
    main()
