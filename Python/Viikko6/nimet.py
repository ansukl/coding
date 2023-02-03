"""
COMP.CS.100 6.6 Käännä nimet oikein päin
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def reverse_name(name):
    """Reverses the user input name by splitting at comma. If there is no
    comma, prints the input.

    :param name: str, given input.
    """

    if name.count(",") == 0:
        return name

    else:
        separated = name.split(",")
        last_name = separated[0].strip()
        first_name = separated[1].strip()

        if last_name == "":
            return first_name
        elif first_name == "":
            return last_name

        return f"{first_name} {last_name}"


def main():

    name = input()
    reverse_name(name)


if __name__ == "__main__":
    main()