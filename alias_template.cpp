#include <iostream>
#include <stdexcept>

template <typename T, int Line, int Col>
class Matrix {
  public:
    Matrix() {
        for (int i = 0; i < Line; ++i) {
            for (int j = 0; j < Col; ++j) { m_[i][j] = T(); }
        }
    }

    int rows() const { return Line; }

    int cols() const { return Col; }

    T& operator()(int row, int col) {
        if (row < 0 || row >= Line || col < 0 || col >= Col) { throw std::out_of_range("Matrix indices out of range"); }
        return m_[row][col];
    }

    const T& operator()(int row, int col) const {
        if (row < 0 || row >= Line || col < 0 || col >= Col) { throw std::out_of_range("Matrix indices out of range"); }
        return m_[row][col];
    }

  private:
    T m_[Line][Col];
};

template <typename T, int Line>
using Square = Matrix<T, Line, Line>;

template <typename T, int Line>
using Vector = Matrix<T, Line, 1>;

int main() {
    Matrix<int, 5, 3> ma;
    std::cout << ma(1, 1) << std::endl;
    Square<double, 4> sq;
    Vector<char, 5> vec;
    return 0;
}