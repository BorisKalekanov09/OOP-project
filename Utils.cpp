#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
string normalizeDate(const string &input)
{
    if (input.empty())
        return string();

    int y, m, d;
    char sep1, sep2;
    istringstream iss(input);

    if (!(iss >> y >> sep1 >> m >> sep2 >> d))
        return string();

    if (sep1 != '-' || sep2 != '-')
        return string();

    if (y < 0 || m < 1 || m > 12 || d < 1)
        return string();

    int mdays = 31;
    if (m == 2)
    {
        bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
        mdays = leap ? 29 : 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        mdays = 30;
    }

    if (d > mdays)
        return string();

    ostringstream out;
    out << setw(4) << setfill('0') << y << '-' 
        << setw(2) << setfill('0') << m << '-' 
        << setw(2) << setfill('0') << d;

    return out.str();
}

string readDeadline(const string &prompt)
{
    string s;
    while (true)
    {
        cout << prompt;
        if (!getline(cin, s))
            return string();

        string norm = normalizeDate(s);
        if (!norm.empty())
            return norm;

        cout << "Invalid date. Please enter in YYYY-MM-DD (e.g. 2026-05-10)." << endl;
    }
}
