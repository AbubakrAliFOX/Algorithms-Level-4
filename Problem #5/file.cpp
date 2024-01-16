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
    if (Month < 1 || Month > 12)
    {
        return 0;
    }

    if (Month == 2)
    {
        return IsLeapYear(Year) ? 29 : 28;
    }

    int DaysOf31[7] = {1,3,5,7,8,10,12};
    for (short i = 1; i <= 7; i++)
    {
        if (DaysOf31[i - 1] == Month) {
            return 31;
        }
    }
    

    return 30;
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
    short Year = ReadNumber("Enter a year");
    short Month = ReadNumber("Enter a month");

    MonthInDetails(Year, Month);

    return 0;
}
