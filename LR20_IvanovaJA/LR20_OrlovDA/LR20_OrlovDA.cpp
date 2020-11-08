#include <iostream>
#include "MyMathFuncs.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int r;
    cout << "Введите радиус: ";
    cin >> r;
    cout << MathFuncs::MyMathFuncs::Perimetr(r) << endl;
    cout << MathFuncs::MyMathFuncs::Square(r);
}
