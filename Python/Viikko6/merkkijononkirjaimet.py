"""
COMP.CS.100 6.4 Vokaalit ja konsonantit
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    word = input("Enter a word: ")
    vowels = ["a", "e", "i", "o", "u", "y"]
    vowel_counter = 0

    for index in range(len(word)):
        for vowel in vowels:
            if vowel == word[index]:
                vowel_counter += 1

    consonant_counter = len(word) - vowel_counter

    print(f"The word \"{word}\" contains {vowel_counter} vowels and "
          f"{consonant_counter} consonants.")


if __name__ == "__main__":
    main()
