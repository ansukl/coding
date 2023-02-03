"""
COMP.CS.100 9.7 Yhteystiedot
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def read_file(file_name):
    """
    Reads a CVS file.
    :param file_name: File to be read.
    :return: dict
    """

    # Try to open the file for the reading of the movie data.
    data_file = open(file_name, mode="r")

    # Initialize the a dictionary for the data.
    data = {}

    # Populate the dictionary, until the file has been processed.
    # A nested loop is needed, because the data structure is nested.
    for line in data_file:
        # Remove the character(s) that end the line.
        line = line.rstrip()

        # Split the line into names and facts.
        parts = line.split(";")

        # Create a new nested dictionary for the facts.
        info = {
            "name": parts[1],
            "phone": parts[2],
            "email": parts[3],
            "skype": parts[4]
        }

        data[parts[0]] = info

    # Close the file.
    data_file.close()


    # Return the data or the error code.
    return data
