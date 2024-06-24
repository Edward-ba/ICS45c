#ifndef STRING_HPP
#define STRING_HPP

#include <iosfwd>

constexpr int MAXLEN = 1024;

class String {
public:
    explicit String(const char *s = "");
    String(const String &s);
    
    String &operator=(const String &s);

    char &operator[](int index);
    
    int size();

    String reverse();

    int indexOf(char c);
    
    int indexOf(const String &s);

    bool operator==(const String &s) const;
    bool operator!=(const String &s) const;
    bool operator>(const String &s) const;
    bool operator<(const String &s) const;
    bool operator>=(const String &s) const;
    bool operator<=(const String &s) const;

    String operator+(const String &s);

    String operator+=(const String &s);

    void print(std::ostream &out) const;

    void read(std::istream &in);

    ~String();
    bool in_bounds(int i) {
        return i >= 0 && i < strlen(buf);
    }

    static int strlen(const char *s);
    static char *strcpy(char *dest, const char *src);
    static char *strncpy(char *dest, const char *src, int n);
    static char *strcat(char *dest, const char *src);
    static char *strncat(char *dest, const char *src, int n);
    static int strcmp(const char *left, const char *right);
    static int strncmp(const char *left, const char *right, int n);
    static void reverse_cpy(char *dest, const char *src);
    static const char *strchr(const char *str, char c);
    static const char *strstr(const char *haystack, const char *needle);
private:
    char buf[MAXLEN];
};

std::ostream &operator<<(std::ostream &out, const String&s);
std::ostream &operator>>(std::istream &in, String&s);
#endif