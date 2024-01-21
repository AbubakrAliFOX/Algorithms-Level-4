#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

struct Date
{
    short Day, Month, Year;
};

short ReadNumber(string Msg = "Please Enter a number")
{
    short Number;
    cout << Msg << endl;
    cin >> Number;
    return Number;
}

void ReadAndCreateDate(Date &NewDate)
{
    short Year = ReadNumber("Enter Year: ");
    short Month = ReadNumber("Enter Month: ");
    short Day = ReadNumber("Enter Day: ");

    NewDate.Day = Day;
    NewDate.Month = Month;
    NewDate.Year = Year;
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

    return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year);
}

bool IsDayLast(Date NewDate)
{
    return NewDate.Day == DaysInMonth(NewDate.Year, NewDate.Month);
}

bool IsMonthLast(Date NewDate)
{
    return NewDate.Month == 12;
}

void AddOneDayToDate(Date &NewDate)
{
    if (IsDayLast(NewDate))
    {
        if (IsMonthLast(NewDate))
        {
            NewDate.Month = 1;
            NewDate.Year++;
        }
        else
        {
            NewDate.Month++;
        }
        NewDate.Day = 1;
    } else {
        NewDate.Day ++;
    }

}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Date NewDate;
        ReadAndCreateDate(NewDate);

        string DateString = to_string(NewDate.Day) + "/" + to_string(NewDate.Month) + "/" + to_string(NewDate.Year);
        cout << "Old Date: " << DateString << endl;

        AddOneDayToDate(NewDate);
        DateString = to_string(NewDate.Day) + "/" + to_string(NewDate.Month) + "/" + to_string(NewDate.Year);
        cout << "After adding 1 day: " << DateString << endl;
    }

    return 0;
}
