#include <iostream>
#include"b_adisch.hpp"

int main() {
    int number;
    int base;
    cout << "Please enter any decimal number: ";
    cin >> number;
    cout << "Please enter a base: ";
    cin >> base;
    Badisch zahl(number, base);
    zahl.display();
}