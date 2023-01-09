Problem:
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
  
Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
  
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.
  
 Solution:

class Solution {
public:
    bool match = false;
    bool fun(string s, string t, int si, int ti) {
        if (si == s.size()) return true;
        if (ti >= t.size()) return false;
        if (s[si] == t[ti]) return fun(s, t, si+1, ti+1);
        else return fun(s, t, si, ti+1);
    }
    bool isSubsequence(string s, string t) {
        // int i = 0;
        // for(char ch : t) {
        //     if(s[i] == ch) i++;
        // }
        // if(i == s.length()) return true;
        // else return false;

        return fun(s, t, 0, 0);
    }
};
