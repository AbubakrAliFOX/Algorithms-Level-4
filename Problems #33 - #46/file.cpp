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

bool IsDayFirst(Date NewDate)
{
    return NewDate.Day == 1;
}


bool IsMonthFirst(Date NewDate)
{
    return NewDate.Month == 1;
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

void DecreaseOneDay(Date &NewDate)
{
    if (IsDayFirst(NewDate))
    {
        if (IsMonthFirst(NewDate))
        {
            NewDate.Month = 12;
            NewDate.Year--;
        } else {
            NewDate.Month--;
        }
        NewDate.Day = DaysInMonth(NewDate.Year, NewDate.Month);
        
    } else {
        NewDate.Day--;
    }
    
}

void DecreaseDateByxDays(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        DecreaseOneDay(NewDate);
    }
}

void DecreaseDateByOneWeek(Date &NewDate)
{
    for (int i = 0; i < 7; i++)
    {
        DecreaseOneDay(NewDate);
    }
}

void DecreaseDateByxWeeks(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        DecreaseDateByOneWeek(NewDate);
    }
}

void DecreaseDateByOneMonth(Date &NewDate)
{
    
    if (IsMonthFirst(NewDate))
    {
        NewDate.Month = 12;
        NewDate.Year--;
    }
    else
    {
        NewDate.Month--;
    }

    CheckNextYearCompatability(NewDate);
    
}

void DecreaseDateByXMonths(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        DecreaseDateByOneMonth(NewDate);
    }
}

void DecreaseDateByOneYear(Date &NewDate)
{
    NewDate.Year--;
    
    CheckNextYearCompatability(NewDate);
    
}

void DecreaseDateByXYears(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        DecreaseDateByOneYear(NewDate);
    }
}

void DecreaseDateByXYearsFaster(Date &NewDate, int X)
{
    NewDate.Year -= X;

    CheckNextYearCompatability(NewDate);
}

void DecreaseDateByOneDecade(Date &NewDate)
{
    DecreaseDateByXYearsFaster(NewDate, 10);
}

void DecreaseDateByXDecades(Date &NewDate, int X)
{
    for (int i = 0; i < X; i++)
    {
        DecreaseDateByOneDecade(NewDate);
    }
}

void DecreaseDateByXDecadesFaster(Date &NewDate, int X)
{
    NewDate.Year -= (X * 10);

    CheckNextYearCompatability(NewDate);
} 

void DecreaseDateByOneCentury(Date &NewDate)
{
    NewDate.Year -= 100;
} 

void DecreaseDateByXCenturies(Date &NewDate, int X)
{
    NewDate.Year -= (X * 100);
} 

void DecreaseDateByOneMellinium(Date &NewDate)
{
    NewDate.Year -= 1000;
} 

void DecreaseDateByXMellinia(Date &NewDate, int X)
{
    NewDate.Year -= (X * 1000);
} 

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Date NewDate1 = ReadAndCreateDate();

        cout << "\n\nDate after: \n\n";

        DecreaseOneDay(NewDate1);
        PrintDateOperation(NewDate1, "01 - Subtracting one day: ");

        DecreaseDateByxDays(NewDate1, 10);
        PrintDateOperation(NewDate1, "02 - Subtracting 10 days: ");

        DecreaseDateByOneWeek(NewDate1);
        PrintDateOperation(NewDate1, "03 - Subtracting one week: ");

        DecreaseDateByxWeeks(NewDate1, 10);
        PrintDateOperation(NewDate1, "04 - Subtracting 10 weeks: ");

        DecreaseDateByOneMonth(NewDate1);
        PrintDateOperation(NewDate1, "05 - Subtracting 1 month: ");

        DecreaseDateByXMonths(NewDate1, 5);
        PrintDateOperation(NewDate1, "06 - Subtracting 5 months: ");

        DecreaseDateByOneYear(NewDate1);
        PrintDateOperation(NewDate1, "07 - Subtracting 1 year: ");

        DecreaseDateByXYears(NewDate1, 10);
        PrintDateOperation(NewDate1, "08 - Subtracting 10 years: ");

        DecreaseDateByXYearsFaster(NewDate1, 10);
        PrintDateOperation(NewDate1, "09 - Subtracting 10 years (faster): ");


        DecreaseDateByOneDecade(NewDate1);
        PrintDateOperation(NewDate1, "10 - Subtracting 1 decade: ");

        DecreaseDateByXDecades(NewDate1, 10);
        PrintDateOperation(NewDate1, "11 - Subtracting 10 decades: ");

        DecreaseDateByXDecadesFaster(NewDate1, 10);
        PrintDateOperation(NewDate1, "12 - Subtracting 10 decades (faster): ");

        DecreaseDateByOneCentury(NewDate1);
        PrintDateOperation(NewDate1, "13 - Subtracting 1 century: ");

        DecreaseDateByXCenturies(NewDate1, 10);
        PrintDateOperation(NewDate1, "14 - Subtracting 10 centuries: ");

        DecreaseDateByOneMellinium(NewDate1);
        PrintDateOperation(NewDate1, "15 - Subtracting 1 mellinuim: ");

        DecreaseDateByXMellinia(NewDate1, 10);
        PrintDateOperation(NewDate1, "16 - Subtracting 10 mellinia: ");
    }

    return 0;
}
