#include <iostream>
#include <vector>
#include <sstream>

// L?p Logger d? qu?n lý log
class Logger {
public:
    static void log(const std::string& message) {
        std::cout << message << std::endl;
    }
};

// L?p Matrix d? th?c hi?n các phép toán trên ma tr?n
class Matrix {
private:
    std::vector<std::vector<int> > data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<int>(rows, cols)) {}

    // Phép c?ng ma tr?n
    Matrix operator+(const Matrix& other) const {
        Logger::log("Performing matrix addition");
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Phép tr? ma tr?n
    Matrix operator-(const Matrix& other) const {
        Logger::log("Performing matrix subtraction");
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Phép nhân ma tr?n
    Matrix operator*(const Matrix& other) const {
        Logger::log("Performing matrix multiplication");
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Phép chia ma tr?n
    Matrix operator/(const Matrix& other) const {
        Logger::log("Performing matrix division");
        // Add division logic here
        return *this; // Placeholder, implement division logic as needed
    }

    // In ma tr?n
    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    Matrix C = A + B;
    C.print();

    Matrix D = A - B;
    D.print();

    Matrix E = A * B;
    E.print();

    // Matrix F = A / B; // Uncomment when division logic is implemented

    return 0;
}
