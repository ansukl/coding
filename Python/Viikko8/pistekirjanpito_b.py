"""
COMP.CS.100 8.13 Pisteiden laskennan virhetilanteet
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    filename = input("Enter the name of the score file: ")

    try:
        file = open(filename, mode="r")

    except OSError:
        print(f"There was an error in reading the file.")
        return

    score_dict = {}
    for file_line in file:
        score_list = file_line.split()
        if len(score_list) != 2:
            print("There was an erroneous line in the file:")
            print(file_line.strip())
            return

        try:
            int(score_list[1])
        except ValueError:
            print("There was an erroneous score in the file:")
            print(score_list[1])
            return

        if score_list[0] in score_dict:
            score_dict[score_list[0]] += int(score_list[1])
        else:
            score_dict[score_list[0]] = int(score_list[1])

    print("Contestant score:")
    sorted_keys = sorted(score_dict)

    for key in sorted_keys:
        print(f"{key} {score_dict[key]}")

    file.close()


if __name__ == "__main__":
    main()
