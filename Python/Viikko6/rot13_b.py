"""
COMP.CS.100 Tehtävä 6.10 Viestin tallentaminen
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def read_message():
    """Reads the user's input and appends it to a list if it is not an empty
    row.

    :return: list, the list containing all user inputs.
    """
    input_list = []

    while True:
        user_input = input()

        if user_input == "":
            return input_list

        input_list.append(user_input)


def main():
    print("Enter text rows to the message. Quit by entering an empty row.")

    msg = read_message()

    print("The same, shouting:")

    for word in msg:
        print(word.upper())


if __name__ == "__main__":
    main()
