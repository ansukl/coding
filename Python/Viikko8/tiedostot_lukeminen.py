"""
COMP.CS.100 8.6 Tiedoston rivien numerointi
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    filename = input("Enter the name of the file: ")

    file = open(filename, mode="r")
    lines = 1
    for file_line in file:
        print(f"{lines} {file_line.strip()}")
        lines += 1


if __name__ == "__main__":
    main()
