"""
COMP.CS.100 Viikko 2 ohjelma 11
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    month = 1
    day = 1

    for m in range(1, 12 + 1):

        if (m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10
                or m == 12):
            for d in range(1, 31 + 1):
                print(f"{day}.{month}.")
                day += 1
                if d == 31:
                    month += 1
                    day = 1

        elif m == 2:
            for d in range(1, 28 + 1):
                print(f"{day}.{month}.")
                day += 1
                if d == 28:
                    month += 1
                    day = 1

        elif m == 4 or m == 6 or m == 9 or m == 11:
            for d in range(1, 30 + 1):
                print(f"{day}.{month}.")
                day += 1
                if d == 30:
                    month += 1
                    day = 1


if __name__ == "__main__":
    main()
