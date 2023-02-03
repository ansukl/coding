"""
COMP.CS.100 Viikko 2 ohjelma 9
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    number = int(input("How many Fibonacci numbers do you want? "))

    prev_fb = 1
    prev_prev_fb = 1

    print(f"1. {prev_prev_fb}")
    print(f"2. {prev_fb}")

    for i in range(3, number + 1):
        new_fb = prev_fb + prev_prev_fb
        prev_prev_fb = prev_fb
        prev_fb = new_fb
        print(f"{i}. {new_fb}")


if __name__ == "__main__":
    main()
