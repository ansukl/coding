"""
COMP.CS.100 Ohjelmointi 1
            Programming 1
10.4 Tuote
Add methods to the class.

K431687
Anna Kleemola
anna.kleemola@tuni.fi
"""


class Product:
    """
    This class defines a simplified product for sale in a store.
    """

    # TODO: Define all the methods here.  You can see what they are,
    #       what parameters they take, and what their return value is
    #       by examining the main-function carefully.
    #
    #       You also need to consider which attributes the class needs.
    #
    #       You are allowed to modify the main function, but your
    #       methods have to stay compatible with the original
    #       since the automatic tests assume that.

    def __init__(self, name, price, sale_percent=0.00):
        """
        A person object is initialized with the name and
        the initial amount of money in the wallet.

        :param name: str, the name of the person whose
            spending the object is following.
        :param initial_money: float, how much money will
            there be in the wallet at the point of creation.
        """

        self.__name = name
        self.__price = price
        self.__sale = sale_percent

    def printout(self):
        """
        When a person's data is needed to be printed on
        screen this method will handle it.  Also good
        for debugging and testing purposes.
        """

        print(self.__name)
        print("  price:", self.__price)
        print("  sale%:", self.__sale)

    def set_sale_percentage(self, percentage):
        self.__sale = float(percentage)

    def get_price(self):
        return self.__price * (1.00 - self.__sale/100)


def main():
    ################################################################
    #                                                              #
    #  You can use the main-function to test your Product class.   #
    #  The automatic tests will not use the main you submitted.    #
    #                                                              #
    #  Voit käyttää main-funktiota Product-luokkasi testaamiseen.  #
    #  Automaattiset testit eivät käytä palauttamaasi mainia.      #
    #                                                              #
    ################################################################

    test_products = {
        "milk":   1.00,
        "sushi": 12.95,
    }

    for product_name in test_products:
        print("=" * 20)
        print(f"TESTING: {product_name}")
        print("=" * 20)

        prod = Product(product_name, test_products[product_name])

        prod.printout()
        print(f"Normal price: {prod.get_price():.2f}")

        print("-" * 20)

        prod.set_sale_percentage(10.0)
        prod.printout()
        print(f"Sale price: {prod.get_price():.2f}")

        print("-" * 20)

        prod.set_sale_percentage(25.0)
        prod.printout()
        print(f"Sale price: {prod.get_price():.2f}")

        print("-" * 20)


if __name__ == "__main__":
    main()
