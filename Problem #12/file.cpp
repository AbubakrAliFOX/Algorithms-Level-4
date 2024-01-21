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

void AddDaysToDate(Date &NewDate, short DaysToAdd)
{
    short NumberOfDaysInCurrentMonth;
    while (DaysToAdd > 0)
    {
        NumberOfDaysInCurrentMonth = DaysInMonth(NewDate.Year, NewDate.Month);

        DaysToAdd -= (NumberOfDaysInCurrentMonth - NewDate.Day + 1);
        NewDate.Day = 1;

        if (NewDate.Month < 12)
        {
            NewDate.Month++;
        }
        else
        {
            NewDate.Year++;
            NewDate.Month = 1;
        }

        if (DaysToAdd <= NumberOfDaysInCurrentMonth)
        {
            NewDate.Day += DaysToAdd;
            break;
        }
    }
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Date NewDate;
        short Year = ReadNumber("Enter Year: ");
        short Month = ReadNumber("Enter Month: ");
        short Day = ReadNumber("Enter Day: ");
        short DaysToAdd = ReadNumber("Enter Days To Add: ");

        NewDate.Day = Day;
        NewDate.Month = Month;
        NewDate.Year = Year;

        string DateString = to_string(NewDate.Day) + "/" + to_string(NewDate.Month) + "/" + to_string(NewDate.Year);
        cout << "Old Date: " << DateString << endl;

        AddDaysToDate(NewDate, DaysToAdd);
        DateString = to_string(NewDate.Day) + "/" + to_string(NewDate.Month) + "/" + to_string(NewDate.Year);
        cout << "After adding [" << DaysToAdd << "] days: " << DateString << endl;
        cout << "*** For Extremely Large Number, change types to int ***" << endl;
    }

    return 0;
}
