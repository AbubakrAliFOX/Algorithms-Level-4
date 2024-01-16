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
    return (Number % 4 == 0 && Number % 100 != 0) || (Number % 400 ==0);
}

short Days(short Year) {
    return IsLeapYear(Year)? 366 : 365;
}

short Hours(short Year) {
    return Days(Year) * 24;
}

short Minutes(short Year) {
    return Days(Year) * 24 * 60;
}

int Seconds(short Year) {
    return Days(Year) * 24 * 60 * 60;
}

void YearInDetails(short Year) {
    cout << "Days: " << Days(Year) << endl;
    cout << "Hours: " << Hours(Year) << endl;
    cout << "Minutes: " << Minutes(Year) << endl;
    cout << "Seconds: " << Seconds(Year)<< endl;
}


int main()
{
    short Year = ReadNumber("Enter a year");


    YearInDetails(Year);

    return 0;
}

