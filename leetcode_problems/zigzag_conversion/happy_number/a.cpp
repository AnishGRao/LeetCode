#include <bits/stdc++.h>
typedef double _d;
using namespace std;
bool isHappy(int n) {
    if (n==1)
        return true;
    std::set<int> a;
    std::string b,d;
    do {
        a.insert(n);
        b=std::to_string(n);
        n=0;
        for (char c : b)
            n+=(c - 48)*(c - 48);

        if (n==1)
            return true;


    }while(a.count(n)==0);
    return false;
}

int main()
{
}
