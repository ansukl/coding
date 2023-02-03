"""
COMP.CS.100 Tehtävä 5.7 Bussiaikataulu
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    timetable = [630, 1015, 1415, 1620, 1720, 2000]

    time = int(input("Enter the time (as an integer): "))

    index = 0
    print("The next buses leave:")

    while index < len(timetable):
        if time <= timetable[index]:
            for i in range(0, 3):
                print(timetable[(index + i) % len(timetable)])

            break

        elif max(timetable) < time:
            for i in range(0, 3):
                print(timetable[i])

            break

        index += 1


if __name__ == "__main__":
    main()