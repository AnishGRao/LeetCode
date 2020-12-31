#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    string s = std::to_string(x);
    // edge case for overflow
    try
    {
        return (x < 0) ? -1 * std::stoi(string(s.rbegin(), s.rend())) : std::stoi(string(s.rbegin(), s.rend()));
    }
    catch (exception e)
    {
        return 0;
    }
}

int main()
{
    reverse(1534236469);
    return 0;
}