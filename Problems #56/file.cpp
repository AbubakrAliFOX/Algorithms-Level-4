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

short OrderOfDate(short Year, short Month, short Day)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2; // Gregorian://0:sun, 1:Mon, 2:Tue...etc
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short OrderOfDate(Date NewDate)
{
    return OrderOfDate(NewDate.Year, NewDate.Month, NewDate.Day);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}

void PrintDate(Date NewDate)
{
    string DateString = to_string(NewDate.Day) + "/" + to_string(NewDate.Month) + "/" + to_string(NewDate.Year);

    cout << "\n\n"
         << DayShortName(OrderOfDate(NewDate)) << ", " << DateString << endl;
}

bool IsWeekEnd(Date NewDate)
{
    string DayName = DayShortName(OrderOfDate(NewDate));
    return DayName == "Fri" || DayName == "Sat";
}

bool IsWorkDay(Date NewDate)
{
    return !IsWeekEnd(NewDate);
}

Date AddVacationDaysToDate(Date VacationBeginningDate, short VacationDays)
{

    while (IsWeekEnd(VacationBeginningDate))
    {
        AddOneDayToDate(VacationBeginningDate);
    }

    while (VacationDays >= 1)
    {
        if (IsWorkDay(VacationBeginningDate))
        {
            VacationDays--;
        }
        AddOneDayToDate(VacationBeginningDate);
    }

    return VacationBeginningDate;
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
    return !IsDate1BeforeDate2(Date1,Date2) && !IsDate1EqualtoDate2(Date1,Date2);
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Date NewDate1 = ReadAndCreateDate();
        Date NewDate2 = ReadAndCreateDate();

        if (IsDate1AfterDate2(NewDate1, NewDate2))
        {
            cout << "TRUE" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }

    return 0;
}
