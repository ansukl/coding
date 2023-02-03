"""
COMP.CS.100 Ohjelmointi 1
            Programming 1
11.9 Murtolukulista
Murtolukuolion toteuttava luokka Fraction.

K431687
Anna Kleemola
anna.kleemola@tuni.fi
"""


class Fraction:
    """
    This class represents one single fraction that consists of
    numerator (osoittaja) and denominator (nimittäjä).
    """

    def __init__(self, numerator, denominator):
        """
        Constructor. Checks that the numerator and denominator are of
        correct type and initializes them.

        :param numerator: int, fraction's numerator
        :param denominator: int, fraction's denominator
        """

        # isinstance is a standard function which can be used to check if
        # a value is an object of a certain class.  Remember, in Python
        # all the data types are implemented as classes.
        # ``isinstance(a, b´´) means more or less the same as ``type(a) is b´´
        # So, the following test checks that both parameters are ints as
        # they should be in a valid fraction.
        if not isinstance(numerator, int) or not isinstance(denominator, int):
            raise TypeError

        # Denominator can't be zero, not in mathematics, and not here either.
        elif denominator == 0:
            raise ValueError

        self.__numerator = numerator
        self.__denominator = denominator
        self.__complement = 0

    def simplify(self):
        common = greatest_common_divisor(self.__numerator, self.__denominator)
        self.__numerator = self.__numerator // common
        self.__denominator = self.__denominator // common

    def complement(self):
        self.__complement = self.__numerator * -1
        comp = Fraction(self.__complement, self.__denominator)
        return comp

    def reciprocal(self):
        one = self.__denominator
        two = self.__numerator
        rec = Fraction(one, two)
        return rec

    def multiply(self, fraction):
        num_multi = fraction.__numerator * self.__numerator
        den_multi = fraction.__denominator * self.__denominator
        multi = Fraction(num_multi, den_multi)
        return multi

    def divide(self, fraction):
        div_num = fraction.__denominator * self.__numerator
        div_den = fraction.__numerator * self.__denominator
        div = Fraction(div_num, div_den)
        return div

    def add(self, fraction):
        a = self.__numerator * fraction.__denominator
        b = self.__denominator * fraction.__denominator
        c = fraction.__numerator * self.__denominator

        add_num = a + c
        add_den = b
        added = Fraction(add_num, add_den)
        return added

    def deduct(self, fraction):
        a = self.__numerator * fraction.__denominator
        b = self.__denominator * fraction.__denominator
        c = fraction.__numerator * self.__denominator

        ded_num = a - c
        ded_den = b
        added = Fraction(ded_num, ded_den)
        return added

    def __lt__(self, fraction):
        return (self.__numerator / self.__denominator) < \
               (fraction.__numerator / fraction.__denominator)

    def __le__(self, fraction):
        return (self.__numerator / self.__denominator) > \
               (fraction.__numerator / fraction.__denominator)

    def return_string(self):
        """
        :returns: str, a string-presentation of the fraction in the format
                       numerator/denominator.
        """

        if self.__numerator * self.__denominator < 0:
            sign = "-"

        else:
            sign = ""

        return f"{sign}{abs(self.__numerator)}/{abs(self.__denominator)}"

    def __str__(self):
        return f"{self.__numerator}/{self.__denominator}"


def greatest_common_divisor(a, b):
    """
    Euclidean algorithm. Returns the greatest common
    divisor (suurin yhteinen tekijä).  When both the numerator
    and the denominator is divided by their greatest common divisor,
    the result will be the most reduced version of the fraction in question.
    """

    while b != 0:
        a, b = b, a % b

    return a


def main():

    fraction_list = []
    print("Enter fractions in the format integer/integer.")
    print("One fraction per line. Stop by entering an empty line.")
    while True:
        frac = input()
        if frac == "":
            break

        num, den = frac.split("/")
        fraction = Fraction(int(num), int(den))
        fraction_list.append(fraction)

    print("The given fractions in their simplified form:")

    for f in fraction_list:
        one = f.return_string()
        f.simplify()
        two = f.return_string()
        print(f"{one} = {two}")


if __name__ == '__main__':
    main()
