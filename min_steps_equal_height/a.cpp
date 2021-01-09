#include <bits/stdc++.h>
#define wayone
using namespace std;
//given array [5,4,3,3,3,1,7,7,8,8,8,8,0]
//make all idx equal, only removals
//  can only remove up to penultimax from current max

//way 1 intrprtn: can remove from all piles with max height

//way 2 only remove from first/last pile with max height


int min_make_equal(std::vector<int> v){
    std::map<int,int,std::greater<int>> occ;
    for (auto num : v)
        occ[num]++;
    int k = 0, j = 0, h = 0;
    for (auto i : occ)
        k+=i.second, j+=k, h=k;
    return j-h;

}


int main(){
    std::cout << min_make_equal({1, 1, 2, 2, 2, 3, 3, 3, 4, 4})<<"\n";
}
