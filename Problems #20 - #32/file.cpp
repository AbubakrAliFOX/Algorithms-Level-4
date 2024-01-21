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

void PrintDateOperation(Date CurrentDate, string Operation)
{
    string DateInString = to_string(CurrentDate.Day) + "/" + to_string(CurrentDate.Month) + "/" + to_string(CurrentDate.Year);
    cout << Operation << DateInString << endl;
}

void CheckNextYearCompatability(Date &NewDate) {
    if (NewDate.Day > DaysInMonth(NewDate.Year, NewDate.Month))
    {
        NewDate.Day = DaysInMonth(NewDate.Year, NewDate.Month);
    }
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

void IncreaseDateByxDays(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        AddOneDayToDate(NewDate);
    }
}

void IncreaseDateByOneWeek(Date &NewDate)
{
    for (int i = 0; i < 7; i++)
    {
        AddOneDayToDate(NewDate);
    }
}

void IncreaseDateByxWeeks(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        IncreaseDateByOneWeek(NewDate);
    }
}

void IncreaseDateByOneMonth(Date &NewDate)
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

    CheckNextYearCompatability(NewDate);
    
}

void IncreaseDateByXMonths(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        IncreaseDateByOneMonth(NewDate);
    }
}

void IncreaseDateByOneYear(Date &NewDate)
{
    NewDate.Year++;
    
    CheckNextYearCompatability(NewDate);
    
}

void IncreaseDateByXYears(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        IncreaseDateByOneYear(NewDate);
    }
}

void IncreaseDateByXYearsFaster(Date &NewDate, int X)
{
    NewDate.Year += X;

    CheckNextYearCompatability(NewDate);
}

void IncreaseDateByOneDecade(Date &NewDate)
{
    IncreaseDateByXYearsFaster(NewDate, 10);
}

void IncreaseDateByXDecades(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        IncreaseDateByOneDecade(NewDate);
    }
}

void IncreaseDateByXDecadesFaster(Date &NewDate, int X)
{
    NewDate.Year += (X * 10);

    CheckNextYearCompatability(NewDate);
} 

void IncreaseDateByOneCentury(Date &NewDate)
{
    NewDate.Year += 100;
} 

void IncreaseDateByXCenturies(Date &NewDate, int X)
{
    NewDate.Year += (X * 100);
} 

void IncreaseDateByOneMellinium(Date &NewDate)
{
    NewDate.Year += 1000;
} 

void IncreaseDateByXMellinia(Date &NewDate, int X)
{
    NewDate.Year += (X * 1000);
} 

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Date NewDate1 = ReadAndCreateDate();

        cout << "\n\nDate after: \n\n";

        AddOneDayToDate(NewDate1);
        PrintDateOperation(NewDate1, "01 - Adding one day: ");

        IncreaseDateByxDays(NewDate1, 10);
        PrintDateOperation(NewDate1, "02 - Adding 10 days: ");

        IncreaseDateByOneWeek(NewDate1);
        PrintDateOperation(NewDate1, "03 - Adding one week: ");

        IncreaseDateByxWeeks(NewDate1, 10);
        PrintDateOperation(NewDate1, "04 - Adding 10 weeks: ");

        IncreaseDateByOneMonth(NewDate1);
        PrintDateOperation(NewDate1, "05 - Adding 1 month: ");

        IncreaseDateByXMonths(NewDate1, 5);
        PrintDateOperation(NewDate1, "06 - Adding 5 months: ");

        IncreaseDateByOneYear(NewDate1);
        PrintDateOperation(NewDate1, "07 - Adding 1 year: ");

        IncreaseDateByXYears(NewDate1, 10);
        PrintDateOperation(NewDate1, "08 - Adding 10 years: ");

        IncreaseDateByXYearsFaster(NewDate1, 10);
        PrintDateOperation(NewDate1, "09 - Adding 10 years (faster): ");


        IncreaseDateByOneDecade(NewDate1);
        PrintDateOperation(NewDate1, "10 - Adding 1 decade: ");

        IncreaseDateByXDecades(NewDate1, 10);
        PrintDateOperation(NewDate1, "11 - Adding 10 decades: ");

        IncreaseDateByXDecadesFaster(NewDate1, 10);
        PrintDateOperation(NewDate1, "12 - Adding 10 decades (faster): ");

        IncreaseDateByOneCentury(NewDate1);
        PrintDateOperation(NewDate1, "13 - Adding 1 century: ");

        IncreaseDateByXCenturies(NewDate1, 10);
        PrintDateOperation(NewDate1, "14 - Adding 10 centuries: ");

        IncreaseDateByOneMellinium(NewDate1);
        PrintDateOperation(NewDate1, "15 - Adding 1 mellinuim: ");

        IncreaseDateByXMellinia(NewDate1, 10);
        PrintDateOperation(NewDate1, "16 - Adding 10 mellinia: ");
    }

    return 0;
}
