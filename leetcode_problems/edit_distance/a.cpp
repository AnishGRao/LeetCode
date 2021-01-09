#include <bits/stdc++.h>
using namespace std;
//NO HELP
//NO looking stuff up
//HARD QUESTION


//turn one word into another
//only insert, delete and change
//first thoughts:
//  map a map for both strings, find what letters are similar, and then equate them
//  if the string2||string1 is bigger, delete nonsimilar chars

int distance(std::string s1, std::string s2){
    auto sz1 = s1.size(), sz2 = s2.size();
    std::vector<std::vector<int>> dp(sz1+1,std::vector<int>(sz2+1, 0));
    for (int i = 1; i++<=sz1;)
        dp[i][0] = i;
    for (int j = 1; j++<=sz2;)
        dp[0][j] = j;
    for(int i = 1; i<=sz1; i++)
        for(int j = 1; j<=sz2; j++)
            dp[i][j] = s1[i-1]==s2[j-1] ? dp[i-1][j-1] : std::min(dp[i-1][j-1], std::min(dp[i][j-1], dp[i-1][j])) + 1;
    return dp[sz1][sz2];
}
//example:
/*


   turn horse -> ros

   dp starts as: 

    [0 1 2 3]
    [1 0 0 0]
    [2 0 0 0]
    [3 0 0 0]
    [4 0 0 0]
    [5 0 0 0]

   this gives us the original dp 2D matrix

   now, we loop.

   first outer loop:
    
    we start with i = j = 1, which we then check s1[0] vs s2[0], which is false. now the value of dp[1][1] = 1 (0+1)
    now, i=1, j=2, which is also false equality, so 


*/


int main(){

}
