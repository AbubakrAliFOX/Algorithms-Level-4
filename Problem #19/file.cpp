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

Date ReadAndCreateDate()
{
    Date NewDate;
    short Year = ReadNumber("Enter Year: ");
    short Month = ReadNumber("Enter Month: ");
    short Day = ReadNumber("Enter Day: ");

    NewDate.Day = Day;
    NewDate.Month = Month;
    NewDate.Year = Year;

    return NewDate;
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

bool IsDayLast(Date NewDate)
{
    return NewDate.Day == DaysInMonth(NewDate.Year, NewDate.Month);
}

bool IsMonthLast(Date NewDate)
{
    return NewDate.Month == 12;
}

bool IsDate1LessThanDate2(Date Date1, Date Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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
    }
    else
    {
        NewDate.Day++;
    }
}

void SwapDates(Date &NewDate1, Date &NewDate2)
{
    Date Temp;
    Temp = NewDate1;
    NewDate1 = NewDate2;
    NewDate2 = Temp;
}

int CalculateDateDifference(Date NewDate1, Date NewDate2, bool IncludeEndDay = false)
{
    int SwapValue = 1;

    if (IsDate1LessThanDate2(NewDate2, NewDate1))
    {
        SwapDates(NewDate1, NewDate2);
        SwapValue = -1;
    }

    int Counter = 0;
    while (IsDate1LessThanDate2(NewDate1, NewDate2))
    {
        AddOneDayToDate(NewDate1);
        Counter++;
    }
    
    return SwapValue * (IncludeEndDay ? ++Counter : Counter);
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Date NewDate1 = ReadAndCreateDate();
        Date NewDate2 = ReadAndCreateDate();

        int Diff = CalculateDateDifference(NewDate1, NewDate2);
        int DiffInclEnd = CalculateDateDifference(NewDate1, NewDate2, true);

        cout << "Difference is: " << Diff << endl;
        cout << "Difference including last day is: " << DiffInclEnd << endl;
    }

    return 0;
}
