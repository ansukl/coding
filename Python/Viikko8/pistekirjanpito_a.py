"""
COMP.CS.100 8.12 Pisteiden laskentaa
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    filename = input("Enter the name of the score file: ")

    file = open(filename, mode="r")

    score_dict = {}
    for file_line in file:
        name, score = file_line.split()
        if name in score_dict:
            score_dict[name] += int(score)
        else:
            score_dict[name] = int(score)

    print("Contestant score:")
    sorted_keys = sorted(score_dict)

    for key in sorted_keys:
        print(f"{key} {score_dict[key]}")

    file.close()


if __name__ == "__main__":
    main()
