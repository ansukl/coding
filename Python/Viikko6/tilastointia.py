"""
COMP.CS.100 6.2 Projekti: tilastointia
By: Anna Kleemola, anna.kleemola@tuni.fi
Student number: K431687
"""
from math import sqrt


def read_input(numbers_list):
    """Reads the user's input and adds the numbers to a list.

    :param numbers_list: list, contains the user's inputs.
    :return: bool, returns false if conditions are not fulfilled and true if
    they are.
    """
    while True:
        number = input()

        if number == "":
            break

        numbers_list.append(float(number))

    # Checks for incorrect input
    if len(numbers_list) < 2:
        print("Error: needs two or more values.")
        return False

    else:
        return True


def calculate_mean(numbers_list):
    """Calculates the mean of the user's inputs, which are stored in
    numbers_list.

    :param numbers_list: list, contains the user's inputs.
    :return: float, the mean of the input numbers.
    """
    numbers_sum = 0

    for number in numbers_list:
        numbers_sum += number

    mean = numbers_sum / len(numbers_list)

    return mean


def standard_deviation(numbers_list):
    """Calculates the standard deviation of the user's inputs. Calculates
    variance first and then uses square root to calculate standard deviation.

    :param numbers_list: list, contains the user's inputs.
    :return: float, the standard deviation of the inputs.
    """
    mean = calculate_mean(numbers_list)

    # Calculates the sum part of the variance
    variance_sum = 0
    for number in numbers_list:
        deviance = (number - mean) ** 2
        variance_sum += deviance

    variance = 1 / (len(numbers_list) - 1) * variance_sum

    # Uses the standard formula (square root of variance) to calculate standard
    # deviation
    stdr_deviation = sqrt(variance)

    return stdr_deviation


def print_histogram(numbers_list):
    """Prints graphical representations (histograms) of the data to show which
    of the six categories each input value belongs to. Uses the lowest and
    highest thresholds of each cateogry to determine where a value belongs to
    and prints an asterisk for each value belonging to one category.

    :param numbers_list: list, contains the user's inputs.
    """
    deviation = standard_deviation(numbers_list)
    mean = calculate_mean(numbers_list)

    # Calculates thresholds for the categories
    for category_number in range(0, 6):
        lowest = category_number * 0.5 * deviation
        highest = (category_number + 1) * 0.5 * deviation

        asterisk = ""

        for number in numbers_list:
            absolute_value = abs(number - mean)
            if lowest <= absolute_value < highest:
                asterisk += "*"

        print(f"Values between std. dev. {lowest:.2f} - {highest:.2f}: "
              f"{asterisk}")


def main():
    print("Enter the data, one value per line.")
    print("End by entering empty line.")

    numbers_list = []

    # Checks if input was valid
    if not read_input(numbers_list):
        return

    print(f"The mean of given data was: {calculate_mean(numbers_list):.2f}")

    print(f"The standard deviation of given data was: "
          f"{standard_deviation(numbers_list):.2f}")

    if standard_deviation(numbers_list) == 0:
        print("Deviation is zero.")
        return

    print_histogram(numbers_list)


if __name__ == "__main__":
    main()
