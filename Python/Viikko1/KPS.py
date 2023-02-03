"""
COMP.CS.100 kuudes ohjelma
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""

def main():
    pelaaja_yksi = input("Player 1, enter your choice (R/P/S): ")
    pelaaja_kaksi = input("Player 2, enter your choice (R/P/S): ")

    if pelaaja_yksi == "P" and pelaaja_kaksi == "R":
        print("Player 1 won!")

    elif pelaaja_yksi == "S" and pelaaja_kaksi == "P":
        print("Player 1 won!")

    elif pelaaja_yksi == "R" and pelaaja_kaksi == "S":
        print("Player 1 won!")

    elif pelaaja_kaksi == "P" and pelaaja_yksi == "R":
        print("Player 2 won!")

    elif pelaaja_kaksi == "S" and pelaaja_yksi == "P":
        print("Player 2 won!")

    elif pelaaja_kaksi == "R" and pelaaja_yksi == "S":
        print("Player 2 won!")

    elif pelaaja_yksi == pelaaja_kaksi:
        print("It's a tie!")

if __name__ == "__main__":
    main()