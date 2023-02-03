"""
COMP.CS.100 Tehtävä 5.6.1 Arvosanojen korvaus
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def convert_grades(grades):
    """
    Converts grades above 0 to value 6
    :param grades: list, the list of grades
    """
    index = 0
    while index < len(grades):
        if grades[index] > 0:
            grades[index] = 6

        index += 1


def main():
    grades = [0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0]
    convert_grades(grades)

    if not grades:
        pass

    else:
        print(grades)  # Should print [0, 6, 0, 6, 0, 6, 0, 6, 0, 6, 0]


if __name__ == "__main__":
    main()
