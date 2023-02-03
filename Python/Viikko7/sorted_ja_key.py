"""
COMP.CS.100 7.13 Lajittele hinnan mukaan
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


PRICES = {
    "milk": 1.09, "fish": 4.56, "bread": 2.10,
    "chocolate": 2.70, "grasshopper": 13.25,
    "sushi": 19.90, "noodles": 0.97, "beans": 0.87,
    "bananas": 1.05, "Pepsi": 3.15,  "pizza": 4.15,
}


def main():
    sorted_prices = sorted(PRICES.items(), key=lambda x: x[1])

    for price in sorted_prices:
        print(f"{price[0]} {price[1]:.2f}")


if __name__ == "__main__":
    main()
