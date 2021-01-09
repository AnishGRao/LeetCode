#include <bits/stdc++.h>
typedef double _d;
using namespace std;
int maxSubArray(vector<int> & nums)
{
    std::vector<int> memo(nums.size());
    memo[0] = nums[0];
    for (int i = 1; i < (int)nums.size(); i++)
        if (memo[i - 1] > 0)
            memo[i] += nums[i];
        else
            memo[i] = nums[i];
}

return memo[0];
}
int main() {}