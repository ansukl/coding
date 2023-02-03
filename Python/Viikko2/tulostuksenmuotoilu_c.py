"""
COMP.CS.100 Viikko 2 ohjelma 8
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    for i in range(1, 11):
        for j in range(1, 11):
            print(f"{i*j:4}", end="")
        print()


if __name__ == "__main__":
    main()
