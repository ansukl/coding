"""
COMP.CS.100 9.5 TV-sarjan valitseminen
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def read_file(filename):
    """
    Reads and saves the series and their genres from the file.

    :param filename: str, user's input specifying the file to be opened.
    :return: dict, a dictionary which contains the series name as key and genres as a list as value.
    """

    genre_series = {}

    try:
        file = open(filename, mode="r")

        for row in file:

            # If the input row was correct, it contained two parts:
            # · the show name before semicolon (;) and
            # · comma separated list of genres after the semicolon.
            # If we know that a function (method split in this case)
            # returns a list containing two elements, we can assign
            # names for those elements as follows:
            name, genres = row.rstrip().split(";")

            genres = genres.split(",")

            if name not in genre_series:
                genre_series[name] = genres

        file.close()
        return genre_series

    except ValueError:
        print("Error: rows were not in the format name;genres.")
        return None

    except IOError:
        print("Error: the file could not be read.")
        return None


def main():
    filename = input("Enter the name of the file: ")

    genre_data = read_file(filename)

    series_genre_list = genre_data.values()
    just_genres = []
    for genre_list in series_genre_list:
        for i in genre_list:
            if i not in just_genres:
                just_genres.append(i)

    sorted_list = sorted(just_genres)
    joined = ", ".join(sorted_list)

    print(f"Available genres are: {joined}")

    while True:
        genre = input("> ")

        if genre == "exit":
            return
        else:
            series_list = []
            for series in genre_data:
                for g in genre_data[series]:
                    if g == genre:
                        series_list.append(series)

            sorted_series = sorted(series_list)

            for s in sorted_series:
                print(s)


if __name__ == "__main__":
    main()
