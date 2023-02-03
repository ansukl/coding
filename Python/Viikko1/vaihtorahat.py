"""
COMP.CS.100 Seitsemäs ohjelma
Tekijä: Anna Kleemola
Opiskelijanumero: K431687
"""


def main():
    hinta = int(input("Purchase price: "))
    maksettu = int(input("Paid amount of money: "))
    erotus = maksettu - hinta

    if maksettu <= hinta:
        print("No change")

    else:
        print("Offer change: ")
        if erotus // 10 > 0:
            kympit = erotus // 10
            print(kympit, "ten-euro notes")
            erotus = erotus - (kympit * 10)

        if erotus  // 5 > 0:
            vitoset = erotus // 5
            print(vitoset, "five-euro notes")
            erotus = erotus - (vitoset * 5)

        if erotus  // 2 > 0:
            kakkoset = erotus // 2
            print(kakkoset, "two-euro coins")
            erotus = erotus - (kakkoset * 2)

        if erotus  // 1 > 0:
            ykkoset = erotus // 1
            print(ykkoset, "one-euro coins")
            erotus = erotus - (ykkoset * 1)


if __name__ == "__main__":
    main()
