#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int longest = -1;
    unordered_map<char, int> check = {};
    int i = 0;
    for (int itr = 0; itr < s.size(); itr++)
    {
        char character = s[itr];
        int size_start = check.size();
        check[character] = 0;
        int size_end = check.size();
        if (size_end >= longest)
        {
            longest = check.size();
        }
        if (size_start == check.size())
        {
            check.clear();
            itr = i;
            i++;
        }
    }
    return (longest == -1) ? 0 : longest;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << "\n";
    cout << lengthOfLongestSubstring("bbbbb") << "\n";
    cout << lengthOfLongestSubstring("pwwkew") << "\n";
    cout << lengthOfLongestSubstring("dvdf") << "\n";
}
