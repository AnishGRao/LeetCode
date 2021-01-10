#include <bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = (int)obstacleGrid.size(),n=(int)obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        bool rock = false;
        for (int i = 0; i<m; i++)
            dp[i][0] = rock || obstacleGrid[i][0] ? 0 : 1, rock = obstacleGrid[i][0] ? 1 : rock;
        rock=false;
        for (int i = 0; i<n; i++)
            dp[0][i] = rock || obstacleGrid[0][i] ? 0 : 1, rock = obstacleGrid[0][i] ? 1 : rock;;  
        
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
}
int main(){

}
