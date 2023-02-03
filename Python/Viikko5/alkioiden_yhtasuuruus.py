"""
COMP.CS.100 Tehtävä 5.5.1 Funktio listan alkioiden yhtäsuuruusvertailuun
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def are_all_members_same(numbers_list):
    """
    Checks if all members in the list are equal
    :param numbers_list: list, the list of numbers to be checked
    :return: bool
    """
    if numbers_list == []:
        return True

    else:
        return min(numbers_list) == max(numbers_list)
