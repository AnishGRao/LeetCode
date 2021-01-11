#include <bits/stdc++.h>
using namespace std;
int largest_in_row(std::vector<char> &h){
	if (h.empty())
	    return 0;
	h.push_back(0);
	std::stack<int> s;
	s.push(-1);
	int cans = 0, ta, tb;
	for (int i = 0; i< h.size(); i++){
	    while((int)h[i]<(int)h[s.top() == -1 ? h.size()-1 : s.top()])
	        ta = (int)h[s.top() == -1 ? h.size()-1 : s.top()], s.pop(), tb = i - s.top() -1, cans = std::max(cans,ta*tb);
	    s.push(i);
	}
	return cans;
}
//island question
int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.empty() || matrix[0].empty())
	    return 0;

	int m = matrix.size(), n = matrix[0].size();
	for (int i = 0; i<m; i++)
	    for (int j = 0; j<n; j++)
	        matrix[i][j] = matrix[i][j] == '1' ? 1 + (i>0 ? int(matrix[i-1][j]) : 0) : 0;
	int max = 0;
	for (auto row : matrix)
	    max = std::max(max, largest_in_row(row));
	return max;        
}
int main(){

}
