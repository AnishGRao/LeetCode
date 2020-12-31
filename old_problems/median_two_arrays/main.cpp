#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2)
{
    vector<double> destination;
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(destination));
    auto it1 = destination.begin();
    if (destination.size() % 2 == 0)
    {
        auto it2 = destination.begin();
        advance(it1, (destination.size() / 2.0) - 1.0);
        advance(it2, destination.size() / 2.0);
        return (*it1 + *it2) / 2.0;
    }
    else
    {
        advance(it1, (destination.size() - 1.0) / 2.0);
        return *it1;
    }
}

int main()
{
    vector<int> nums1 = {1, 1};
    vector<int> nums2 = {2, 3};
    double x = findMedianSortedArrays(nums1, nums2);
    cout << x << "\n";
    return 0;
}