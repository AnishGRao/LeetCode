#include <bits/stdc++.h>
#define visresults
using namespace std;



bool isMatch(string s, string p) {
    //table with all 0s
    std::vector<std::vector<int>> dp(p.size()+1, std::vector<int>(s.size()+1,0));
    
    dp[0][0]=1;
    
    #ifdef visresults
    //show what the initial dp looks like.
    std::cout<<"Initial dp:\n";
    for (auto i : dp)
        for (int j = 0; j<i.size(); j++)
            std::cout << i[j] << (j == i.size() - 1 ? "\n" : " ");
    std::cout<<"\n\n";
    #endif
    
    //I know about true=1, but this is more readable.
    for (int i = 1; i<=p.size(); i++)
        dp[i][0] = p[i-1]=='*' && dp[i-1][0]==1 ? 1 : 0;
    
    #ifdef visresults
    //show what this does when there are stars.
    std::cout<<"After next dpization dp:\n";
    for (auto i : dp)
        for (int j = 0; j<i.size(); j++)
            std::cout << i[j] << (j == i.size() - 1 ? "\n" : " ");
    std::cout<<"\n\n";
    #endif
    

    for (int i = 1; i<= p.size(); i++){ 
            for (int j =1; j<= s.size(); j++){
                //basically, if it is a star, check if either (row-1,col) or (row,col-1) were 1 (indicating match)
                //  if so, then set to 1
                //If its a ? or it just matched, then just set it equal to the diagonal previous
                dp[i][j] = p[i-1] == '*' ? (dp[i-1][j]==1 || dp[i][j-1]==1 ? 1 : 0) :
                    (p[i-1]=='?' || p[i-1]==s[j-1]  ? dp[i-1][j-1] : dp[i][j]);
        
            }
            #ifdef visresults
                //show what is happening for every char in the regexed string.
                std::cout<<"After completion of character " << p[i-1] << ":\n";
                for (auto i : dp)
                    for (int j = 0; j<i.size(); j++)
                        std::cout << i[j] << (j == i.size() - 1 ? "\n" : " ");
                std::cout<<"\n\n";
            #endif
    }

    return dp[p.size()][s.size()];
}
int main(){
    isMatch("acdcb","a*c?b");
}
