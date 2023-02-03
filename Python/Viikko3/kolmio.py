"""
COMP.CS.100 Tehtävä 3.8.1 Kolmion pinta-ala
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""

from math import sqrt


def area(a, b, c):
    """Calculate and return the area of a triangle.

       :param a: float, first side of the triangle.
       :param b: float, second side of the triangle.
       :param c: float, third side of the triangle.
       :return: float, the area of the triangle.
       """

    s = (a + b + c) / 2
    x = s * (s - a) * (s - b) * (s - c)
    result = sqrt(x)
    return result


def main():
    first = float(input("Enter the length of the first side: "))
    second = float(input("Enter the length of the second side: "))
    third = float(input("Enter the length of the third side: "))

    triangle_area = area(first, second, third)

    print(f"The triangle's area is {triangle_area:.1f}")


if __name__ == "__main__":
    main()
