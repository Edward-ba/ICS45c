#include <string>

constexpr int STK_MAX = 1000;

class Stack {
    int _top;
    char buf[STK_MAX];
public:
    // consturcts this stack
    Stack();
    // adds C to top of stack
    void push(char c);
    // removes and returns the top charachter of the stack
    char pop();
    // peeks at top char and returns without removing
    char top() const;
    //  returns true if stack is empty
    bool isEmpty() const;
    // returns true if stack is full
    bool isFull() const;
};

void push_all(Stack & stk, const std::string& line);
void pop_all(Stack & stk);


