#include <iostream>
#include <algorithm>
#include "stack.hpp"

Stack::Stack() 
: _top(0) {
    std::cout << "Create stack" << std::endl;
}


bool Stack::isEmpty() const {
    return 0 == _top;
}

bool Stack::isFull() const {
    return STK_MAX == _top;
}

void Stack::push(char c) {
    if (!isFull()) {
        buf[_top] = c;
        _top += 1;
    }
}

char Stack::pop() {
    if (!isEmpty()) {
        _top -= 1;
        char c = buf[_top];
        return c;
    }
    else {
        return '@';
    }
}

char Stack::top() const{
    if (!isEmpty()) {
        return buf[_top];
    }
    else {
        return '@';
    }
}

void push_all(Stack& stk, const std::string& line) {

    std::for_each(begin(line), end(line), [&](auto c) {
        stk.push(c);
    });
}

void pop_all(Stack& stk) {
    while(!stk.isEmpty()) {
        std::cout << stk.pop();
    }
    std::cout << std::endl;
}


// int main()
// {
//     Stack stk;
//     std::string line;
//     while (std::getline(std::cin, line)) {
//         push_all(stk, line);
//         pop_all(stk);
//     }
//     return 0;
// }