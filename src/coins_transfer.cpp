#include <iostream>
#include "coins.hpp"

int main() {
    Coins piggyBank(50, 50, 50, 50);
    Coins pocket(8, 3, 6, 8);

    std::cout << piggyBank << pocket << std::endl;

    Coins pay_for_chips = pocket.extract_exact_change(coins_required_for_cents(149));
    std::cout << "Bought chips using pocket" << std::endl;
    std::cout << "Chips required the coins: " << pay_for_chips << "";

}