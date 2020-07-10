#include <bits/stdc++.h>
using namespace std;
// FSM solution

bool star_from_char(string s, string p);
bool dot_from_char(string s, string p);
bool char_from_dot(string s, string p);
bool char_from_star(string s, string p);
bool dot_from_star(string s, string p);
bool dot_from_dot(string s, string p);
bool star_from_dot();
bool char_from_char(string s, string p);
bool init_char(string s, string p);

bool star_from_char(string s, string p) {}

bool dot_from_char(string s, string p) {}

bool char_from_dot(string s, string p) {}

bool char_from_star(string s, string p) {}

bool dot_from_star(string s, string p) {}

bool star_from_dot(string s, string p) {}

bool char_from_char(string s, string p);

bool init_char(string s, string p)
{
    if (s[0] != p[0])
        return false;
    else
    {
        switch (p[1])
        {
            case '*':
                return star_from_char(s.substr(1), p.substr(1));
                break;
            case '.':
                return dot_from_char(s.substr(1), p.substr(1));
                break;
            default:
                return char_from_char(s.substr(1), p.substr(1));
                break;
        }
    }
}

bool init_dot(string s, string p)
{
    switch (p[1])
    {
        case '*':
            return star_from_dot(s.substr(1), p.substr(1));
            break;
        case '.':
            return dot_from_dot(s.substr(1), p.substr(1));
            break;
        default:
            return char_from_dot(s.substr(1), p.substr(1));
            break;
    }
}

bool init_star(string s, string p) {}

bool isMatch(string s, string p)
{
    reverse(s.begin(), s.end());
    reverse(p.begin(), p.end());
    switch (p[0])
    {
        case '*':
            return init_star(s, p);
            break;
        case '.':
            return init_dot(s, p);
            break;
        default:
            return init_char(s, p);
            break;
    }
}

int main() {}