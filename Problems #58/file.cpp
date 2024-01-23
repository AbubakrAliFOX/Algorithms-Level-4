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

bool AreDatesOverLapping(Period Period1, Period Period2)
{
    if (CompareTwoDates(Period2.End,Period1.Start) == BeforeAfterEqualDate::Before || CompareTwoDates(Period2.Start,Period1.End) == BeforeAfterEqualDate::After)
    {
        return false;
    } else {
        return true;
    }
    
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Period Period1 = ReadAndCreatePeriod();
        Period Period2 = ReadAndCreatePeriod();


        if (AreDatesOverLapping(Period1, Period2))
        {
            cout << "Yes" << endl;
        }
        
    }

    return 0;
}
