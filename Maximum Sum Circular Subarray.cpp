Problem:
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:
Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:
Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104

Solution:

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // int n = nums.size(), maxAns = INT_MIN;
        // for (int i = 0; i < n; i++) {
        //     int curSum = nums[i];
        //     maxAns = max(maxAns, curSum);
        //     int j = i+1;
        //     while ((j % n) != i) {
        //         j %= n;
        //         curSum += nums[j++];
        //         maxAns = max(maxAns, curSum);
        //     }
        // }
        // return maxAns;

        int arrSum = 0, maxSum = INT_MIN, minSum = INT_MAX, curMaxSum = 0, curMinSum = 0;
        for (int i : nums) {
            curMaxSum += i;
            maxSum = max(maxSum, curMaxSum);
            if (curMaxSum < 0) curMaxSum = 0;
            curMinSum += i;
            minSum = min(minSum, curMinSum);
            if (curMinSum > 0) curMinSum = 0;
            arrSum += i;
        }
        if (arrSum == minSum) return maxSum;
        return max(maxSum, arrSum - minSum);
    }
};
