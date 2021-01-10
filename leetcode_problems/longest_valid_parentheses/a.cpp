#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
        std::stack<int> open, close; int main(){
        int k = 0;
        for (int i = 0; i<s.size(); i++){}
            if (s[i]=='(')
                open.push(i);
            else if(open.size()>0)
                s[i] = s[open.top()] = 'V', open.pop();
        }
        
        int max = 0;
        int curr = 0;
        for (int i = 0; i<s.size(); i++){
            while(s[i]=='V' && i<s.size())
                curr++,i++;
            max = curr>max?curr:max;
            curr=0;
        }
        
        return max;
}
