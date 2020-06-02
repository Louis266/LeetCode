#include <string>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

bool checkLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0 && year % 400 != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int countDays(string date)
{
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));    
    int days = 0;
    int m_31[7] = {1, 3, 5, 7, 8, 10, 12};
    int m_30[4] = {4, 6, 9, 11};

    vector<int> m31(m_31, m_31 + 7);
    vector<int> m30(m_30, m_30 + 4);
    for (int i = 1; i < month; i++)
    {
        if (count(m31.begin(), m31.end(), i))
        {
            days += 31;
        }
        if (count(m30.begin(), m30.end(), i))
        {
            days += 30;
        }
        if (i == 2)
        {
            if (checkLeapYear(year))
            {
                days += 29;
            }
            else
            {
                days += 28;
            }
        }
    }

    days += day;

    return days;
}

int totalDays(string date1, string date2)
{
    int days_total = 0;
    int year_1 = stoi(date1.substr(0, 4));
    int month_1 = stoi(date1.substr(5, 2));
    int day_1 = stoi(date1.substr(8, 2));

    int year_2 = stoi(date2.substr(0, 4));
    int month_2 = stoi(date2.substr(5, 2));
    int day_2 = stoi(date2.substr(8, 2));

    if (checkLeapYear(year_1))
    {
        days_total += 366 - countDays(date1);
    }
    else
    {
        days_total += 365 - countDays(date1);
    }

    for (int i = year_1 + 1; i < year_2; i++)
    {
        days_total += checkLeapYear(i) ? 366 : 365;
    }

    days_total += countDays(date2);

    return days_total;
}

int daysBetweenDates(string date1, string date2)
{
    int days_total = 0;
    int year_1 = stoi(date1.substr(0, 4));
    int month_1 = stoi(date1.substr(5, 2));
    int day_1 = stoi(date1.substr(8, 2));

    int year_2 = stoi(date2.substr(0, 4));
    int month_2 = stoi(date2.substr(5, 2));
    int day_2 = stoi(date2.substr(8, 2));

    if (year_1 == year_2) // same year
    {
        int days1 = countDays(date1);
        int days2 = countDays(date2);
        return days1 > days2 ? days1 - days2 : days2 - days1;
    }

    days_total = year_2 > year_1 ? totalDays(date1, date2): totalDays(date2,date1);

    return days_total;
}

int main()
{

    string date_1 = "2019-12-20";
    string date_2 = "2020-12-20";
    string date_3 = "1996-12-20";
    string date_4 = "2020-11-20";

    string date_5 = "2019-12-31";
    string date_6 = "2020-01-15";

    // int year_1 = stoi(date_1.substr(0, 4));
    // int month_1 = stoi(date_1.substr(5, 2));
    // int day_1 = stoi(date_1.substr(8, 2));

    // cout << year_1 << "-" << month_1 << "-" << day_1 << endl;
    cout << countDays(date_5) << endl;


    cout << "Days between "
         << date_6 << " and "
         << date_5 << " is "
         << daysBetweenDates(date_6, date_5)
         << endl;
}