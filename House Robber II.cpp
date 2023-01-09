Problem:
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Example 2:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 3:
Input: nums = [1,2,3]
Output: 3
 
Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000

Solution:

class Solution {
public:
    int fun(int ind, vector<int> &nums, int end, vector<int> &dp) {
        if(ind == end) return nums[end];
        if (dp[ind] != -1) return dp[ind];
        int take = nums[ind];
        if (ind-2 >= end) take += fun(ind-2, nums, end, dp);
        int dontTake = 0+fun(ind-1, nums, end, dp);
        return dp[ind] = max(take, dontTake);
    }
    int rob(vector<int>& nums) {
        // int n = nums.size(), first = nums[0], last = nums[0];

        // vector<int> dp1(n, -1);
        // if (n > 1) first = fun(n-1, nums, 1, dp1);

        // vector<int> dp2(n, -1);
        // if (n > 2) last = fun(n-2, nums, 0, dp2);

        // return max(first, last);
        int left = 0, right = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int take = nums[i] + left;
            int dontTake = 0 + right;
            left = right;
            right = max(take, dontTake);
        }
        int first = right;
        left = 0, right = nums[0];
        for (int i = 1; i < n-1; i++) {
            int take = nums[i] + left;
            int dontTake = 0 + right;
            left = right;
            right = max(take, dontTake);
        }
        int second = right;
        return  max(first, second);
    }
};
