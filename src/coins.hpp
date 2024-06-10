#pragma once

#include <iosfwd>
#include <iostream>

constexpr int CENTS_PER_QUARTER = 25;
constexpr int CENTS_PER_DIME = 10;
constexpr int CENTS_PER_NICKLE = 5;

class Coins {
public:
    Coins(int q, int d, int n, int p);
    void deposit_coins(Coins& coins);
    bool has_exact_change_for_coins(const Coins& coins) const;
    Coins extract_exact_change(const Coins& coins);
    int total_value_in_cents() const;
    void print(std::ostream& out) const;
    bool operator==(const Coins& other) const = default;

private:
    int _quarters, _dimes, _nickles, _pennies;
};

std::ostream& operator<<(std::ostream& out, const Coins& coins) {
    coins.print(out);
    return out;
};

Coins coins_required_for_cents(int amount_in_cents) {
    int q, d, n, p;
    q = (int) (amount_in_cents / CENTS_PER_QUARTER);
    amount_in_cents %= CENTS_PER_QUARTER;
    d = (int) (amount_in_cents / CENTS_PER_DIME);
    amount_in_cents %= CENTS_PER_DIME;
    n = (int) (amount_in_cents / CENTS_PER_NICKLE);
    amount_in_cents %= CENTS_PER_NICKLE;
    p = amount_in_cents;

    return Coins(q, d, n, p);
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

void coins_menu(std::istream& in, std::ostream& out);
