Problem:
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 
Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

Solution:

class Solution {
public:
    int fun(int row, int col, vector<vector<int>>& matrix, int n, vector<vector<int>> &dp) {
        if (col < 0 || col >= n) return 1e9;
        if (row == n-1) return matrix[n-1][col];
        if (dp[row][col] != -1) return dp[row][col];
        int down = matrix[row][col] + fun(row+1, col, matrix, n, dp);
        int leftDiag = matrix[row][col] + fun(row+1, col-1, matrix, n, dp);
        int rightDiag = matrix[row][col] + fun(row+1, col+1, matrix, n, dp);
        return dp[row][col] = min(down, min(leftDiag, rightDiag));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // int min_ans = INT_MAX;
        // for (int j = 0; j < n; j++) {
        //     vector<vector<int>> dp(n, vector<int>(n, -1));
        //     min_ans = min(min_ans, fun(0, j, matrix, n, dp));
        // }
        // return min_ans;

        // int n = matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0) dp[0][j] = matrix[0][j];
        //         else {
        //             int down = 0, leftDiag = 0, rightDiag = 0;
        //             down = matrix[i][j] + dp[i-1][j];
        //             if (j+1 < n) leftDiag = matrix[i][j] + dp[i-1][j+1];
        //             else leftDiag = 1e9;
        //             if (j > 0) rightDiag = matrix[i][j] + dp[i-1][j-1];
        //             else rightDiag = 1e9;
        //             dp[i][j] = min(down, min(leftDiag, rightDiag));
        //         }
        //     }
        // }
        // int min_ans = INT_MAX;
        // for (int j = 0; j < n; j++) {
        //     min_ans = min(min_ans, dp[n-1][j]);
        // }
        // return min_ans;

        int n = matrix.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0) temp[j] = matrix[0][j];
                else {
                    int down = 0, leftDiag = 0, rightDiag = 0;
                    down = matrix[i][j] + dp[j];
                    if (j+1 < n) leftDiag = matrix[i][j] + dp[j+1];
                    else leftDiag = 1e9;
                    if (j > 0) rightDiag = matrix[i][j] + dp[j-1];
                    else rightDiag = 1e9;
                    temp[j] = min(down, min(leftDiag, rightDiag));
                }
            }
            dp = temp;
        }
        int min_ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            min_ans = min(min_ans, dp[j]);
        }
        return min_ans;
    }
};
