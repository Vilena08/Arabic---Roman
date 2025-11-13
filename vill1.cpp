/********************
* Author:Saibuu V.M *
* Date: 13.11.2025  *
********************/

#include <iostream>
#include <string>
using namespace std;

string convertArabicToRoman(int number) {
    string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int correspondingValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    string result = "";
    for (size_t index = 0; index < sizeof(correspondingValues)/sizeof(correspondingValues[0]); ++index) {
        while (number >= correspondingValues[index]) {
            result += romanSymbols[index];
            number -= correspondingValues[index];
        }
    }
    return result;
}

int main() {
    int userInput;
    cout << "Enter a positive integer less than 4000: ";
    cin >> userInput;
    
    if(userInput > 0 && userInput < 4000){
        cout << "The number in Roman notation: " << convertArabicToRoman(userInput) << endl;
    } else{
        cout << "Invalid input." << endl;
    }
    return 0;
}

/********************
* Author:Saibuu V.M *
* Date: 13.11.2025  *
********************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int convertRomanToDecimal(const string& romanNumerals) {
    map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int decimalEquivalent = 0;
    int stringLength = romanNumerals.length();

    for (int currentPosition = 0; currentPosition < stringLength;++currentPosition) {
        if (currentPosition + 1 < stringLength && romanMap[romanNumerals[currentPosition]] < romanMap[romanNumerals[currentPosition + 1]]) {
            decimalEquivalent += romanMap[romanNumerals[currentPosition + 1]] - romanMap[romanNumerals[currentPosition]];
            ++currentPosition; 
            
        } else {
            decimalEquivalent += romanMap[romanNumerals[currentPosition]];
        }
    }

    return decimalEquivalent;
}

int main() {
    string romanInput;
    cout << "Enter a valid Roman number (no spaces): ";
    cin >> romanInput;

    try {
        int decimalOutput = convertRomanToDecimal(romanInput);
        cout << "The equivalent decimal number is: " << decimalOutput << endl;
    } catch(...) {
        cerr << "Error: Invalid Roman number format." << endl;
    }

    return 0;
}