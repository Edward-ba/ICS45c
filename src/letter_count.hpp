#pragma once
#include <algorithm>

int char_to_index(char ch) {
    return int (toupper(ch)) - 65;
};
char index_to_char(int i) {
    return char (i + 65);
};
void count(string s, int counts[]) {
    std::for_each(begin(s), end(s), [&](auto c) {
        if (isalpha(c)) {
            counts[char_to_index(c)] += 1;
        }
    });
};
void print_counts(int counts[], int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << index_to_char(i) << " " << counts[i] << std::endl;
    }
};