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

bool IsDate1EqualtoDate2(Date Date1, Date Date2)
{
    return Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : (false);
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

        if (IsDate1EqualtoDate2(NewDate1, NewDate2))
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
