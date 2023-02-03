#include <iostream>
#include "book.hh"

using namespace std;

Book::Book(string author_name, string book_name):
    author_(author_name), book_name_(book_name), loaned_(false) {
}

void Book::print() {
    if (!loaned_) {
        cout << author_ << " : " << book_name_ <<endl;
        cout << "- available" <<endl;
    } else {
        cout << author_ << " : " << book_name_ <<endl;
        cout << "- loaned: ";
        loaned_date_.print();
        cout << "- to be returned: ";
        due_date_.print();
    }
}

void Book::loan(Date& day) {
    if (!loaned_) {
        loaned_date_ = day;
        due_date_ = day;
        due_date_.advance(28);
        loaned_ = true;
    } else {
         cout << "Already loaned: cannot be loaned" <<endl;
    }
}

void Book::renew() {
    if (loaned_) {
        due_date_.advance(28);
    } else {
        cout << "Not loaned: cannot be renewed" <<endl;
    }
}

void Book::give_back() {
    loaned_ = false;
}
