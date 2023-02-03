#ifndef BOOK_HH
#define BOOK_HH

#include "date.hh"

#include <string>
using namespace std;

class Book
{
public:
    Book();
    // Constructor.
    Book(string author_name, string book_name);

    // More methods
    void print();
    void loan(Date& day);
    void renew();
    void give_back();

private:
    string author_;
    string book_name_;
    bool loaned_;
    Date loaned_date_;
    Date due_date_;

};

#endif // BOOK_HH
