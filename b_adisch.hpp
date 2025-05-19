#ifndef B_ADISCH_HPP
#define B_ADISCH_HPP

#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

class Badisch {
    private:
    int base; //Basis für die Darstellung
    vector<int> digits; //vector für die Ziffernfolge
    void convert(int number) { // die Funktion um eine natürliche Zahl zu konvertieren.
        digits.clear();
        while (number != 0) {
            digits.push_back(number % base);
            number = number / base;
        }
        reverse(digits.begin(), digits.end());
    }
    int toDecimal() const {
        // Konvertiert das Badisch-Objekt in eine Dezimalzahl
        int decimalValue = 0;
        int multiplier = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            decimalValue += digits[i] * multiplier;
            multiplier *= base;
        }
        return decimalValue;
    }
    public:
    Badisch(int number, int base) : base(base) {
        if(base < 2 || base > 9) {
            throw invalid_argument("Basis soll zwischen 2 und 9 liegen");
        }
        convert(number);
    };
    void display() {
        cout << "< ";
        for(int i = 0; i < digits.size(); i++) {
            cout << digits[i] << " ";
        }
        cout << ">_" << base << endl;
    }
    Badisch operator+ (const Badisch &other) {
        if(base != other.base) {
            throw invalid_argument("Addition erfordert gleiche Basen");
        }
        int sum = toDecimal() + other.toDecimal();
        return Badisch(sum, base);
    }


};
#endif //B_ADISCH_HPP
