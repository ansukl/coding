"""
COMP.CS.100 Ohjelmointi 1
            Programming 1
10.10 Mölkyn pisteiden laskenta
Calculates points for Mölkky.

K431687
Anna Kleemola
anna.kleemola@tuni.fi
"""


# TODO:
# a) Implement the class Player here.

class Player:
    def __init__(self, name):

        self.__name = name
        self.__score = 0
        self.__throws = 0
        self.__points = 0
        self.__notzero = 0

    def get_name(self):
        return self.__name

    def add_points(self, pts):
        self.__points += pts
        self.__throws += 1

        if pts > 0:
            self.__notzero += 1

        if (self.__score + pts) > 50:
            print(f"{self.__name} gets penalty points!")
            self.__score = 25
        elif 40 <= (self.__score + pts) <= 49:
            self.__score += pts
            print(f"{self.__name} needs only {50 - self.__score} points."
                  f" It's better to avoid knocking down the pins with"
                  f" higher points.")
        else:
            self.__score += pts

    def has_won(self):
        while self.__score == 50:
            return True

    def get_points(self):
        return self.__score

    def score_average(self, pts):
        while pts > (self.__points / self.__throws):
            return True

    def hit_percentage(self):
        if self.__notzero == 0:
            return 0.0
        else:
            return (self.__notzero / self.__throws) * 100


def main():
    # Here we define two variables which are the objects initiated from the
    # class Player. This is how the constructor of the class Player
    # (the method that is named __init__) is called!

    player1 = Player("Matti")
    player2 = Player("Teppo")

    throw = 1
    while True:

        # if throw is an even number
        if throw % 2 == 0:
            in_turn = player1

        # else throw is an odd number
        else:
            in_turn = player2

        pts = int(input("Enter the score of player " + in_turn.get_name() +
                        " of throw " + str(throw) + ": "))

        in_turn.add_points(pts)

        # TODO:
        # c) Add a supporting feedback printout "Cheers NAME!" here.
        if in_turn.score_average(pts):
            print("Cheers " + in_turn.get_name() + "!")

        if in_turn.has_won():
            print("Game over! The winner is " + in_turn.get_name() + "!")
            return

        print("")
        print("Scoreboard after throw " + str(throw) + ":")
        print(f"{player1.get_name()}: {player1.get_points()} p, hit percentage "
              f"{player1.hit_percentage():.1f}") # TODO: d)
        print(f"{player2.get_name()}: {player2.get_points()} p, hit percentage "
              f"{player2.hit_percentage():.1f}") # TODO: d)
        print("")

        throw += 1


if __name__ == "__main__":
    main()
