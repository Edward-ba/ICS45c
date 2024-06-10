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
        return Coins(0, 0, 0, 0);
    }
    else {
        this->_quarters -= coins._quarters;
        this->_dimes -= coins._dimes;
        this->_nickles -= coins._nickles;
        this->_pennies -= coins._pennies;
        return *this;
    }
}

int Coins::total_value_in_cents() const {
    return 25*this->_quarters + 10*this->_dimes + 5*this->_nickles + this ->_pennies;
}

void Coins::print(std::ostream& out) const{
    out << "Quarters: " << this->_quarters << std::endl;
    out << "Dimes: " << this->_dimes << std::endl;
    out << "Nickles: " << this->_nickles << std::endl;
    out << "Pennies: " << this->_quarters << std::endl;
}

// int main() {
//     ask_for_coins(std::cin, std::cout);
// }