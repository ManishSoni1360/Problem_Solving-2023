Problem:

Ninja is planing this 'N' days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can't do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 'POINTS' with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
For Example
If the given 'POINTS' array is [[1,2,5], [3,1,1],[3,3,3] ], the answer will be 11 as 5 +
3 + 3.


Solution:

int fun(int day, int prevInd, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            int curSum;
            if (i != prevInd) {
                curSum = points[day][i];
                maxi = max(maxi, curSum);
            }
        }
        return maxi;
    }
    int maxi = 0;
    if (dp[day][prevInd] != -1) return dp[day][prevInd];
    for (int i = 0; i < 3; i++) {
        int curSum;
        if (i != prevInd) {
            curSum = points[day][i] + fun(day-1, i, points, dp);
            maxi = max(maxi, curSum);
        }
    }
    return dp[day][prevInd] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return fun(n-1, 3, points, dp);
}
