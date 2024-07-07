#include "string.hpp"
#include "list.hpp"
#include <iostream>

String::String(const char *s) {
    this->head = list::from_string(s);
}

String::String(const String &s) {
    this->head = list::copy(s.head);
}

String::~String() {
    list::free(this->head);
}

String::String(String &&s) {
    this->head = s.head;
}

void String::swap(String &s) {
    std::swap(s.head, this->head);
}

String &String::operator=(const String &s) {
    this->head = list::copy(s.head);
    return *this;
}

String &String::operator=(String &&s) {
    this->head = s.head;
    return *this;
}

bool String::in_bounds(int index) const {
    return list::length(this->head) >= index;
}

char String::operator[](int index) const {
    if (!this->in_bounds(index))
        throw std::out_of_range("Index out of bounds");
    else {
        list::Node *tmp = list::nth(this->head, index);
        if (tmp == nullptr)
            return ' ';
        return tmp->data;
    }
}

int String::size() const {
    return list::length(this->head);
}

String String::reverse() const {
    String out = String();
    out.head = list::reverse(this->head);
    return out;
}

int String::indexOf(char c) const {
    list::Node *node = list::find_char(this->head, c);
    return list::index(this->head, node);
}

int String::indexOf(const String &s) const {
    list::Node *node = list::find_list(this->head, s.head);
    return list::index(this->head, node);
}

bool String::operator==(const String &s) const {
    return list::compare(this->head, s.head) == 0;
}

std::strong_ordering String::operator<=>(const String &s) const {
    return list::compare(this->head, s.head) <=> 0;
}

String String::operator+(const String &s) const {
    String out = String();
    out.head = list::append(this->head, s.head);
    return out;
}

String &String::operator+=(const String &s) {
    list::Node *tmp = list::copy(s.head);
    list::last(this->head)->next = tmp;
    return *this;
}

void String::print(std::ostream &out) const {
    list::print(out, this->head);
}

void String::read(std::istream &in) {
    int len = in.gcount();
    char *buf = new char[len + 2];
    in.read(buf, len);
    buf[len + 1] = '\0';
    this->head = String(buf).head;
}

std::ostream &operator<<(std::ostream &out, const String &s) {
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s) {
    s.read(in);
    return in;
}