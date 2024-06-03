#include <iostream>
using namespace std;
#include "letter_count.hpp"

constexpr int N_CHARS = ('Z' - 'A' + 1); //will be 26

int main() {
    int counts[N_CHARS] = {0};

    count("Hi my name is Ed", counts);
    print_counts(counts, N_CHARS);

}