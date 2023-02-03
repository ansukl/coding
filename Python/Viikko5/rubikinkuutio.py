"""
COMP.CS.100 Tehtävä 5.5.3 Rubikin kuutio -kilpailut
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    record_list = []

    for i in range(1, 5 + 1):
        time = float(input(f"Enter the time for performance {i}: "))
        record_list.append(time)

    minimum = min(record_list)
    maximum = max(record_list)

    record_list.remove(minimum)
    record_list.remove(maximum)

    total = 0

    for time in record_list:
        total += time

    official_record = total / len(record_list)
    print(f"The official competition score is {official_record:.2f} seconds.")


if __name__ == "__main__":
    main()
