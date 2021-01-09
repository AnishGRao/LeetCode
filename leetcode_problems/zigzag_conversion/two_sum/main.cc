#include <bits/stdc++.h>
std::vector<int> twoSum(std::vector<int> & nums, int target)
{
    std::vector<int> copy = nums;
    std::sort(nums.begin(), nums.end());
    int itr_floor = 0;
    int itr_ceil = nums.size() - 1;
    for (;;)
    {
        if (nums[itr_floor] + nums[itr_ceil] == target && itr_floor != itr_ceil)
        {
            int first = (int)std::distance(copy.begin(), std::find(copy.begin(), copy.end(), nums[itr_floor]));
            copy[first] = -INT_MAX;
            return {first, (int)std::distance(copy.begin(), std::find(copy.begin(), copy.end(), nums[itr_ceil]))};
        }
        else if (nums[itr_floor] + nums[itr_ceil] < target)
            itr_floor += 1;
        else if (nums[itr_floor] + nums[itr_ceil] > target)
            itr_ceil -= 1;
    }
}
int main(int argc, char ** argv)
{
    std::vector<int> G;
    G.push_back(3);
    G.push_back(2);
    G.push_back(4);

    std::cout << twoSum(G, 6)[0] << "\t";
    std::cout << twoSum(G, 6)[1] << "\n";
    return 0;
}
