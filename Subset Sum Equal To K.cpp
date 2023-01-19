Problem:
You are given an array/list 'ARR' of 'N' positive integers and an integer 'K'. Your task is to check if there exists a subset in 'ARR' with a sum equal to 'K'.
Note: Return true if there exists a subset with sum equal to 'K'. Otherwise, return false.
For Example:
If ‘ARR' is {1,2,3,4} and 'K' = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.

Solution:

#include <bits/stdc++.h> 
bool fun(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;
    if (dp[ind][target] != -1) return dp[ind][target];
    int take = false;
    if (arr[ind] <= target) take = fun(ind-1, target-arr[ind], arr, dp);
    int notTake = fun(ind-1, target, arr, dp);
    return dp[ind][target] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
//     vector<vector<int>> dp(n, vector<int> (k+1, -1));
//     return fun(n-1, k, arr, dp);
    
    vector<vector<bool>> dp(n, vector<bool> (k+1, 0));
//     for (int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][0] = true;
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
        dp[i][0] = true;
        for (int target = 1; target <= k; target++) {
            int take = false;
            if (arr[i] <= target) take = dp[i-1][target - arr[i]];
            int notTake = dp[i-1][target];
            dp[i][target] = take || notTake;
        }
    }
    return dp[n-1][k];
}
