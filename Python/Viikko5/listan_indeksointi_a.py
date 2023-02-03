"""
COMP.CS.100 Tehtävä 5.3.1 Listan alkioiden läpikäyminen
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    numbers_list = []

    print("Give 5 numbers:")

    for i in range(0, 5):
        number = int(input("Next number: "))

        if number > 0:
            numbers_list.append(number)

    print("The numbers you entered that were greater than zero were:")
    for number in numbers_list:
        print(number)


if __name__ == "__main__":
    main()


