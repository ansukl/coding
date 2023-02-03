"""
COMP.CS.100 Tehtävä 6.11 Kokonaisen viestin ROT-13-salaus
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


def encrypt(text):
    """
    Encrypts its parameter using ROT13 encryption technology.

    :param text: str,  string to be encrypted
    :return: str, <text> parameter encrypted using ROT13
    """

    regular_chars = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
                     "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v",
                     "w", "x", "y", "z"]

    encrypted_chars = ["n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x",
                       "y", "z", "a", "b", "c", "d", "e", "f", "g", "h", "i",
                       "j", "k", "l", "m"]

    temp = text.lower()

    if temp in regular_chars:
        reg_index = regular_chars.index(temp)
        if text.isupper():
            return encrypted_chars[reg_index].upper()
        else:
            return encrypted_chars[reg_index]
    else:
        return text


def row_encryption(text):
    """Encrypts its parameter using the encrypt() function.

    :param text: str,  string to be encrypted
    :return: str, <text> parameter encrypted using ROT13
    """
    encrypted_text = ""
    for char in text:
        encrypted_text += encrypt(char)

    return encrypted_text


def main():
    print("Enter text rows to the message. Quit by entering an empty row.")

    msg = read_message()

    print("ROT13:")

    for word in msg:
        print(row_encryption(word))


if __name__ == "__main__":
    main()
