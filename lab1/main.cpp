#include <iostream>
using namespace std;

struct Triangle {
    int number;        // номер фигуры
    string color;
    double leg1, leg2; // катеты прямоугольного треуольника
    Triangle *next;

    typedef Triangle *PTriangle;
    PTriangle Head = NULL;

    PTriangle CreateNode ( int NewNumber, string NewColor, double NewLeg1, double NewLeg2) {

        Triangle *NewTriangle = new Triangle;
        NewTriangle -> number = NewNumber;
        NewTriangle -> color = NewColor;
        NewTriangle -> leg1 = NewLeg1;
        NewTriangle -> leg2 = NewLeg2;
        NewTriangle -> next = NULL;

        return NewTriangle;
    }

    void AddFirst (Triangle *&Head, int NewNumber, string NewColor, double NewLeg1, double NewLeg2) {

        Triangle *NewTriangle = new Triangle;
        NewTriangle -> number = NewNumber;
        NewTriangle -> color = NewColor;
        NewTriangle -> leg1 = NewLeg1;
        NewTriangle -> leg2 = NewLeg2;
        NewTriangle -> next = Head;
        Head = NewTriangle;

        return;
    }

    void AddLast (Triangle *&Head, int NewNumber, string NewColor, double NewLeg1, double NewLeg2) {

        Triangle *tmp = Head;

        if ( Head == NULL ) {
            AddFirst( Head, NewNumber, NewColor, NewLeg1, NewLeg2 );
            return;
        }
        while ( tmp -> next ) tmp = tmp -> next;

        Triangle *NewTriangle = new Triangle;
        NewTriangle -> number = NewNumber;
        NewTriangle -> color = NewColor;
        NewTriangle -> leg1 = NewLeg1;
        NewTriangle -> leg2 = NewLeg2;
        NewTriangle -> next = NULL;
        tmp -> next = NewTriangle;

        return;
    }

    int AddAfter( Triangle *Head, int NewNumber, string NewColor, double NewLeg1, double NewLeg2, int NumberAfter) {

        if (Head == NULL) return 1;

        Triangle *tmp = Head;

        while (tmp != NULL && tmp -> number != NumberAfter) tmp = tmp -> next;

        if ( tmp == NULL ) return 1;

        Triangle *NewTriangle = new Triangle;
        NewTriangle -> number = NewNumber;
        NewTriangle -> color = NewColor;
        NewTriangle -> leg1 = NewLeg1;
        NewTriangle -> leg2 = NewLeg2;
        NewTriangle -> next = tmp -> next;
        tmp -> next = NewTriangle;

        return 0;
    }

    int AddBefore( Triangle *&Head, int NewNumber, string NewColor, double NewLeg1, double NewLeg2, int NumberBefore) {

        if ( Head == NULL ) return 1;

        if (Head -> number == NumberBefore ) {
            AddFirst( Head, NewNumber, NewColor, NewLeg1, NewLeg2 );
            return 0;
        }
        if ( Head -> next == NULL ) return 1;

        Triangle *prev = Head, *tmp = Head -> next;

        while (tmp -> next != NULL && tmp -> number != NumberBefore) {
            prev = prev -> next;
            tmp = tmp -> next;
        }
        if ( tmp -> next == NULL && tmp -> number != NumberBefore) return 1;

        Triangle * NewTriangle = new Triangle;
        NewTriangle -> number = NewNumber;
        NewTriangle -> color = NewColor;
        NewTriangle -> leg1 = NewLeg1;
        NewTriangle -> leg2 = NewLeg2;
        NewTriangle -> next = tmp;
        prev -> next = NewTriangle;

        return 0;
    }

    int DelTriangle( Triangle *&Head, int DelNumber) {

        if ( Head == NULL ) return 1;

        Triangle *tmp = Head;

        if ( Head -> number == DelNumber ) {
            Head = Head -> next;
            delete tmp;
            return 0;
        }
        if ( Head->next == NULL ) return 1;

        Triangle *prev = Head;
        tmp = Head -> next;

        while (tmp -> next != NULL && tmp -> number != DelNumber) {
            prev = prev -> next;
            tmp = tmp -> next;
        }
        if ( tmp -> next == NULL && tmp -> number != DelNumber) return 1;

        prev -> next = tmp -> next;
        delete tmp;

        return 0;
    }

    void PrintList( Triangle *Head) {

        if ( Head == NULL ) {
            cout<<"The list is empty";
            return;
        }
        Triangle *tmp = Head;

        while (tmp != NULL) {
            cout << "The number of triangle: " << tmp -> number <<
              "\nColor: " << tmp -> color <<
              "\nLegs: "<< tmp -> leg1 << ", " << tmp -> leg2 << "\n\n";
            tmp = tmp -> next;
        }
        return;
    }

};

int main() {

    Triangle *list = new Triangle();

    list -> AddFirst(list, 1, "green", 3, 4.5);
    list -> AddBefore(list, 2, "red", 4.12345, 5.7784, 1);
    list -> AddAfter(list, 3, "yellow", 10, 10, 2);
    list -> AddLast(list, 4, "purple", 1.55, 1);
    list -> AddAfter(list, 5, "blue", 2, 8.2324, 1);
    list -> DelTriangle(list, 4);

    list -> PrintList(list);

    return 0;
}
