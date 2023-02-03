"""
COMP.CS.100 Tehtävä 5.5.2 Funktio listan suuruusjärjestyksen tarkasteluun
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def is_the_list_in_order(numbers_list):
    """
    Checks list members are in order
    :param numbers_list: list, the list of numbers to be checked
    :return: bool
    """
    if not numbers_list:
        return True

    testilista = []
    testilista += numbers_list
    testilista.sort()

    return numbers_list == testilista
