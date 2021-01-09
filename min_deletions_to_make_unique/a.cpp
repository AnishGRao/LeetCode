#include <bits/stdc++.h>
using namespace std;
int minDeletions(string s) {
        std::map<char, int> freq;
        for (auto c : s)
            freq[c]++;
        std::vector<std::pair<char,int>> A;
        for (auto i : freq)
            A.push_back({i.first, i.second});
        std::sort(A.begin(),A.end(),
                  [=](std::pair<char,int>&ta,std::pair<char,int>&tb)->bool{
                      return ta.second<tb.second;
                  }
                 );
        int num_del=0;
        std::vector<int> ovals;
        
        for (auto i : A){
            //for (auto i : ovals)
            //    std::cout<<i<<"\t";
            // std::cout<<"\n";
            if (std::find(ovals.begin(),ovals.end(),i.second)!=ovals.end()){
                int aa = i.second;
                while(true){
                    if (std::find(ovals.begin(),ovals.end(),--aa)==ovals.end()){
                        if (aa!=0)
                            ovals.push_back(aa);
                        num_del+=i.second-aa;
                        break;
                    }
                }
                continue;
            }
            ovals.push_back(i.second);
        }
        return num_del;
}
int main(){

}
