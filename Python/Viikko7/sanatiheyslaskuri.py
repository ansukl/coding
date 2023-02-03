"""
COMP.CS.100 7.9 Sanatiheyslaskuri
Tekijä: Anna Kleemola, anna.kleemola@tuni.fi
Opiskelijanumero: K431687
"""


def main():
    print("Enter rows of text for word counting. Empty row to quit.")
    sentence_list = []
    while True:
        text = input("")
        if text == "":
            break
        else:
            sentence_list.append(text)

    sentence_dict = {}
    for sentence in sentence_list:
        splitted = sentence.split()
        for word in splitted:
            lowercase = word.lower()
            if lowercase in sentence_dict:
                sentence_dict[lowercase] += 1
            else:
                sentence_dict[lowercase] = 1
    sorted_keys = sorted(sentence_dict)

    for key in sorted_keys:
        print(f"{key} : {sentence_dict[key]} times")


if __name__ == '__main__':
    main()