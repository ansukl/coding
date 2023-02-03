"""
COMP.CS.100 Tehtävä 5.2 Lukujonoja
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def loop_one():
    """prints the numbers divisble by two from 0 to 100
    """
    for i in range(0, 101):
        if i % 2 == 0:
            print(i)


def loop_two():
    """prints the numbers divisble by two from 100 to 0
    """
    for i in range(100, -1, -1):
        if i % 2 == 0:
            print(i)


def main():
    loop_one()
    loop_two()


if __name__ == "__main__":
    main()
