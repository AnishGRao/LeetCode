#include <bits/stdc++.h>
typedef double _d;
using namespace std;
bool searchMatrix_slow(vector<vector<int>> & matrix, int target)
{
    for (int r = 0, c = matrix[0].size() - 1; r < matrix.size() && c >= 0;)
    {
        if (matrix[r][c] > target)
            c--;
        else if (matrix[r][c] < target)
            r++;
        else
            return true;
    }
    return false;
}

// beats 99.66% of answers.
bool searchMatrix(vector<vector<int>> & a, int b)
{
    ios::sync_with_stdio(0);
    if (a.size() == 1 && a[0].size() == 0)
        return false;
    while (!a.empty())
    {
        auto c = a[0][a[0].size() - 1];
        if (c == b)
            return true;
        else if (c > b)
            for (int d = 0; d < a.size(); d++)
            {
                a[d].pop_back();
                if (a[d].empty())
                    a.erase(a.begin() + d);
            }
        else
            a.erase(a.begin());
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{-1, 3}};
    int target = 3;
    searchMatrix(matrix, target);
}
