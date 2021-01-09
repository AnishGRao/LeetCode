#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    vector<vector<bool>> palindrome;
    palindrome.resize(s.size(), vector<bool>(s.size()));
    int len = s.size();
    int ceil = 0, B, E;
    for (int row = 0; row < len; row++)
    {
        palindrome[row][row] = 1;
        for (int ele = 0; ele < row; ele++)
        {
            if (s[ele] == s[row] && (row - ele <= 2 || palindrome[ele + 1][row - 1]))
            {
                palindrome[ele][row] = 1;
                if (row - ele + 1 > ceil)
                {
                    ceil = row - ele + 1;
                    B = ele;
                    E = row;
                }
            }
        }
    }
    return (s.substr(B, E - B + 1) == "") ? s.substr(0, 1) : s.substr(B, E - B + 1);
}
int main() {}