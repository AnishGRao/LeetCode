#include <bits/stdc++.h>
using namespace std;

string operation(string s, int numRows)
{
    vector<string> rows;
    rows.resize(min(numRows, (int)s.size()));
    int cRow = 0;
    bool cond = 0;
    for (auto c : s)
    {
        rows[cRow] += c;
        cond = (!cRow | cRow == numRows - 1) ? !cond : cond;
        cRow += cond ? 1 : -1;
    }
    return accumulate(rows.begin(), rows.end(), string(),
                      [](const string & T1, const string & T2) -> string { return T1 + T2; });
}

string ret(string s) { return s; }
string convert(string s, int numRows) { return (numRows <= 1) ? ret(s) : operation(s, numRows); }
