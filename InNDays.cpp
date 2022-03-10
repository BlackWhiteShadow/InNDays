#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool isNumber(const string& s)
{
    for (char const& ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

int intoNumbers(string day)
{
    if (day == "Monday") return  1;
    else if (day == "Tuesday") return 2;
    else if (day == "Wednesday") return 3;
    else if (day == "Thursday") return 4;
    else if (day == "Friday") return 5;
    else if (day == "Saturday") return 6;
    else if (day == "Sunday") return 7;
}

string intoString(int dayNumber)
{
    switch (dayNumber)
    {
    case 1:
        return "Monday";
        break;
    case 2:
        return "Tuesday";
        break;
    case 3:
        return "Wednesday";
        break;
    case 4:
        return "Thusday";
        break;
    case 5:
        return "Friday";
        break;
    case 6:
        return "Saturday";
        break;
    case 7:
        return "Sunday";
        break;
    }
}

vector<string> afterNDays(vector<string> days, int n) 
{
    vector<string> newDays;
    int dayNumber = 0;
    for (int i = 0; i < days.size(); i++)
    {
        dayNumber = intoNumbers(days[i]) + n;

        if (dayNumber > 7)
            dayNumber -= 7;

        newDays.push_back(intoString(dayNumber));
    }

    return newDays;
}

int main()
{
    string x;
    vector<string> days;
    int n;
    while (true)
    {
        cin >> x;
        if (isNumber(x))
        {
            n = stoi(x);
            break;
        }
        else
            days.push_back(x);
    }
    
    for(int i = 0; i < days.size(); i++)
        cout << afterNDays(days, n)[i] << " ";
}

