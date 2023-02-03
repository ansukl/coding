"""
COMP.CS.100 7.3 Hintalista
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""

PRICES = {
    "milk": 1.09, "fish": 4.56, "bread": 2.10,
    "chocolate": 2.7, "grasshopper": 13.25,
    "sushi": 19.9, "noodles": 0.97, "beans": 0.87,
    "bananas": 1.05, "Pepsi": 3.15,  "pizza": 4.15,
}


def main():
    while True:
        product_name = input("Enter product name: ")
        if product_name == "" or product_name.isspace() is True:
            print("Bye!")
            return False
        else:
            stripped = product_name.strip()
            if stripped in PRICES:
                print(f"The price of {stripped} is {PRICES[stripped]:.2f} e")
            else:
                print(f"Error: {stripped} is unknown.")


if __name__ == "__main__":
    main()
