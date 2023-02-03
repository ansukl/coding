#include <iostream>
#include <string>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

bool palindrome_recursive(std::string s)
{
  RECURSIVE_FUNC
  // Do not remove RECURSIVE_FUNC declaration, it's necessary for automatic testing to work
  // ------------

    int word_length = s.length();
    char first_letter = s.at(0);
    char last_letter = s.at(word_length -1);
    int first_index = 0;

    if (word_length > 2) {
      if (first_letter != last_letter) {
          return false;
      }

      else {
          std::string substracted;

          substracted = s.substr(first_index +1, word_length -2);
          return palindrome_recursive(substracted);
        }
    }

    else {
        if (first_letter != last_letter) {
            return false;
        }
    } return true;
}

// Do not modify rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    std::cout << "Enter a word: ";
    std::string word;
    std::cin >> word;

    if(palindrome_recursive(word)){
        std::cout << word << " is a palindrome" << std::endl;
    } else {
        std::cout << word << " is not a palindrome" << std::endl;
    }
}
#endif
