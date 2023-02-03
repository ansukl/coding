"""
COMP.CS.100 Tehtävä 4.6.1 Liukulukujen vertaileminen
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def compare_floats(a, b, epsilon):
    """Compares the two floats given by the user with sufficient accuracy.

    :param a: the first float to be compared
    :param b: the second float to be compared
    :param epsilon: margin of error
    :return: returns bool
    """
    return abs(a - b) < epsilon


def main():
    number = float(input("Please, enter a float: "))
    a = number
    second_number = float(input("Please, enter a second float: "))
    b = second_number
    margin = float(input("Please, enter a margin of error: "))
    epsilon = margin

    print(compare_floats(a, b, epsilon))


if __name__ == "__main__":
    main()
