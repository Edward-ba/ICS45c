#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "array.hpp"

template<typename T>
class Matrix {
public:
    Matrix()
    : rows(0), cols(0), data(Array<Array<T>>()) {};

    Matrix(int rows, int cols)
    : rows(rows), cols(cols) {
        this->data = std::move(Array<Array<T>>(rows));
        for (int i = 0; i < cols; ++i) {
            this->data[i] = std::move(Array<T>(cols));
        }
    }
    Array<T>& operator[](int row) {
        return this->data[this->row];
    }
    const Array<T> &operator[](int row) const {
        return this->data[this->row];
    };

    int num_rows() const {
        return this->rows;
    }

    int num_cols() const {
        return this->cols;
    }

    void fill(const T& val) {
        int i = 0;
        int j = 0;
        for (; i < this->rows; ++i) {
            j = 0;
            for (; j < this->cols; ++j) {
                data[i][j] = val;
            }
        }
    }

    template <typename Fn>
    void fill_with_fn(Fn fn) {
        delete[] this->data;
        this = Matrix<Fn>(this->rows, this->cols);
        this->fill(fn);
    }


private:
    int rows, cols;
    Array<Array<T>> data;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    int i = 0;
    for (; i < matrix.num_rows; ++i) {
        out << matrix[i] << std::endl;
    }
    return out;
}


template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix) {
    for (int i = 0; i < matrix.num_rows(); ++i) {
        for (int j = 0; j < matrix.num_cols(); ++j) {
            T tmp;
            in >> tmp;
            matrix[i][j] = tmp;
            char space;
            in >> space;
        }
    }

    return in;
}

#endif