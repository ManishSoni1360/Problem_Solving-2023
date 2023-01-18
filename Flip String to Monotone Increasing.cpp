Problem:
A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
Return the minimum number of flips to make s monotone increasing.

Example 1:
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.

Example 2:
Input: s = "010110"
Output: 2
Explanation: We flip to get 011111, or alternatively 000111.

Example 3:
Input: s = "00011000"
Output: 2
Explanation: We flip to get 00000000.
 
Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.


Solution:

class Solution {
public:
    int minFlipsMonoIncr(string s) {
    //    int zeroes = count(s.begin(), s.end(), '0');
    //    int ans = zeroes;
    //    for (char c : s) {
    //        if (c == '0') {
    //            --zeroes;
    //            ans = min(ans, zeroes);
    //        } else ++zeroes;
    //    }
    //    return ans;

        int n = s.length();
        vector<int> dp(n);
        dp[0] = 0;
        int ones = s[0] == '1';
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                dp[i] = dp[i-1];
                ++ones;
            }
            else dp[i] = min(ones, dp[i-1]+1);
        }   
        return dp[n-1];
    }
};
