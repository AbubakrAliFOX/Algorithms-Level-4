#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
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

short DaysInMonth(Date NewDate)
{
    short Month = NewDate.Month;
    short Day = NewDate.Day;
    short Year = NewDate.Year;

    int DaysOfMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month < 1 || Month > 12) ? 0 : (Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : (DaysOfMonths[Month - 1]));

    // In One Line:
    // return Month == 2 ? (IsLeapYear(Year) ? 29 : 28) : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
}

bool IsDayLast(Date NewDate)
{
    return NewDate.Day == DaysInMonth(NewDate);
}

bool IsMonthLast(Date NewDate)
{
    return NewDate.Month == 12;
}

bool IsDateValid(Date NewDate)
{
    return (NewDate.Month <= 12 && NewDate.Month >= 1) && ((NewDate.Day <= DaysInMonth(NewDate) && NewDate.Day >= 1));
}

vector<string> split(string Str, string Delim)
{

    short pos = 0;
    string sWord; // define a string variable  // use find() function to get the position of the delimiters
    short Counter = 0;
    vector<string> vWords;
    while ((pos = Str.find(Delim)) != std::string::npos)
    {
        sWord = Str.substr(0, pos); // store the word
        if (sWord != "")
        {
            vWords.push_back(sWord);
            Counter++;
        }
        Str.erase(0, pos + Delim.length()); /* erase() until positon and move to next word. */
    }
    if (Str != "")
    {
        vWords.push_back(Str); // it print last word of the string.
        Counter++;
    }

    return vWords;
}

Date StringToDate(string strDate)
{
    Date NewData;
    vector<string> vDate = split(strDate, "/");

    NewData.Day = stoi(vDate[0]);
    NewData.Month = stoi(vDate[1]);
    NewData.Year = stoi(vDate[2]);

    return NewData;
}


string DateToString(Date NewDate)
{
    string DateInString = to_string(NewDate.Day) + "/" + to_string(NewDate.Month) + "/" + to_string(NewDate.Year);
    return DateInString;
}

void PrintDate(Date NewDate)
{
    cout << "Day :" << NewDate.Day << endl;
    cout << "Month :" << NewDate.Month << endl;
    cout << "Year :" << NewDate.Year << endl;
}

int main()
{

    bool RunLoop = true;

    while (RunLoop)
    {
        Date Date1 = ReadAndCreateDate();
        // string strDate = "21/12/2022";
        cout << DateToString(Date1) << endl;
        // PrintDate(StringToDate(strDate));
    }

    return 0;
}
