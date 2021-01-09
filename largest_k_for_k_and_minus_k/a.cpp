#include <bits/stdc++.h>
using namespace std;
//[3, 2, -2, 5, -3]
int large(std::vector<int> v){
    std::map<int,int, std::greater<int>> lar;
    for (auto i : v)
        lar[i<0 ? -1*i : i]++;
    while(lar.size()>0 && lar.begin()->second < 2)
        lar.erase(lar.begin());
    if (lar.size()==0)
        return 0;
    return lar.begin()->first;
}

int main(){
    std::cout << large({-41,3,2,5,41})<<"\n";
}
