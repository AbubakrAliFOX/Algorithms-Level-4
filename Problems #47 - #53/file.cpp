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

    cout << "\n\nToday is " << DayShortName(OrderOfDate(NewDate)) << ", " << DateString << endl;
}


bool IsEndOfWeek(Date NewDate) {
    string DayName = DayShortName(OrderOfDate(NewDate));
    return DayName == "Sat"; 
}


bool IsWeekEnd(Date NewDate) {
    string DayName = DayShortName(OrderOfDate(NewDate));
    return DayName == "Fri" || DayName == "Sat"; 
}

bool IsWorkDay(Date NewDate) {
    return !IsWeekEnd(NewDate); 
}

short DaysToEndOfWeek(Date NewDate) {
   return 6 - OrderOfDate(NewDate);
    
}

short DaysToEndOfMonth(Date NewDate) {
    return DaysInMonth(NewDate.Year, NewDate.Month) - NewDate.Day + 1;
}

short DaysToEndOfYear(Date NewDate) {
    short DaysToYearEnd = 0;
    while (NewDate.Month <= 12)
    {
        DaysToYearEnd += DaysToEndOfMonth(NewDate);
        NewDate.Month++;
        NewDate.Day = 1;
    }
    return DaysToYearEnd;
}


int main()
{

    bool RunLoop = true;

    // while (RunLoop)
    // {
    Date NewDate = GetSysDate();
    PrintDate(NewDate);

    if (IsEndOfWeek(NewDate))
    {
        cout << "End of week" << endl;
    }

    if (IsWeekEnd(NewDate))
    {
        cout << "Week End" << endl;
    }

     if (IsWorkDay(NewDate))
    {
        cout << "Work Day" << endl;
    }
    
    cout << "Days to end of week: " << DaysToEndOfWeek(NewDate) << endl;
    cout << "Days to end of month: " << DaysToEndOfMonth(NewDate) << endl;
    cout << "Days to end of year: " << DaysToEndOfYear(NewDate) << endl;
    // }

    return 0;
}
