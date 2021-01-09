#include <bits/stdc++.h>
typedef double _d;
using namespace std;
// exceeds timelimit
vector<int> naive_productExceptSelf(vector<int> & nums)
{
    // initialize 1d ones
    std::vector<int> out(nums.size(), 1);
    for (uint i = 0; i < nums.size(); i++)
        for (uint j = 0; j < nums.size(); j++)
            out[i] *= i == j ? 1 : nums[j];
    return out;
}
// still exceeds time limit
vector<int> less_naive_productExceptSelf(vector<int> & nums)
{
    // initialize 1d ones
    int fullprod = std::accumulate(std::begin(nums), std::end(nums), 1, std::multiplies<int>());
    std::vector<int> out(nums.size());
    for (uint i = 0; i < nums.size(); i++)
    {
        out[i] = std::accumulate(std::begin(nums) + 1, std::end(nums), 1, std::multiplies<int>());
        std::iter_swap(nums.begin(), nums.begin() + i + 1);
    }
    return out;
}

// worked really nicely
vector<int> even_less_naive_productExceptSelf(vector<int> & nums)
{
    // initialize 1d ones
    int fullprod = std::accumulate(std::begin(nums), std::end(nums), 1, std::multiplies<int>());
    std::vector<int> out(nums.size());
    if (fullprod == 0)
    {
        for (uint i = 1; i < nums.size(); i++)
        {
            out[i - 1] = std::accumulate(std::begin(nums) + 1, std::end(nums), 1, std::multiplies<int>());
            std::iter_swap(nums.begin(), nums.begin() + i);
        }
        out[nums.size() - 1] = std::accumulate(std::begin(nums) + 1, std::end(nums), 1, std::multiplies<int>());
    }
    else
    {
        for (uint i = 0; i < nums.size(); i++)
        {
            out[i] = fullprod / nums[i];
        }
    }
    return out;
}

// beats 99% in runtime
vector<int> productExceptSelf(vector<int> & nums)
{
    // traverse from either side
    int s = nums.size(), a = 1, b = 1;
    vector<int> c(s, 1);
    for (int i = 0, j = s - 1; i < s - 1 && j > 0; i++, j--)
        a *= nums[i], b *= nums[j], [i + 1] *= a, c[j - 1] *= b;
    return c;
}

int main()
{
    std::vector<int> g = {9, 0, -2};
    even_less_naive_productExceptSelf(g);
}
