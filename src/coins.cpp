#include "coins.hpp"
#include <iostream>

Coins::Coins(int q, int d, int n, int p)
: _quarters(q), 
_dimes(d), 
_nickles(n), 
_pennies(p) {
}

void Coins::deposit_coins(Coins& coins) {
    this->_quarters += coins._quarters;
    coins._quarters = 0;
    this->_dimes += coins._dimes;
    coins._dimes = 0;
    this->_nickles += coins._nickles;
    coins._nickles = 0;
    this->_pennies += coins._pennies;
    coins._pennies = 0;
}

bool Coins::has_exact_change_for_coins(const Coins& coins) const {
    if (this->_quarters < coins._quarters) {
        return false;
    }
    else if (this->_dimes < coins._dimes) {
        return false;
    }
    else if (this->_nickles < coins._nickles) {
        return false;
    }
    else if (this->_pennies < coins._pennies) {
        return false;
    }
    else {
        return true;
    }
}

Coins Coins::extract_exact_change(const Coins& coins) {
    if (this->has_exact_change_for_coins(coins)) {
        this->_quarters -= coins._quarters;
        this->_dimes -= coins._dimes;
        this->_nickles -= coins._nickles;
        this->_pennies -= coins._pennies;
        return coins;
    }
    else {
        return Coins(0, 0, 0, 0);
    }
}

int Coins::total_value_in_cents() const {
    return 25*this->_quarters + 10*this->_dimes + 5*this->_nickles + this ->_pennies;
}

void Coins::print(std::ostream& out) const{
    out << this->_quarters << " Quarters, ";
    out << this->_dimes << " Dimes, ";
    out << this->_nickles << " Nickles, ";
    out << this->_pennies << " Pennies";
}

Coins coins_required_for_cents(int amount_in_cents) {
    int q, d, n, p;
    q = (int) (amount_in_cents / CENTS_PER_QUARTER);
    amount_in_cents -= CENTS_PER_QUARTER * q;
    d = (int) (amount_in_cents / CENTS_PER_DIME);
    amount_in_cents -= CENTS_PER_DIME * d;
    n = (int) (amount_in_cents / CENTS_PER_NICKLE);
    amount_in_cents -= CENTS_PER_NICKLE * n;
    p = amount_in_cents;

    return Coins (q, d, n, p);
};

std::ostream& operator<<(std::ostream& out, const Coins& coins) {
    coins.print(out);
    return out;
};

void print_cents(int cents, std::ostream& out) {
    out << "$" << cents/100.0;
};

Coins ask_for_coins(std::istream& in, std::ostream& out) {
    int q, d, n, p;
    out << "Quarters? ";
    in >> q;
    out << "Dime? ";
    in >> d;
    out << "Nickle? ";
    in >> n;
    out << "Pennies? ";
    in >> p;
    return Coins(0,0,0,0);
};