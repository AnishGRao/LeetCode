#include <bits/stdc++.h>
typedef double _d;
using namespace std;
#define I_M 2147483647
int minPathSum(vector<vector<int>> & grid)
{
    int rows = (int)grid.size(), cols = (int)grid[0].size();
    std::vector<std::vector<int>> memo(rows, std::vector<int>(cols, I_M));
    memo[0][0] = grid[0][0];
    int max = I_M;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j && i == 0)
                continue;
            memo[i][j] =
                std::min((i - 1 < 0 ? I_M : memo[i - 1][j]), (j - 1 < 0 ? I_M : memo[i][j - 1])) + grid[i][j];
            if (i == rows - 1 && j == cols - 1)
                max = std::min(max, memo[i][j]);
        }
    }
    return rows == 1 && cols == 1 ? grid[0][0] : max;
}

int main()
{
    std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    std::cout << minPathSum(grid) << std::endl;
    return 0;
}