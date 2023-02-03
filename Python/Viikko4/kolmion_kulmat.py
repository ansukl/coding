"""
COMP.CS.100 Tehtävä 4.10.1 Kolmion kulmien laskeminen
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def calculate_angle(angle1, angle2=90):
    """
    Calculates angle of triangle.
    :param angle1: angle 1 of triangle
    :param angle2: angle 2 of triangle
    :return: returns third angle
    """
    return 180 - angle1 - angle2
