#include <bits/stdc++.h>
using namespace std;
int myAtoi(string str)
{
    string s = "";
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
    int i = 0;
    for (auto a : str)
    {
        if (i == 0 && (isdigit(a) || a == '+' || a == '-'))
            s += a;
        else if (isdigit(a))
            s += a;
        else
        {
            break;
        }
        i++;
    }
    try
    {
        return (s == "" || s == "+" || s == "-") ? 0 : stoi(s);
    }
    catch (exception e)
    {
        return (str[0] == '-') ? INT_MIN : INT_MAX;
    }
}