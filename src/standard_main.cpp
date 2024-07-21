#include <cmath>
#include <iostream>
#include <numbers>

#include "array.hpp"
#include "matrix.hpp"

template<typename T>
Array<T> operator*(const Matrix<T>& mat, const Array<T>& arr) {
    if (mat.num_cols() != arr.length())
        throw std::string{"Dimensions do not line up for product!"};
    
    Array<T> result{mat.num_rows()};
    result.fill(0);

    for(int i = 0; i < mat.num_rows(); ++i) {
        for(int j = 0; j < mat.num_rows(); ++i) {
            result[i] += mat[i][j] * arr[j];
        }
    }

    return result;
}

template <typename T>
T ask_for(const std::string& message, T value = T{}) {
    std::cout << message;
    std::cin >> value;
    return value;
}

Matrix<double> rotation_matrix(double angle) {
    Matrix<double> result{2, 2};
    result[0][0] = std::cos(angle);
    result[0][1] = -std::sin(angle);
    result[1][0] = std::sin(angle);
    result[1][1] = std::cos(angle);

    return result;
}

int main() {
    int rows = ask_for<int>("Enter number of rows of matrix: ");
    int cols = ask_for<int>("Enter number of cols of matrix: ");

    Matrix<int> mat = ask_for("Enter Matrix:\n", Matrix<int>{rows, cols});
    Array<int> arr = ask_for("Enter Vector: ", Array<int>{cols});
    Array<int> result = mat * arr;
    std::cout << "The product is:\n" << result << std::endl;

    Array<double> vec = ask_for("Enter 2-d vector: ", Array<double>{2}); 
    double angle = ask_for<double>("Enter angle: "); 
    std::cout << "Rotating\n" << vec << "\nby <<<< angle <<<< degrees gives\n" << rotation_matrix(angle / 180.0 * std::numbers::pi) * vec << '\n';
}