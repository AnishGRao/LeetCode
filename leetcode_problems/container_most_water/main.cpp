#include <bits/stdc++.h>

int maxArea(std::vector<int> & height)
{
    auto _s = height.begin();
    int i = 0, j = height.size() - 1, _m;
    while (i < j)
    {
        _m = std::max(_m, std::min(*(_s + i), *(_s + j)) * (j - i));
        *(_s + i) < *(_s + j) ? --j : ++i;
    }
    return _m;
}

int main() { return 0; }