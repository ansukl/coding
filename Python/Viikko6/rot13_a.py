"""
COMP.CS.100 Tehtävä 6.9 Yhden rivin ROT-13-salaus
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


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
    text = input()
    encrypt(text)


if __name__ == "__main__":
    main()
