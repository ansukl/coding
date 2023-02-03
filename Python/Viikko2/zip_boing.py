"""
COMP.CS.100 Viikko 2 ohjelma 5
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    choice = int(input("How many numbers would you like to have? "))

    do_the_main_loop = True

    repetition_counter = 1
    while do_the_main_loop:
        if repetition_counter % 3 == 0 and repetition_counter % 7 == 0:
            print("zip boing")
            repetition_counter += 1
        elif repetition_counter % 3 == 0:
            print("zip")
            repetition_counter += 1
        elif repetition_counter % 7 == 0:
            print("boing")
            repetition_counter += 1
        else:
            if repetition_counter <= choice:
                print(repetition_counter)
                repetition_counter += 1
            else:
                do_the_main_loop = False


if __name__ == "__main__":
    main()

