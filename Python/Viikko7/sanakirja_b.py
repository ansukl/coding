"""
COMP.CS.100 7.6 Lisäominaisuuksia turistisanakirjaan 1
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    english_spanish = {"hey": "hola", "thanks": "gracias", "home": "casa"}
    english_words = sorted(english_spanish)
    print("Dictionary contents:")
    print(", ".join(english_words))

    while True:

        command = input("[W]ord/[A]dd/[R]emove/[P]rint/[T]ranslate/[Q]uit: ")

        if command == "W":

            word = input("Enter the word to be translated: ")
            if word in english_spanish:
                print(f"{word} in Spanish is {english_spanish[word]}")
            else:
                print("The word", word, "could not be found from the "
                                        "dictionary.")

        elif command == "A":
            english_word = input("Give the word to be added in English: ")
            spanish_word = input("Give the word to be added in Spanish: ")
            english_spanish[english_word] = spanish_word

            english_words = sorted(english_spanish)
            print("Dictionary contents:")
            print(", ".join(english_words))

        elif command == "R":
            remove_word = input("Give the word to be removed: ")
            if remove_word in english_spanish:
                del english_spanish[remove_word]
            else:
                print("The word", remove_word, "could not be found from the "
                                               "dictionary.")

        elif command == "Q":
            print("Adios!")
            return

        elif command == "P":
            for word in sorted(english_spanish):
                print(f"{word} {english_spanish[word]}")

        elif command == "T":
            sentence = input("Enter the text to be translated into Spanish: ")
            split_sentence = sentence.split(" ")
            translated = []
            for word in split_sentence:
                if word in english_spanish:
                    translated.append(english_spanish[word])
                else:
                    translated.append(word)
            print("The text, translated by the dictionary:")
            print(" ".join(translated))
        else:
            print("Unknown command, enter W, A, R, P, T or Q!")


if __name__ == "__main__":
    main()
