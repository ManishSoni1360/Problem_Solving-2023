Problem:
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
  
Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
     
Example 2:
Input: triangle = [[-10]]
Output: -10
 
Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

Solution:

class Solution {
public:
    int fun(int row, int col, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp) {
        if (row == n-1) return triangle[n-1][col];
        if (dp[row][col] != -1) return dp[row][col];
        int down = triangle[row][col] + fun(row+1, col, triangle, n, dp);
        int diag = triangle[row][col] + fun(row+1, col+1, triangle, n, dp);
        return dp[row][col] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return fun(0, 0, triangle, n, dp);

        // int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j <= i; j++) {
        //         if (i == 0 && j == 0) dp[0][0] = triangle[0][0];
        //         else {
        //             int down = 0, diag = 0;
        //             if (j < i) {
        //                 down = triangle[i][j] + dp[i-1][j]; 
        //             } else down = 1e9;
        //             if (j > 0) {
        //                 diag = triangle[i][j] + dp[i-1][j-1]; 
        //             } else diag = 1e9;
        //             dp[i][j] = min(down, diag);
        //         }
        //     }
        // }
        // int min_ans = INT_MAX;
        // for (int j = 0; j < n; j++) {
        //     min_ans = min(dp[n-1][j], min_ans);
        // }
        // return min_ans;

        int n = triangle.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j <= i; j++) {
                if (i == 0 && j == 0) temp[0] = triangle[0][0];
                else {
                    int down = 0, diag = 0;
                    if (j < i) {
                        down = triangle[i][j] + dp[j]; 
                    } else down = 1e9;
                    if (j > 0) {
                        diag = triangle[i][j] + dp[j-1]; 
                    } else diag = 1e9;
                    temp[j] = min(down, diag);
                }
            }
            dp = temp;
        }
        int min_ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            min_ans = min(dp[j], min_ans);
        }
        return min_ans;
    }
};
