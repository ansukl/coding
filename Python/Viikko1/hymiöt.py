"""
COMP.CS.100 Viides ohjelma
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""

def main():
    string_mieliala = input("How do you feel? (1-10) ")
    mieliala = int(string_mieliala)
    if mieliala < 1 or mieliala > 10:
        print("Bad input!")
    elif mieliala == 1:
        print("A suitable smiley would be :'(")
    elif mieliala < 4:
        print("A suitable smiley would be :-(")
    elif mieliala <= 7:
        print("A suitable smiley would be :-|")
    elif mieliala < 10:
        print("A suitable smiley would be :-)")
    else:
        print("A suitable smiley would be :-D")

if __name__ == "__main__":
    main()