#include <iostream>
#include <cmath>
#include <string>
using namespace std;

long long int ReadNumber(string Msg = "Please Enter a number")
{
    long long int Number;
    cout << Msg << endl;
    cin >> Number;
    return Number;
}

string NumberToText(long long int Number)
{

    if (Number == 0)
        return " ";

    if (Number >= 0 && Number <= 19)
    {
        string arr[] = {"",
                        "One",
                        "Two",
                        "Three",
                        "Four",
                        "Five",
                        "Six",
                        "Seven",
                        "Eight",
                        "Nine",
                        "Ten",
                        "Eleven",
                        "Twelve",
                        "Thirteen",
                        "Fourteen",
                        "Fifteen",
                        "Sixteen",
                        "Seventeen",
                        "Eighteen",
                        "Nineteen"};
        return arr[Number];
    }

    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {"", "", "Twenty",
                        "Thirty",
                        "Fourty",
                        "Fifty",
                        "Sixty",
                        "Seventy",
                        "Eighty",
                        "Ninty"};
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 999)
    {

        return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 999999)
    {

        return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 999999999)
    {

        return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 999999999999)
    {

        return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
    }

    if (Number >= 1000000000000 && Number <= 999999999999999)
    {

        return NumberToText(Number / 1000000000000) + " Trillion " + NumberToText(Number % 1000000000000);
    }

    

    return 0;
}

int main()
{
    long long int Number = ReadNumber();

    cout << NumberToText(Number) << endl;

    return 0;
}
