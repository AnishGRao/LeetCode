#include <bits/stdc++.h>
using namespace std;
int m, n, ans = 0;
    //set value to 3 if we visited
void dfs(vector<vector<int>>& grid, int i , int j, int zcnt){
	if (i>=m || j>=n || i<0 || j<0 || grid[i][j]==-1 || grid[i][j]==3 || (grid[i][j]==2 && zcnt>0))
	    return;
	if (grid[i][j]==2)
	    ans++;
	if (grid[i][j]==0)
	    zcnt--;
	auto tmp = grid[i][j];
	grid[i][j] = 3;
	dfs(grid, i+1, j, zcnt);
	dfs(grid, i-1, j, zcnt);
	dfs(grid, i, j+1, zcnt);
	dfs(grid, i, j-1, zcnt);
	grid[i][j] = tmp;
}
    
    
    
int uniquePathsIII(vector<vector<int>>& grid) {
	m = (int)grid.size(),n=(int)grid[0].size();
	int zeroes=0, row, col;

	for (int i = 0; i<m; i++)
	    for (int j = 0; j<n; j++)
	        zeroes += grid[i][j] == 0 ? 1 : 0, row = grid[i][j] == 1 ? i : row, col = grid[i][j] == 1 ? j : col;
	dfs(grid, row, col, zeroes);
	return ans;
}
int main(){

}
