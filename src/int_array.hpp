#ifndef INT_ARRAYHPP
#define INT_ARRAYHPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>

class Array {
public:
    Array() : len(0), buf{nullptr} {
    }

    explicit Array(int len) : len{len}, buf{new int[len]} {}

    Array(const Array& other) {
        this->len = other.len;
        this->buf = new int[this->len];
        int i = 0;
        for (; i < this->len; ++i) {
            this->buf[i] = other.buf[i];
        }
    }

    Array(Array&& other) noexcept {
        this->len = other.len;
        this->buf = other.buf;
    }

    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

    Array& operator=(const Array& other) {
        if (this->buf != nullptr)
            delete[] this->buf;
        this->len = other.len;
        this->buf = new int[this->len];
        int i = 0;
        for (; i < this->len; ++i) {
            this->buf[i] = other.buf[i];
        }
    }

    Array& operator=(Array&& other) {
        if (this->buf != nullptr)
            delete[] this->buf;
        this->len = other.len;
        this->buf = other.buf;
        return *this;
    }
    
    ~Array() {
        delete[] this->buf;
    }

    int length() const {
        return this->len;
    }

    int& operator[](int index) {
        if (!in_bounds(index)) {
            return this->buf[0];
        }
        return this->buf[index];
    }

    void fill(int val) {
        int i = 0;
        for (; i < this->len; ++i) {
            buf[i] = val;
        }
    }

private:
    int len;
    int* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < this->len;
    }
};

inline std::ostream& operator<<(std::ostream& out, const Array& array) {
    std::stringstream temp;
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << const_cast<Array&>(array)[i];
    }

    out << temp.str();
    return out;
}

inline std::istream& operator>>(std::istream& in, Array& array) {
    for (int i = 0; i < array.length(); ++i) {
        int tmp;

        in >> tmp;
        array[i] = tmp;
    }

    return in;
}

#endif