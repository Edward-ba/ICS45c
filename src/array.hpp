#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

template <typename T>
class Array {
public:
    Array() : len(0), buf{nullptr} {
    }

    explicit Array(int len) : len{len} {
        this->buf  = new T[this->len];
    }

    Array(const Array& other) {
        this->len = other.len;
        this->buf = new T[this->len];
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
        this->buf = new T[this->len];
        int i = 0;
        for (; i < this->len; ++i) {
            this->buf[i] = other.buf[i];
        }
        return *this;
    }

    Array& operator=(Array&& other) {
        if (this == &other) {
            return *this;
        }
        delete[] this->buf;
        this->len = other.len;
        this->buf = other.buf;

        other.len = 0;
        other.buf = nullptr;
        return *this;
    }
    
    ~Array() {
        delete[] this->buf;
    }

    int length() const {
        return this->len;
    }

    T& operator[](int index) {
        if (!in_bounds(index)) {
            return this->buf[0];
        }
        return this->buf[index];
    }

    const T& operator[](int index) const {
        if (!in_bounds(index)) {
            return this->buf[0];
        }
        return this->buf[index];
    }

    template <typename Fn>
    void fill_with_fn(Fn fn) {
        int i = 0;
        for (; i < len; ++i) {
            buf[i] = fn;
        }
    }

    void fill(T val) {
        int i = 0;
        for (; i < this->len; ++i) {
            buf[i] = val;
        }
    }
private:
    int len;
    T* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
    std::stringstream temp;
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << const_cast<Array<T>&>(array)[i];
    }

    out << temp.str();
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Array<T>& array) {
    for (int i = 0; i < array.length(); ++i) {
        int tmp;

        in >> tmp;
        array[i] = tmp;
    }

    return in;
}

#endif