#include <bits/stdc++.h>
#include <ctype.h>
typedef double _d;
#define uint unsigned int
using namespace std;
int calculate(string s)
{
    // first find multiply
    std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
    s.erase(end_pos, s.end());
    string input = s;
    std::deque<std::string> in_arr;
    string temp = "";
    for (uint i = 0; i < input.size(); i++)
    {
        if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
        {
            std::string k{s[i]};
            in_arr.push_back(temp), in_arr.push_back(k), temp = "";
        }
        else
            temp += s[i];
    }
    if (temp.size() != 0)
    {
        in_arr.push_back(temp);
    }

    auto mloc = find(in_arr.begin(), in_arr.end(), "*");
    auto dloc = find(in_arr.begin(), in_arr.end(), "/");

    std::vector<std::string>::iterator cloc;

    if (mloc == in_arr.end())
    {
        if (dloc == in_arr.end())
        {
            ;
        }
        else
        {
            while (dloc != in_arr.end())
            {
                int idx = dloc - in_arr.begin();
                int lhs = std::stoi(in_arr[idx - 1]);
                int rhs = std::stoi(in_arr[idx + 1]);
                int new_val = lhs / rhs;
                in_arr[idx - 1] = to_string(new_val);
                in_arr.erase(in_arr.begin() + idx, in_arr.begin() + idx + 2);
                dloc = find(in_arr.begin(), in_arr.end(), "/");
            }
        }
    }
    else
    {
        if (dloc == in_arr.end())
        {
            while (mloc != in_arr.end())
            {
                int idx = mloc - in_arr.begin();
                int lhs = std::stoi(in_arr[idx - 1]);
                int rhs = std::stoi(in_arr[idx + 1]);
                int new_val = lhs * rhs;
                in_arr[idx - 1] = to_string(new_val);
                in_arr.erase(in_arr.begin() + idx, in_arr.begin() + idx + 2);
                mloc = find(in_arr.begin(), in_arr.end(), "*");
            }
        }
        else
        {
            while (mloc != in_arr.end() || dloc != in_arr.end())
                if (mloc - in_arr.begin() > dloc - in_arr.begin())
                {
                    int idx = dloc - in_arr.begin();
                    int lhs = std::stoi(in_arr[idx - 1]);
                    int rhs = std::stoi(in_arr[idx + 1]);
                    int new_val = lhs / rhs;
                    in_arr[idx - 1] = to_string(new_val);
                    in_arr.erase(in_arr.begin() + idx, in_arr.begin() + idx + 2);
                    dloc = find(in_arr.begin(), in_arr.end(), "/");
                    mloc = find(in_arr.begin(), in_arr.end(), "*");
                }
                else
                {
                    int idx = mloc - in_arr.begin();
                    int lhs = std::stoi(in_arr[idx - 1]);
                    int rhs = std::stoi(in_arr[idx + 1]);
                    int new_val = lhs * rhs;
                    in_arr[idx - 1] = to_string(new_val);
                    in_arr.erase(in_arr.begin() + idx, in_arr.begin() + idx + 2);
                    mloc = find(in_arr.begin(), in_arr.end(), "*");
                    dloc = find(in_arr.begin(), in_arr.end(), "/");
                }
        }
    }
    int tint = 0;
    for (uint i = 0; i < in_arr.size(); i++)
    {
        if (in_arr[i] == "+")
        {
            tint += std::stoi(in_arr[i + 1]);
            in_arr.pop_front();
            in_arr.pop_front();
            in_arr.pop_front();
            in_arr.push_front(to_string(tint));
            i = 0;
        }
        else if (in_arr[i] == "-")
        {
            tint -= std::stoi(in_arr[i + 1]);
            in_arr.pop_front();
            in_arr.pop_front();
            in_arr.pop_front();
            in_arr.push_front(to_string(tint));
            i = 0;
        }
        else
        {
            tint = std::stoi(in_arr[i]);
        }
    }
    return std::stoi(in_arr[0]);
}
int main() { calculate("5 +4*8*9/4*19"); }
