#include <bits/stdc++.h>
using namespace std;
//[1,2,0,4]
void duplicateZeros(vector<int> & arr)
{
    auto beg = arr.begin();
    auto it = std::find_if(beg, arr.end(), [](const int & a) { return a == 0; });
    while (it != arr.end())
    {
        arr.insert(it, 0);
        beg += std::distance(beg, it + 1);
        it = std::find_if(beg, arr.end(), [](const int & a) { return a == 0; });
    }
}

int main()
{
    std::vector<int> temp = {1, 0, 2, 3, 0, 4, 5, 0};
    duplicateZeros(temp);
    for (auto i : temp)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}