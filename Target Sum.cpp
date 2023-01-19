Problem:
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1
 
Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000


Solution:
class Solution {
public:
    int fun(int ind, vector<int>& nums, int target, int sum, vector<vector<int>> &dp) {
        if (ind < 0) return sum == target;
        if (dp[ind][sum+1000] != -1) return dp[ind][sum+1000];
        int add = fun(ind-1, nums, target, sum + nums[ind], dp);
        int subs = fun(ind-1, nums, target, sum - nums[ind], dp);
        return dp[ind][sum+1000] = add + subs;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2005, -1));
        return fun(n-1, nums, target, 0, dp);
    }
};
