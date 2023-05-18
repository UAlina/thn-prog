#include <iostream>

using namespace std;

class Matrix {

protected:
    string name;
    int row, column; // size
    float **matrix;

public:
    Matrix(string name, int newRow, int newColumn);

    void PrintMatrix();

    Matrix operator+(Matrix &matrix2);

    Matrix operator-(Matrix &matrix2);

    Matrix operator*(Matrix &matrix2);
};

Matrix::Matrix(string newName, int newRow, int newColumn) {
    name = newName;
    row = newRow;
    column = newColumn;
    matrix = new float *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new float[column];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i][j] = rand() % 9 + 1;
        }
    }
}

void Matrix::PrintMatrix() {
    if (row != 0 and column != 0) {
        cout << name << " = " << endl;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

Matrix Matrix::operator+(Matrix &matrix2) {
    if (row == matrix2.row and column == matrix2.column) {
        Matrix tmpMatrix = Matrix(name + " + " + matrix2.name, row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                tmpMatrix.matrix[i][j] = matrix[i][j] + matrix2.matrix[i][j];
            }
        }
        return tmpMatrix;
    } else {
        cout << name + " and " + matrix2.name + " can't be added\n" << endl;
        return Matrix("m3", 0, 0);
    }
}

Matrix Matrix::operator-(Matrix &matrix2) {
    if (row == matrix2.row and column == matrix2.column) {
        Matrix tmpMatrix = Matrix(name + " - " + matrix2.name, row, column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                tmpMatrix.matrix[i][j] = matrix[i][j] - matrix2.matrix[i][j];
            }
        }
        return tmpMatrix;
    } else {
        cout << name + " and " + matrix2.name + " can't be subtracted\n" << endl;
        return Matrix("m3", 0, 0);
    }
}

Matrix Matrix::operator*(Matrix &matrix2) {
    if (column == matrix2.row) {
        Matrix tmpMatrix = Matrix(name + " * " + matrix2.name, row, matrix2.column);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < matrix2.column; j++) {
                float sum = 0;

                for (int length = 0; length < column; length++) {
                    sum += matrix[i][length] * matrix2.matrix[length][j];
                }

                tmpMatrix.matrix[i][j] = sum;
            }
        }
        return tmpMatrix;
    } else {
        cout << name + " and " + matrix2.name + " can't be multiplied\n" << endl;
        return Matrix("m3", 0, 0);
    }
}

int main() {
    Matrix m1 = Matrix("m1", 2, 3);
    m1.PrintMatrix();

    Matrix m2 = Matrix("m2", 2, 3);
    m2.PrintMatrix();

    Matrix mx = Matrix("mx", 0, 0);

    Matrix m3 = Matrix("m3", 3, 1);
    m3.PrintMatrix();

    mx = m1 + m2;
    mx.PrintMatrix();

    mx = m1 - m2;
    mx.PrintMatrix();

    mx = m1 * m2;
    mx.PrintMatrix();

    mx = m1 + m3;
    mx.PrintMatrix();

    mx = m1 - m3;
    mx.PrintMatrix();

    mx = m1 * m3;
    mx.PrintMatrix();

    return 0;
}
