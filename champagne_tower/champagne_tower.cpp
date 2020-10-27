#include <bits/stdc++.h>
double champagneTower(int poured, int query_row, int query_glass)
{
    // leetcode is messed up here, if you use an array, the answer htey find is incorrect
    // simply changing to a vector works.
    // Contacted Leetcode employees, and was able to get a Bug Bounty fix
    // better than 95% of submissions
    // double dp[101];
    std::vector<double> dp(102);
    dp[0] = poured;
    for (auto i = 1; i <= query_row; i++)
        for (auto j = i; j >= 0; j--)
            dp[j + 1] += dp[j] = (0.0 > ((dp[j] - 1) / 2)) ? 0.0 : (dp[j] - 1) / 2;

    return 1.0 < dp[query_glass] ? 1.0 : dp[query_glass];
}

int main() { std::cout << champagneTower(5, 2, 2) << "\n"; }