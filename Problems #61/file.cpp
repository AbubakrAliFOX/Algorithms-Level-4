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

bool IsDate1BeforeDate2(Date Date1, Date Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualtoDate2(Date Date1, Date Date2)
{
    return Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : (false);
}

bool IsDate1AfterDate2(Date Date1, Date Date2)
{
    return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualtoDate2(Date1, Date2);
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

    if (IsDate1BeforeDate2(NewDate2, NewDate1))
    {
        SwapDates(NewDate1, NewDate2);
        SwapValue = -1;
    }

    int Counter = 0;
    while (IsDate1BeforeDate2(NewDate1, NewDate2))
    {
        AddOneDayToDate(NewDate1);
        Counter++;
    }

    return SwapValue * (IncludeEndDay ? ++Counter : Counter);
}

enum BeforeAfterEqualDate
{
    After = 1,
    Before = -1,
    Equal = 0
};

BeforeAfterEqualDate CompareTwoDates(Date Date1, Date Date2)
{
    return IsDate1BeforeDate2(Date1, Date2) ? (BeforeAfterEqualDate::Before) : (IsDate1EqualtoDate2(Date1, Date2) ? BeforeAfterEqualDate::Equal : BeforeAfterEqualDate::After);
}

bool IsDateWithinPeriod(Period NewPeriod, Date NewDate)
{
    return !(CompareTwoDates(NewDate, NewPeriod.Start) == BeforeAfterEqualDate::Before || CompareTwoDates(NewDate, NewPeriod.End) == BeforeAfterEqualDate::After);
}

bool AreDatesOverLapping(Period Period1, Period Period2)
{
    if (CompareTwoDates(Period2.End, Period1.Start) == BeforeAfterEqualDate::Before || CompareTwoDates(Period2.Start, Period1.End) == BeforeAfterEqualDate::After)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int PeriodLength(Period NewPeriod, bool IncludeEndDay = false)
{
    return CalculateDateDifference(NewPeriod.Start, NewPeriod.End, IncludeEndDay);
}

int OverlapDays(Period Period1, Period Period2)
{
    if (!AreDatesOverLapping(Period1, Period2))
        return -999;

    int Period1Length = PeriodLength(Period1, true);
    int Period2Length = PeriodLength(Period2, true);
    int OverlapCounter = 0;

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.Start, Period1.End))
        {
            if (IsDateWithinPeriod(Period2, Period1.Start))
            {
                OverlapCounter++;
            }
            AddOneDayToDate(Period1.Start);
        }
    } else {
        while (IsDate1BeforeDate2(Period2.Start, Period2.End))
        {
            if (IsDateWithinPeriod(Period1, Period2.Start))
            {
                OverlapCounter++;
            }
            AddOneDayToDate(Period2.Start);
        }
    }


    return OverlapCounter;
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Period Period1;
        Period1.Start.Year = 2022;
        Period1.Start.Month = 1;
        Period1.Start.Day = 1;
        Period1.End.Year = 2022;
        Period1.End.Month = 1;
        Period1.End.Day = 10;

        Period Period2 = ReadAndCreatePeriod();

        cout << "Overlappin days are: " << OverlapDays(Period1, Period2) << endl;
    }

    return 0;
}
