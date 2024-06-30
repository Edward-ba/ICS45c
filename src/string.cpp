#include <utility>
#include <iostream>
#include "string.hpp"
#include "alloc.hpp"

String::String(const char *s) {
    this->buf = strdup(s);
}

String::String(const String &s) {
    this->buf = strdup(s.buf);
}

String::String(int length) {
    this->buf = new char[length];
}

int String::strlen(const char *s) {
    int i = 0;
    while (true) {
        if (s[i] == '\0') {
            return i;
        }
        ++i;
    }
}

String::~String() {
    delete[] this->buf;
}

char *String::strncpy(char *dest, const char *src, int n)
{
    int i=0;
    for ( ; src[i] != '\0' && i < n; ++i )
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strcpy(char *dest, const char *src) 
{
    int i=0;
    for (; src[i] != '\0'; ++i) 
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *String::strncat(char *dest, const char *src, int n)
{
    int i = strlen(dest);
    int j = 0;
    for (; src[j] != '\0' && j < n; ++i, ++j)
        dest[i] = src[j];
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src)
{
    int i = strlen(dest);
    int j = 0;
    for (; src[j] != '\0'; ++j)
        dest[i+j] = src[j];
    dest[i+j] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right)
{
    int i = 0;
    while (true) {
        if (left[i] != right[i] || left[i] == '\0' || right[i] == '\0') {
            return left[i] - right[i];
        }
        ++i;
    }
}

int String::strncmp(const char *left, const char *right, int n)
{
    int i = 0;
    while (i < n) {
        if (left[i] != right[i] || left[i] == '\0' || right[i] == '\0') {
            return left[i] - right[i];
        }
        ++i;
    }
    return  0;
}

const char *String::strchr(const char *str, char c)
{
    int i = 0;
    for (; str[i] != '\0'; ++i)
    {
        if (str[i] == c)
        {
            return &str[i];
        }
    }
    if (c == '\0')
        return &str[i];
    else
        return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle)
{
    if (needle[0] == '\0') {
        return &haystack[0];
    }
    int i = 0;
    int j;
    for (; haystack[i] != '\0'; ++i)
    {
        if (haystack[i] == needle[0])
        {
            j = 1;
            for (; needle[j] != '\0'; ++j) {
                if (needle[j] != haystack[i + j]) 
                    break;
            }
            if (needle[j] == '\0')
                return &haystack[i];
        } 
    }
    return nullptr;
}

String &String::operator=(String s) {
    delete[] this->buf;
    this->buf = new char[strlen(s.buf) + 1];
    strcpy(this->buf, s.buf);
    return *this;
}

char &String::operator[](int index) {
    if (in_bounds(index)){
        return this->buf[index];
    }
    else {
        return this->buf[strlen(this->buf)];
    }
}

const char &String::operator[](int index) const {
    return this->buf[index];
}

int String::size() const {
    return strlen(this->buf);
}

String String::reverse() const {
    int length = strlen(this->buf);
    String out = String(length);
    int i = 0;
    for (; i < length; ++i) {
        out.buf[i] = this->buf[length - i];
    }
    out.buf[i] = '\0';
    return out;
}

int String::indexOf(char c) const {
    int i = 0;
    for (; this->buf[i] != '\0'; ++i) {
        if (this->buf[i] == c) {
            return i;
        }
    };
    return -1;
    
}

int String::indexOf(String s) const {
    int i = 0;
    int j;
    for (; this->buf[i] != '\0'; ++i)
    {
        if (this->buf[i] == s.buf[0])
        {
            j = 1;
            for (; s.buf[j] != '\0'; ++j) {
                if (s.buf[j] != this->buf[i + j]) 
                    break;
            }
            if (s.buf[j] == '\0')
                return i;
        } 
    }
    return -1;
}

bool String::operator==(String s) const {
    return strcmp(this->buf, s.buf) == 0;
}

bool String::operator!=(String s) const {
    return strcmp(this->buf, s.buf) != 0;
}

bool String::operator>(String s) const {
    return strcmp(this->buf, s.buf) > 0;
}

bool String::operator>=(String s) const {
    return strcmp(this->buf, s.buf) >= 0;
}

bool String::operator<(String s) const {
    return strcmp(this->buf, s.buf) < 0;
}

bool String::operator<=(String s) const {
    return strcmp(this->buf, s.buf) <= 0;
}

String String::operator+(String s) const {
    String out = String(strlen(this->buf) + strlen(s.buf) + 1);
    strcpy(out.buf, this->buf);
    strcat(out.buf, s.buf);
    return out;
}

String &String::operator+=(String s) {
    char *tmp = new char[strlen(this->buf) + strlen(s.buf) + 1];
    strcpy(tmp, this->buf);
    delete[] this->buf;
    this->buf = strcat(tmp, s.buf);
    return *this;
}

void String::print(std::ostream &out) const {
    int i = 0;
    for (; this->buf[i] != '\0'; ++i) {
        out << this->buf[i];
    }
}

char *String::strdup(const char *src) {
    char *out = new char[strlen(src) + 1];
    int i = 0;
    for (; src[i] != '\0'; ++i) {
        out[i] = src[i];
    }
    out[i] = '\0';
    return out;
}

std::ostream &operator<<(std::ostream &out, String s) {
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s) {
    int len = in.gcount();
    char *buf = new char[len + 2];
    in.read(buf, len);
    buf[len + 1] = '\0';
    s = String(buf);
    delete[] buf;
    return in;
}

void String::read(std::istream &in) {
    in >> *this;
}

void String::reverse_cpy(char *dest, const char *src) {
    int i = strlen(src) - 1;
    int j = 0;
    for (; i >= 0; --i, ++j) {
        dest[j] = src[i];
    }
    dest[j] = '\0';
}