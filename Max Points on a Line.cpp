Problem:

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Example 1:

Input: points = [[1,1],[2,2],[3,3]]
Output: 3
  
Example 2:

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        int ans = 1;
        for (int i = 0; i < len-1; i++) {
            map<double, int> mpp;
            for (int j = i+1; j < len; j++) {
                if (points[j][1] == points[i][1]) mpp[-90]++;
                else {
                    double slope = (double) (points[j][0] - points[i][0]) / (double) (points[j][1] - points[i][1]);
                    mpp[slope]++;
                }
            }
            int temp = 0;
            for (auto i : mpp) {
                temp = max(temp, i.second+1);
            }
            ans = max(ans, temp);
        }
        return ans;
};
