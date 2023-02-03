"""
COMP.CS.100 Tehtävä 3.3 Lenkkilaskuri
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    total_running_length = 0
    zero_counter = 0

    number_of_days = int(input("Enter the number of days: "))

    for n in range(1, number_of_days + 1):
        running_length = float(input(f"Enter day {n} running length: "))

        total_running_length += running_length

        # pidetään kirjaa peräkkäisistä nollapäivistä
        if running_length == 0:
            zero_counter += 1

            if zero_counter == 3:
                print("\nYou had too many consecutive lazy days!")
                return

        # nollataan laskuri, että vain peräkkäiset nollat huomioidaan
        else:
            zero_counter = 0

    # lasketaan mittauspäivien keskiarvo
    length_mean = total_running_length / number_of_days

    # printataan tyhjä rivi muotoilua varten
    print()

    if length_mean < 3.00:
        print(f"Your running mean of {length_mean:.2f} km was too low!")

    else:
        print(
            f"You were persistent runner! With a mean of {length_mean:.2f} km."
        )


if __name__ == "__main__":
    main()
