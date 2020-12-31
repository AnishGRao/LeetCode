#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    auto _s = s.begin(), _e = s.begin();
    for (; _e != s.end(); _e++)
    {
        if (*_e == ' ')
        {
            reverse(_s, _e);
            _s = _e + 1;
        }
    }
    reverse(_s, s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    cout << reverseWords("the sky is blue") << "\n";
    return 0;
}
