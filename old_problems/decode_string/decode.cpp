#include <bits/stdc++.h>
using namespace std;
string decodeString(string s)
{
    std::stack<std::string> chars;
    std::stack<int> nums;
    auto str = (std::string) "";
    auto number = 0;
    for (auto c : s)
    {
        if (isdigit(c))
        {
            number *= 10;
            number += c - '0';
        }
        else if (isalpha(c))
        {
            str += c;
        }
        else if (c == '[')
        {
            chars.push(str);
            nums.push(number);
            str = "";
            number = 0;
        }
        else if (c == ']')
        {
            std::string S = str;
            for (int i = 0; i < nums.top() - 1; i++)
                str += S;
            nums.pop();
            str = chars.top() + str;
            chars.pop();
        }
    }
    return str;
}
int main()
{
    assert(decodeString("2[abc]3[cd]ef3[a2[c]]") == "abcabccdcdcdefaccaccacc");
    std::cout << "goof";
}