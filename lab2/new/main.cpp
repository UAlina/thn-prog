#include <iostream>

using namespace std;

class Vector {

protected:
    string name;
    int length;
    float *vector;

public:
    Vector(string name, int length, float elem);

    void PrintVector();

    Vector operator*(float number);

    Vector operator/(float number);

    Vector operator+(Vector &vector2);

    Vector operator-(Vector &vector2);

    float Scalar(Vector &vector2);
};

Vector::Vector(string newName, int newLength, float newElem) {
    name = newName;
    length = newLength;
    vector = new float[length];
    for (int i = 0; i < length; i++) {
        vector[i] = newElem;
    }
}

void Vector::PrintVector() {
    cout << name << " = ( ";
    for (int i = 0; i < length; i++) {
        cout << vector[i] << ", ";
    }
    cout << ")" << endl;
}

Vector Vector::operator*(float number) {
    Vector tmpVector = Vector(name + " * " + to_string(number), length, 0);
    for (int i = 0; i < length; i++) {
        tmpVector.vector[i] = vector[i] * number;
    }
    return tmpVector;
}

Vector Vector::operator/(float number) {
    Vector tmpVector = Vector(name + " / " + to_string(number), length, 1);
    for (int i = 0; i < length; i++) {
        tmpVector.vector[i] = vector[i] / number;
    }
    return tmpVector;
}

Vector Vector::operator+(Vector &vector2) {
    if (length == vector2.length) {
        Vector tmpVector = Vector("sum of " + name + " and " + vector2.name, length, 0);
        for (int i = 0; i < length; i++) {
            tmpVector.vector[i] = vector[i] + vector2.vector[i];
        }
        return tmpVector;
    } else {
        cout << "Can't be added: different lengths of vectors "
             << name << " and " << vector2.name << endl;
    }
}

Vector Vector::operator-(Vector &vector2) {
    if (length == vector2.length) {
        Vector tmpVector = Vector("difference of " + name + " and " + vector2.name, length, 0);
        for (int i = 0; i < length; i++) {
            tmpVector.vector[i] = vector[i] - vector2.vector[i];
        }
        return tmpVector;
    } else {
        cout << "Can't be subtracted: different lengths of vectors " << name << " and " << vector2.name << endl;
    }
}

float Vector::Scalar(Vector &vector2) {
    float summa = 0;
    if (length == vector2.length) {
        for (int i = 0; i < length; i++) { summa += vector[i] * vector2.vector[i]; }
        cout << "scalar of " + name + " and " + vector2.name + " = " << summa << endl;
    } else { cout << "Different lengths of vectors " << name << " and " << vector2.name << endl; }
}


int main() {
    Vector v1 = Vector("v1", 3, 1);
    Vector v2 = Vector("v2", 3, 2);
    Vector v4 = Vector("v4", 2, 4);
    v1.PrintVector();
    v2.PrintVector();
    v4.PrintVector();
    cout << endl;

    Vector v3 = Vector("v3", 0, 0);

    v3 = v1 * 5;
    v3.PrintVector();

    v3 = v1 / 5;
    v3.PrintVector();

    v3 = v1 + v2;
    v3.PrintVector();

    v3 = v1 - v2;
    v3.PrintVector();

    v3 = v1 + v4;
    v3 = v1 - v4;

    v1.Scalar(v2); // = v1 * v2

    return 0;
}
