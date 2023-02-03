"""
COMP.CS.100 8.9 Numeroitujen rivien kirjoittaminen tiedostoon¶
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
    filename = input("Enter the name of the file: ")

    try:
        write_file = open(filename, mode="w")

    except OSError:
        print(f"Writing the file {filename} was not successful.")
        return

    print("Enter rows of text. Quit by entering an empty row.")
    sentence_list = read_message()
    lines = 1
    for sentence in sentence_list:
        print(f"{lines} {sentence.strip()}", file=write_file)
        lines += 1

    write_file.close()
    print(f"File {filename} has been written.")


if __name__ == "__main__":
    main()
