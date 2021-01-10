#include <bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n,0));
        for (int i = 0; i<std::max(m,n); i++)
            dp[i<m ? i : 0 ][0] = 1, dp[0][i<n ? i : 0 ] = 1;
        for (int i = 1; i<m; i++)
            for (int j = 1; j<n; j++)
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp.back().back();
}
int main(){

}
