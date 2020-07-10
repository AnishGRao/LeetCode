#include <bits/stdc++.h>
using namespace std;
// supreme laziness
bool isPalindrome(int x)
{
    string str = to_string(x);
    if (!isdigit(str[0]))
        return false;
    return (str == string(str.rbegin(), str.rend()));
}

int main()
{
    isPalindrome(1001);
    return 0;
}