#include <iostream>
#include <cmath>
#include <string>
using namespace std;

short ReadNumber(string Msg = "Please Enter a number")
{
    short Number;
    cout << Msg << endl;
    cin >> Number;
    return Number;
}

bool IsLeapYear (short Number) {
    if ((Number % 4 == 0 && Number % 100 != 0) || (Number % 400 ==0)) {
        return true;
    }

    return false;
}


int main()
{
    short Number = ReadNumber("Enter a year");


    if (IsLeapYear(Number)) {

    cout << "It is a leap year" << endl;
    } else {
    cout << "It is NOT a leap year" << endl;

    }

    return 0;
}
