"""
COMP.CS.100 8.7 Tiedoston rivien numerointi ei onnistukaan
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    filename = input("Enter the name of the file: ")

    try:
        file = open(filename, mode="r")

    except OSError:
        print(f"There was an error in reading the file.")
        return

    lines = 1
    for file_line in file:
        print(f"{lines} {file_line.strip()}")
        lines += 1

    file.close()


if __name__ == "__main__":
    main()
