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

bool IsLeapYear(short Number)
{
    return (Number % 4 == 0 && Number % 100 != 0) || (Number % 400 == 0);
}

short DaysInMonth(short Year, short Month)
{
    int DaysOfMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month < 1 || Month > 12) ? 0 : (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : (DaysOfMonths[Month - 1]));

    // In One Line:
    // return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
}

short HoursInMonth(short Year, short Month)
{
    return DaysInMonth(Year, Month) * 24;
}

int MinutesInMonth(short Year, short Month)
{
    return HoursInMonth(Year, Month) * 60;
}

int SecondsInMonth(short Year, short Month)
{
    return MinutesInMonth(Year, Month) * 60;
}

void MonthInDetails(short Year, short Month)
{
    cout << "DaysInMonth: " << DaysInMonth(Year, Month) << endl;
    cout << "HoursInMonth: " << HoursInMonth(Year, Month) << endl;
    cout << "MinutesInMonth: " << MinutesInMonth(Year, Month) << endl;
    cout << "SecondsInMonth: " << SecondsInMonth(Year, Month) << endl;
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        short Year = ReadNumber("Enter a year");
        short Month = ReadNumber("Enter a month");
        MonthInDetails(Year, Month);
    }

    return 0;
}
