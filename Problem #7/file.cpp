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

short OrderOfDate(short Year, short Month, short Day)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        short Year = ReadNumber("Enter a year");
        short Month = ReadNumber("Enter a month");
        short Day = ReadNumber("Enter a day");
        cout << "\n\nOrder of day: " << OrderOfDate(Year, Month, Day) << endl;
        cout << "Day: " << DayShortName(OrderOfDate(Year, Month, Day)) << "\n\n"
             << endl;
    }

    return 0;
}
