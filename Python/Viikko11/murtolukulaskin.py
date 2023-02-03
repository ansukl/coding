"""
COMP.CS.100 Ohjelmointi 1
            Programming 1
11.10 Murtolukulaskin
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

    def get_numerator(self):
        return self.__numerator

    def get_denominator(self):
        return self.__denominator

    def simplify(self):
        common = self.greatest_common_divisor(self.__numerator, self.__denominator)
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
        num_multi = fraction.get_numerator() * self.__numerator
        den_multi = fraction.get_denominator() * self.__denominator
        multi = Fraction(num_multi, den_multi)
        return multi

    def divide(self, fraction):
        div_num = fraction.get_denominator() * self.__numerator
        div_den = fraction.get_numerator() * self.__denominator
        div = Fraction(div_num, div_den)
        return div

    def add(self, fraction):
        a = self.__numerator * fraction.get_denominator()
        b = self.__denominator * fraction.get_denominator()
        c = fraction.get_numerator() * self.__denominator

        add_num = a + c
        add_den = b
        added = Fraction(add_num, add_den)
        return added

    def deduct(self, fraction):
        a = self.__numerator * fraction.get_denominator()
        b = self.__denominator * fraction.get_denominator()
        c = fraction.get_numerator() * self.__denominator

        ded_num = a - c
        ded_den = b
        added = Fraction(ded_num, ded_den)
        return added

    def __lt__(self, frac):
        return (self.__numerator / self.__denominator) < (frac.get_numerator() / frac.get_denominator())

    def __le__(self, frac):
        return (self.__numerator / self.__denominator) > (frac.get_numerator() / frac.get_denominator())

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

    @staticmethod
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
    frac_dict = {}
    while True:
        cmd = input("> ")

        if cmd == "":
            print("Unknown command!")
            continue

        if cmd == "add":
            frac = input("Enter a fraction in the form integer/integer: ")
            name = input("Enter a name: ")

            frac_dict[name] = Fraction(
                int(frac.split("/")[0]),
                int(frac.split("/")[1])
            )

        elif cmd == "print":
            name = input("Enter a name: ")

            if name not in frac_dict:
                print(f"Name {name} was not found")
            else:
                print(f"{name} = {frac_dict[name]}")

        elif cmd == "list":
            key_list = sorted(frac_dict.keys())

            for key in key_list:
                print(f"{key} = {frac_dict[key]}")

        elif cmd == "*":
            first = input("1st operand: ")

            if first not in frac_dict:
                print(f"Name {first} was not found")
                continue

            second = input("2nd operand: ")

            if second not in frac_dict:
                print(f"Name {second} was not found")
                continue

            multiplied = frac_dict[first].multiply(frac_dict[second])
            print(f"{frac_dict[first]} * {frac_dict[second]} = {multiplied}")
            multiplied.simplify()
            print(f"simplified {multiplied}")

        elif cmd == "file":
            file_name = input("Enter the name of the file: ")

            try:
                file = open(file_name, "r")

            except OSError:
                print("Error: the file cannot be read.")

            else:
                for row in file:
                    splitted = row.split("=")
                    splitted2 = splitted[1].split("/")
                    if len(splitted) == 2 and len(splitted2) == 2:
                        frac_dict[splitted[0]] = Fraction(
                            int(splitted2[0]),
                            int(splitted2[1])
                        )
                    else:
                        print("Error: the file cannot be read.")
                        break

        elif cmd == "quit":
            print("Bye bye!")
            return

        else:
            print("Unknown command!")


if __name__ == '__main__':
    main()
