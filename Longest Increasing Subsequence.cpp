Problem:
Given an integer array nums, return the length of the longest strictly increasing subsequence

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
  
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
  
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 
Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
  
Solution:

class Solution {
public:
    int fun(int ind, int prev, vector<int> &nums, int n, vector<vector<int>> &dp) {
        int len1 = 0, len2 = 0;
        if (ind >= n) return 0;
        if (dp[ind][prev+1] != -1) return dp[ind][prev+1];
        len2 = 0+fun(ind+1, prev, nums, n, dp);
        if (prev == -1 || nums[ind] > nums[prev]) len1 = 1+fun(ind+1, ind, nums, n, dp);
        return dp[ind][prev+1] = max(len1, len2);
    }
    int lengthOfLIS(vector<int>& nums) {
        // int len = nums.size();
        // if(len == 1) return 1; 
        // vector<int> dp(len, 1);
        // int ans = INT_MIN;
        // for(int i = 1; i < len; i++) {
        //     for(int j = 0; j < i; j++) {
        //         if(nums[i] > nums[j] && dp[i] <= dp[j]) {
        //             dp[i] = dp[j] + 1;
        //         }
        //     }
        //     ans = max(ans, dp[i]);
        // }
        // return ans;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return fun(0, -1, nums, n, dp);
    }
};
