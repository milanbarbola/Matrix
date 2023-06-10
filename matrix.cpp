#include <iostream>
#include <vector>

template<typename T>
class Matrix {
private:
    std::vector<T> data;
    int size;

public:
    Matrix(int size) : size(size), data(size * size) {}

    T& operator()(int row, int col) {
        return data[row * size + col];
    }

    const T& operator()(int row, int col) const {
        return data[row * size + col];
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result(i, j) = (*this)(i, j) - other(i, j);
            }
        }
        return result;
    }

    Matrix<T> operator*(T scalar) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result(i, j) = (*this)(i, j) * scalar;
            }
        }
        return result;
    }

    Matrix<T> operator/(T scalar) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result(i, j) = (*this)(i, j) / scalar;
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                T sum = 0;
                for (int k = 0; k < size; ++k) {
                    sum += (*this)(i, k) * other(k, j);
                }
                result(i, j) = sum;
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << (*this)(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix<int> m1(4);
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;
    m1(0, 3) = 4;
    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    m1(1, 3) = 6;
    m1(2, 0) = 7;
    m1(2, 1) = 8;
    m1(2, 2) = 9;
    m1(2, 3) = 6;
    m1(3, 0) = 7;
    m1(3, 1) = 8;
    m1(3, 2) = 9;
    m1(3, 3) = 6;
    Matrix<int> m2(4);
    m2(0, 0) = 9;
    m2(0, 1) = 8;
    m2(0, 2) = 7;
    m2(0, 3) = 7;
    m2(1, 0) = 6;
    m2(1, 1) = 5;
    m2(1, 2) = 4;
    m2(1, 3) = 7;
    m2(2, 0) = 3;
    m2(2, 1) = 2;
    m2(2, 2) = 1;
    m2(2, 3) = 7;
    m2(3, 0) = 3;
    m2(3, 1) = 2;
    m2(3, 2) = 1;
    m2(3, 3) = 7;
    Matrix<int> m3 = m1 + m2;
    Matrix<int> m4 = m1 - m2;
    Matrix<int> m5 = m1 * 2;
    Matrix<int> m6 = m2 / 2;
    Matrix<int> m7 = m1 * m2;

    std::cout << "m1:" << std::endl;
    m1.print();
    std::cout << "m2:" << std::endl;
    m2.print();
    std::cout << "m3 (m1 + m2):" << std::endl;
    m3.print();
    std::cout << "m4 (m1 - m2):" << std::endl;
    m4.print();
    std::cout << "m5 (m1 * 2):" << std::endl;
    m5.print();
    std::cout << "m6 (m2 / 2):" << std::endl;
    m6.print();
    std::cout << "m7 (m1 * m2):" << std::endl;
    m7.print();

    return 0;
}

