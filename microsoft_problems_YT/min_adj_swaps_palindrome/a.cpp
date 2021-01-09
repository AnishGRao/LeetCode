#include <bits/stdc++.h>
using namespace std;
int palindrome(std::string I){
    int n = I.size();
    //allkklllkla
    //-1
    int count_badness = 0;
    int count = 0;
    for (int i = 0; i < n/2; i++){
        auto left = i, right = n-i-1;
        while(right>left){
            if (I[right]==I[left])
                break;
            else
                right--;
        }
        //first time: e.g
        //mamad
        if (right==left)
            if (++count_badness>1)
                return -1;
        
        for (int j = right; j<n-1-left; j++){
            std::swap(I[j],I[j+1]);
            count++;    
        }
    }
    return count;
}
//what i missed in video
int palindrome_helper(std::string inp){
    std::string rinp = inp;
    std::reverse(rinp.begin(),rinp.end());
    return std::min(palindrome(inp),palindrome(rinp))
}
int main(){
    std::string in_string= "ntiin";

    std::cout << std::palindrome_helper(in_string)<<"\n";
}
