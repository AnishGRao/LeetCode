#include <bits/stdc++.h>


std::vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int i, j, n = nums.size(), wins;
    wins = n - k + 1;                        // # of windows
    vector<int> lft(n), rgt(n);            // to store above explained lft and rgt
    rgt[n - 1] = nums[n - 1];
    for (i=0, j=n-2; i<n||j>=0; i++,j--){
        if ((i<n)){
            lft[i] = nums[i];
            if (i % k !=0) 
                lft[i] = max(lft[i - 1], lft[i]);                                                                                                                
        }
        if (j>=0){
            rgt[j] = nums[j];
            if (j% k != (k - 1))
                rgt[j]= max(rgt[j], rgt[j + 1]);                                                                                                                    
        }                                                                    
    }
    vector<int> ans;
    for (i = 0; i < wins; i++)
        ans.push_back(max(rgt[i], lft[i + k - 1]));
    return ans;
                                                                                                
}

int main(){
    return 0;
}
