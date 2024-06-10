#include <iostream>

#include "coins.hpp"

constexpr int CENTS_FOR_CANDY_BAR = 482;


int main() {
    Coins pocket(100, 10, 10, 100);

   std::cout << "I started with " << pocket << " in my pocket." << std::endl;
   Coins pay_for_candy = pocket.extract_exact_change(coins_required_for_cents(CENTS_FOR_CANDY_BAR));
   std::cout << "I bought a candy bar for " << CENTS_FOR_CANDY_BAR << " cents using " << pay_for_candy << "." << std::endl;
   std::cout << "I have " << pocket << " left in my pocket." << std::endl;

}