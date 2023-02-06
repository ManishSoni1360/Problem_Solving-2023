Problem:
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
  
Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 
Constraints:
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
  
Solution:
class Solution {
public:
    bool checkEqual(vector<int> a, vector<int> b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26, 0), b(26, 0);
        for (char c1 : s1) a[c1 - 'a']++;
        
        int start = 0, end = 0;
        while (end < s2.length()) {
            b[s2[end] - 'a']++;
            
            if (end - start + 1 == s1.length()) {
                if (checkEqual(a, b)) return true;
            }
            
            if (end - start + 1 >= s1.length()) {
                b[s2[start] - 'a']--;
                start++;
            }
            end++;
        }
        return false;
    }
};
