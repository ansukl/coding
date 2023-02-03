"""
COMP.CS.100 Tehtävä 4.7 Lottopelejä
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def factorial(n):
    """
    Calculates factorial.

    :param n: int, used to calculate factorial
    :return: int, returns factorial
    """
    fact = 1

    for i in range(1, n + 1):
        fact = fact * i

    return fact


def odds(a, b):
    """
    Calculates odds.

    :param a: int, number of lottery balls
    :param b: int, number of drawn balls
    :return: int, calculated odds
    """
    return int(factorial(a) / (factorial((a - b)) * factorial(b)))


def valid_input(one, two):
    """
    Checks if given numbers are valid.
    :param one: int, number of lottery balls
    :param two: int, number of drawn balls
    :return: bool, True if valid
    """
    if one < 0 or two < 0:
        print("The number of balls must be a positive number.")
        return False
    elif two > one:
        print("At most the total number of balls can be drawn.")
        return False
    else:
        return True


def main():
    a = int(input("Enter the total number of lottery balls: "))
    b = int(input("Enter the number of the drawn balls: "))

    if valid_input(a, b):
        prob = odds(a, b)
        print(
            f"The probability of guessing all {b} balls correctly is 1/{prob}"
        )


if __name__ == "__main__":
    main()
