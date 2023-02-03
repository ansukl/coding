"""
COMP.CS.100 Tehtävä 3.6.3 Tulostetaan ruutu
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def print_box(x, y, char):
    """ Prints a box.

    :param x: Width of the box
    :param y: Height of the box
    :param char: Mark used for making the box
    """

    x = int(x)
    y = int(y)

    for i in range(0, y):
        print(f"{char * x}")


def main():
    width = input("Enter the width of a frame: ")
    height = input("Enter the height of a frame: ")
    mark = input("Enter a print mark: ")

    print()
    print_box(width, height, mark)


if __name__ == "__main__":
    main()
