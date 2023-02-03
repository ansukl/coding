"""
COMP.CS.100 Tehtävä 5.3.2 Listan alkioiden läpikäyminen
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    numbers_list = []

    print("Give 5 numbers:")

    for i in range(0, 5):
        number = int(input("Next number: "))
        numbers_list.append(number)

    print("The numbers you entered, in reverse order:")

    for i in range(5, 0, -1):
        print(numbers_list[i-1])


if __name__ == "__main__":
    main()

