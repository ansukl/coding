"""
COMP.CS.100 Tehtävä 4.11.1 Paranneltu ruudun tulostus
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def print_box(width, height, border_mark="#", inner_mark=" "):
    """ Prints a box.

    :param width: Width of the box
    :param height: Height of the box
    :param border_mark: Mark used for outer box
    :param inner_mark: Mark used for inner box
    """

    print(f"{border_mark * width}")

    for i in range(0, height-2):
        print(f"{border_mark}{(width-2)*inner_mark}{border_mark}")

    print(f"{border_mark * width}")
    print()


def main():
    print_box(5, 4)
    print_box(3, 8, "*")
    print_box(5, 4, "O", "o")
    print_box(inner_mark=".", border_mark="O", height=4, width=6)


if __name__ == "__main__":
    main()
