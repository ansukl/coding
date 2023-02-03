"""
COMP.CS.100 Tehtävä 3.8.2 Tulostetaan ruutu syötetarkastuksin
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def read_input(response):
    """Checks the given response is larger than zero.


    :param response: the response given when asked.
    :return: returns valid value.
    """
    while True:
        val = int(input(response))
        if val > 0:
            return val


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
    width = read_input("Enter the width of a frame: ")
    height = read_input("Enter the height of a frame: ")
    mark = input("Enter a print mark: ")

    print()
    print_box(width, height, mark)


if __name__ == "__main__":
    main()
