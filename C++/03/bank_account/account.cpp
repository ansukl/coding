#include "account.hh"
#include <iostream>

using namespace std;

Account::Account(const std::string& owner, bool has_credit):
    account_name_(owner), credit_limit_(has_credit), limit_amount_(0), account_balance_(0) {
    generate_iban();
}

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::print() const {
    cout << account_name_ << " : " << iban_ << " : " << account_balance_ << " euros" <<endl;
}

void Account::set_credit_limit(int limit) {
    if (credit_limit_ == false) {
        cout << "Cannot set credit limit: the account has no credit card" <<endl;
    } else (limit_amount_ += limit);
}

void Account::save_money(int amount) {
    account_balance_ += amount;
}

bool Account::take_money(int amount) {
    if (credit_limit_ && amount <= account_balance_ + limit_amount_) {
        account_balance_ -= amount;
        cout << amount << " euros taken: new balance of " << iban_ << " is " << account_balance_ << " euros" <<endl;
        return true;
    } else if (credit_limit_ && amount > account_balance_ + limit_amount_) {
        cout << "Cannot take money: credit limit overflow" <<endl;
        return false;
    } else if (amount > account_balance_) {
        cout << "Cannot take money: balance underflow" <<endl;
        return false;
    } else {
        account_balance_ -= amount;
        cout << amount << " euros taken: new balance of " << iban_ << " is " << account_balance_ << " euros" <<endl;
        return true;
    }
}

void Account::transfer_to(Account& account, int amount) {
    if (take_money(amount)) {
        account.save_money(amount);
    }
}
