#include <iostream>
using namespace std;

class Vector {

protected:
    string name;
    int length;
    int *vector;

public:
    Vector(string name){ this->name = name; }

    void CreateVector () {
        cout << "Enter the length of the vector " << this->name << endl;
        cin >> length;

        int elem;
        vector = new int [length];
        cout << "Enter a vector " << this->name << " of length " << length << ":" << endl;
        for (int i = 0; i < length; i++) {
            cin >> elem;
            vector[i] = elem;
        }
    }

    void Multiply (float number){
        for (int i = 0; i < length; i++) vector[i] *= number;
    }

    void Divide (float number) {
        for (int i = 0; i < length; i++) vector[i] /= number;
    }

    void AddVector(Vector &vector2) {
        if (this->length == vector2.length) {
            for (int i = 0; i < length; i++) vector[i] = vector[i] + vector2.vector[i];
        }
        else cout << "Can't be added: different lengths of vectors " << this->name << " and " << vector2.name << endl;
    }

    void SubtractVector(Vector &vector2) {
        if (this->length == vector2.length) {
            for (int i = 0; i < length; i++) vector[i] = vector[i] - vector2.vector[i];
        }
        else cout << "Can't be subtracted: different lengths of vectors " << this->name << " and " << vector2.name << endl;
    }

    void PrintVector () {
        cout << this->name << " = ( ";
        for (int i = 0; i < length; i++) {
            cout << vector[i] << ' ';
        }
        cout << ")" << endl;
    }
};

int main() {

    Vector *vect1 = new Vector("v1");
    vect1 -> CreateVector();

    Vector *vect2 = new Vector("v2");
    vect2 -> CreateVector();

    Vector *vect3 = new Vector("v3");
    vect3 -> CreateVector();

    vect1 -> PrintVector();
    vect2 -> PrintVector();
    vect3 -> PrintVector();

    cout << ">>> v1 * 6" << endl;
    vect1 -> Multiply(6);
    vect1 -> PrintVector();

    cout << ">>> v1 / 3" << endl;
    vect1 -> Divide(3);
    vect1 -> PrintVector();

    cout << ">>> v2 + v1" << endl;
    vect2 -> AddVector(*vect1);
    vect2 -> PrintVector();

    cout << ">>> v1 - v2" << endl;
    vect1 -> SubtractVector(*vect2);
    vect1 -> PrintVector();

    cout << ">>> v3 + v1" << endl;
    vect3 -> AddVector(*vect1);
    vect3 -> PrintVector();

    return 0;
}
