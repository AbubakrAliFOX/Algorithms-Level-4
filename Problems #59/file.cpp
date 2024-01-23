#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

struct Date
{
    short Day, Month, Year;
};

struct Period
{
    Date Start, End;
};

short ReadNumber(string Msg = "Please Enter a number")
{
    short Number;
    cout << Msg << endl;
    cin >> Number;
    return Number;
}

Date GetSysDate()
{
    Date SysDate;
    time_t t = time(0);
    tm *now = localtime(&t);
    SysDate.Year = now->tm_year + 1900;
    SysDate.Month = now->tm_mon + 1;
    SysDate.Day = now->tm_mday;
    return SysDate;
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

Period ReadAndCreatePeriod()
{
    Period NewPeroid;
    cout << "\nEnter Period Begin: \n";
    NewPeroid.Start = ReadAndCreateDate();
    cout << "\nEnter Period End: \n";
    NewPeroid.End = ReadAndCreateDate();
    return NewPeroid;
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

bool IsDate1BeforeDate2(Date Date1, Date Date2)
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

int CalculateDateDifference(Date NewDate1, Date NewDate2, bool IncludeEndDay = false)
{

    if (IsDate1BeforeDate2(NewDate1, NewDate2))
    {
        int Counter = 0;
        while (IsDate1BeforeDate2(NewDate1, NewDate2))
        {
            AddOneDayToDate(NewDate1);
            Counter++;
        }

        return IncludeEndDay ? ++Counter : Counter;
    }
    else
    {
        return -1;
    }
}

int PeriodLength (Period NewPeriod, bool IncludeEndDay = false) {
    return CalculateDateDifference(NewPeriod.Start, NewPeriod.End,IncludeEndDay);
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Period Period1 = ReadAndCreatePeriod();

        cout << "Peroid length is: " << PeriodLength(Period1) << " days." << endl;
        cout << "Peroid length is (inlc. end date): " << PeriodLength(Period1, true) << " days." << endl;
        
    }

    return 0;
}
