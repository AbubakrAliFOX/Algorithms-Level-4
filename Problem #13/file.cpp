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

bool IsDate1LessThanDate2(Date Date1, Date Date2)
{
    if (Date1.Year > Date2.Year)
    {
        return false;
    }
    else if (Date1.Year < Date2.Year)
    {
        return true;
    }
    else if (Date1.Year == Date2.Year)
    {
        if (Date1.Month > Date2.Month)
        {
            return false;
        }
        else if (Date1.Month < Date2.Month)
        {
            return true;
        }
        else if (Date1.Month == Date2.Month)
        {
            if (Date1.Day > Date2.Day)
            {
                return false;
            }
            else if (Date1.Day < Date2.Day)
            {
                return true;
            }
            else if (Date1.Day == Date2.Day)
            {
                return false;
            }
        }
    }
}

int main()
{
    bool RunLoop = true;

    while (RunLoop)
    {
        Date NewDate1;
        Date NewDate2;
        ReadAndCreateDate(NewDate1);
        ReadAndCreateDate(NewDate2);

        if (IsDate1LessThanDate2(NewDate1, NewDate2))
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
