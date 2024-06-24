#include <iostream>
using namespace std;
#include "string.hpp"
#include <stack>

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

int String::strlen(const char*s)
{
    int i = 0;
    for (; s[i] != '\0'; ++i)
        continue;
    return i;
}

char *String::strncat(char *dest, const char *src, int n)
{
    int i = strlen(dest);
    int j = 0;
    for (; src[j] != '\0' && j < n && i < n; ++i, ++j)
        dest[i] = src[j];
    dest[i] = '\0';
    return dest;
}

char *String::strcat(char *dest, const char *src)
{
    int i = strlen(dest);
    int j = 0;
    for (; src[j] != '\0'; ++i, ++j)
        dest[i] = src[j];
    dest[i] = '\0';
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

void String::reverse_cpy(char *dest, const char *src) 
{
    int i = strlen(src);
    int j = 0;
    for (; j <= i; ++j) {
        dest[j] = src[i - j];
    }
    dest[j + 1] = '\0';
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
    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle)
{
    int i = 0;
    for (; haystack[i] != '\0'; ++i)
    {
        if (haystack[i] == needle[0])
        {
            int j = 1;
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

String &String::operator=(const String &s) 
{
    strcpy(this->buf, s.buf);
    return *this;
}

char &String::operator[](int index)
{
    return this->buf[index];
}

String String::reverse()
{
    String out = String();
    reverse_cpy(out.buf, this->buf);
    return out;
}

int String::indexOf(char c)
{
    int i = 0;
    for (; this->buf[i] != c; ++i);
    return i;
}

String::String(const char *s)
{
    strncpy(buf, s, MAXLEN-1);
}

