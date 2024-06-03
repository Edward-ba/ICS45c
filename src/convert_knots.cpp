#include <iostream>
using namespace std;
#include "convert_knots.hpp"

int main(){
    int knots = 0;
    cout << "integer speed in knots: ";
    cin >> knots;
    cout << "speed in miles per minute is "
         << knots_to_miles_per_minute(knots)
         << endl;
    return 0;
}

