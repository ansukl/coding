"""
COMP.CS.100 Tehtävä 4.8 Geometriset kuviot
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""
PI = 3.14159265358979323846


def str2float(string):
    """
    Convert string to float.
    :param string: str, given string
    :return: float, converted float
    """

    return float(string)


def print_results(circ, surf):
    """
    Prints results.
    :param circ: float, circumference
    :param surf: float, surface area
    """

    print(f"The circumference is {circ:.2f}")
    print(f"The surface area is {surf:.2f}")


def valid_input(number):
    """
    Validates input.
    :param number: float, given value
    :return: bool, True if valid
    """
    if number <= 0:
        return False
    else:
        return True


def circle(radius):
    """
    Calculates circle properties.
    :param radius: float, radius of circle
    """

    circumference = 2 * PI * radius
    surface_area = PI * radius * radius

    print_results(circumference, surface_area)


def square(side):
    """
    Calculates square properties.
    :param side: float, side of square
    """

    circumference = side * 4
    surface_area = side * side

    print_results(circumference, surface_area)


def rectangle(s1, s2):
    """
    Calculates rectangle properties.
    :param s1: float, side 1 of rectangle
    :param s2: float, side 2 of rectangle
    """

    circumference = (s1 * 2) + (s2 * 2)
    surface_area = s1 * s2

    print_results(circumference, surface_area)


def menu():
    """
    Print a menu for user to select which geometric pattern to use in
    calculations.
    """

    while True:
        answer = input("Enter the pattern's first letter or (q)uit: ")

        if answer == "s":
            side = str2float(input("Enter the length of the square's side: "))

            while not valid_input(side):
                side = str2float(
                    input("Enter the length of the square's side: ")
                )

            square(side)

        elif answer == "r":
            s1 = str2float(
                input("Enter the length of the rectangle's side 1: ")
            )

            while not valid_input(s1):
                s1 = str2float(
                    input("Enter the length of the rectangle's side 1: ")
                )

            s2 = str2float(
                input("Enter the length of the rectangle's side 2: ")
            )

            while not valid_input(s2):
                s2 = str2float(
                    input("Enter the length of the rectangle's side 2: ")
                )

            rectangle(s1, s2)

        elif answer == "c":
            radius = str2float(input("Enter the circle's radius: "))

            while not valid_input(radius):
                radius = str2float(input("Enter the circle's radius "))

            circle(radius)

        elif answer == "q":
            return

        else:
            print("Incorrect entry, try again!")

        # Empty row for the sake of readability.
        print()


def main():
    menu()
    print("Goodbye!")


if __name__ == "__main__":
    main()
