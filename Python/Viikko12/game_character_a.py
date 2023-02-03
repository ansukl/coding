"""
COMP.CS.100 Ohjelmointi 1 / Programming 1

12.3 Pelihahmo A

This program models a character adventuring in a video game,
or more like, the stuff that the character carries around.

K431687
Anna Kleemola
anna.kleemola@tuni.fi
"""


class Character:

    def __init__(self, name):

        self.__character_name = name
        self.__inventory = {}

    def give_item(self, item):
        if item not in self.__inventory:
            self.__inventory[item] = 1
        else:
            self.__inventory[item] += 1

    def remove_item(self, item):
        if item in self.__inventory:
            self.__inventory[item] -= 1
            if self.__inventory[item] == 0:
                del self.__inventory[item]

    def printout(self):
        sorted_items = sorted(self.__inventory.items())
        sorted_dict = dict(sorted_items)

        print(f"Name: {self.__character_name}")

        if self.__inventory == {}:
            print("  --nothing--")
        else:
            for i in sorted_dict:
                print(f"  {sorted_dict[i]} {i}")

    def get_name(self):
        return self.__character_name

    def has_item(self, item):
        if item in self.__inventory:
            return True
        else:
            return False

    def how_many(self, item):
        if item in self.__inventory:
            return self.__inventory[item]
        else:
            return 0

def main():
    character1 = Character("Conan the Barbarian")
    character2 = Character("Deadpool")

    for test_item in ["sword", "sausage", "plate armor", "sausage", "sausage"]:
        character1.give_item(test_item)

    for test_item in ["gun", "sword", "gun", "sword", "hero outfit"]:
        character2.give_item(test_item)

    character1.remove_item("sausage")
    character2.remove_item("hero outfit")

    character1.printout()
    character2.printout()

    for hero in [character1, character2]:
        print(f"{hero.get_name()}:")

        for test_item in ["sausage", "sword", "plate armor", "gun", "hero outfit"]:
            if hero.has_item(test_item):
                print(f"  {test_item}: {hero.how_many(test_item)} found.")
            else:
                print(f"  {test_item}: none found.")


if __name__ == "__main__":
    main()
