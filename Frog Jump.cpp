Problem:
A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.
Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
 

Constraints:

2 <= stones.length <= 2000
0 <= stones[i] <= 231 - 1
stones[0] == 0
stones is sorted in a strictly increasing order.
  
Solution:

class Solution {
public:
    unordered_map<int, bool>mpp;
    map<pair<int, int>, bool> dpp;

    bool fun(int pos, int unit, vector<int> &stones, int n) {
        if (mpp[pos] == false || pos > stones[n-1]) return false;
        if (pos == stones[n-1]) return true;
        if (dpp.find({pos, unit}) != dpp.end()) return dpp[{pos, unit}];
        bool jump;
        if (pos == 0) jump = fun(pos+1, 1, stones, n);
        else {
            if (unit - 1 > 0) jump = fun(pos+unit-1, unit-1, stones, n);
            if (jump) return true;

            jump = fun(pos+unit, unit, stones, n);
            if (jump) return true;

            jump = fun(pos+unit+1, unit+1, stones,n);
            if (jump) return true;
        }
        dpp[{pos, unit}] = jump;
        return jump;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(int i : stones) mpp[i] = true;
        return fun(0, 1, stones, n);

        // map<int, set<int>> mpp;
        // mpp[1].insert(1);
        // int len = stones.size();

        // for (int i = 1; i < len; i++) {
        //     int pos = stones[i];
        //     for (int unit : mpp[pos]) {
        //         mpp[pos + unit - 1].insert(unit-1);
        //         mpp[pos + unit].insert(unit);
        //         mpp[pos + unit + 1].insert(unit + 1);
        //     }
        // }
        // return mpp[stones[len-1]].size() != 0;
        // if (stones[1] - stones[0] > 1) return false;
    }
};
