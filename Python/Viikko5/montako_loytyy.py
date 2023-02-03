"""
COMP.CS.100 Tehtävä 5.4 Montako löytyy?
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def input_to_list(amount):
    """Compiles a list from the user inputs, determines searched value and
    prints how many times the searched value can be found among the entered
    numbers.

    :param amount: int, how many numbers the user wants to process
    """
    numbers_list = []

    print(f"Enter {amount} numbers:")

    for i in range(0, amount):
        number = int(input(""))
        numbers_list.append(number)

    searched_value = int(input("Enter the number to be searched: "))

    searched_calculator = 0

    for number in numbers_list:

        if number == searched_value:
            searched_calculator += 1

    if searched_calculator > 0:
        print(f"{searched_value} shows up {searched_calculator} times among"
              f" the numbers you have entered.")

    else:
        print(f"{searched_value} is not among the numbers you have entered.")


def main():
    amount = int(input("How many numbers do you want to process: "))
    input_to_list(amount)


if __name__ == "__main__":
    main()
