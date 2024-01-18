#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
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

short OrderOfDate(short Year, short Month, short Day)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string MonthShortName(short Month)
{
    string arrDayNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return arrDayNames[Month - 1];
}

short DaysFromYearBeginning(short Year, short Month, short Day)
{

    short NumberOfDaysFromYearBeginning = 0;

    for (short i = 1; i < Month; i++)
    {
        NumberOfDaysFromYearBeginning += DaysInMonth(Year, i);
    }

    NumberOfDaysFromYearBeginning += Day;

    return NumberOfDaysFromYearBeginning;
}

string DateOfDay(short Year, short Day)
{
    short Month = 1;
    while (true)
    {
        if (Day <= DaysInMonth(Year, Month))
        {
            break;
        }
        Day -= DaysInMonth(Year, Month);
        Month++;
        
    }
    
    return to_string(Day)+"/"+to_string(Month)+"/"+to_string(Year);
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        short Year = ReadNumber("Enter Year: ");
        short Month = ReadNumber("Enter Month: ");
        short Day = ReadNumber("Enter Day: ");
        short DayNumber = DaysFromYearBeginning(Year, Month, Day);
        
        cout << "Number of days from beginning of the year: " << DayNumber << endl;
        cout << DayNumber << " Date is: " << DateOfDay(Year, DayNumber) << endl;
    }

    return 0;
}
