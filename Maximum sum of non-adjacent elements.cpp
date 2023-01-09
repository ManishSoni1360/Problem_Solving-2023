Problem:
You are given an array/list of 'N' integers. You are supposed to return the maximum sum of the subsequence
with the constraint that no two elements are adjacent in the given array/list.

Solution:

#include <bits/stdc++.h> 

int fun(int ind, vector<int> &nums, vector<int> &dp) {
    if (ind == 0) return nums[0];
    if (ind < 0) return 0;
    if (dp[ind] != -1) return dp[ind];
    int take = nums[ind] + fun(ind-2, nums, dp);
    int notTake = 0 + fun(ind-1, nums, dp);
    return dp[ind] = max (take, notTake);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    
//     first method - memoization
//     int n = nums.size();
//     vector<int> dp(n, -1);
//     return fun(n-1, nums, dp);
    
//     second method - tabulation
//     int n = nums.size();
//     vector<int> dp(n);
//     dp[0] = nums[0];
//     for (int i = 1; i < n; i++) {
//         int take = nums[i];
//         if (i > 1) take += dp[i-2];
//         int notTake = 0 + dp[i-1];
//         dp[i] = max(take, notTake);
//     }
//     return dp[n-1];
    
//     third method - space optimized
       int n = nums.size();
        int left = 0, right = 0;
       for (int i = 0; i < n; i++) {
           int take = nums[i] + left;
           int dontTake = 0 + right;
           left = right;
           right = max(take, dontTake);
       }
       return right;
}
