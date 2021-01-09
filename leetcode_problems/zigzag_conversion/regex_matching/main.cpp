#include <bits/stdc++.h>
using namespace std;
// recursive solution
std::string::iterator A, B;
void _next(std::string::iterator str, std::string::iterator match, bool & ans)
{
    if (ans)
        return;

    if (std::next(match) == B)
    {
        if (std::next(str) == A)
            ans = true;
        return;
    }

    if (std::next(str) == A)
    {
        if (*match == '*')
            _next(str, match - 2, ans);
        return;
    }

    if (*str == *match || *match == '.')
    {
        _next(str - 1, match - 1, ans);
        return;
    }

    if (*match == '*')
    {
        if (*str == *(match - 1) || *(match - 1) == '.')
            _next(str - 1, match, ans);
        _next(str, match - 2, ans);
    }
}

bool isMatch(string s, string p)
{
    bool ans = false;
    A = s.begin();
    B = p.begin();
    // TODO replace with begin
    _next(s.end() - 1, p.end() - 1, ans);
    return ans;
}

int main()
{
    std::string j = isMatch("aaaabddd", "a*abbd*") ? "true" : "false";
    std::cout << j;
    return 0;
}