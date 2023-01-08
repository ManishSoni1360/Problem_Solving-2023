Problem: 
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 
Constraints:
1. 1 <= pattern.length <= 300
2. pattern contains only lower-case English letters.
3. 1 <= s.length <= 3000
4. s contains only lowercase English letters and spaces ' '.
5. s does not contain any leading or trailing spaces.
6. All the words in s are separated by a single space.


Solution:

class Solution {
public:
    bool wordPattern(string pattern, string s)  {  
        unordered_map<char, string> mpp;
        unordered_set<string> store;

        int t = 0, len = s.length();
        for (char c : pattern) {
            if (t >= len) return false;
            string temp = "";
            while (s[t] != ' ' && t < len) temp += s[t++];

            if (store.find(temp) != store.end()) {
                if (mpp.find(c) != mpp.end() && mpp[c] != temp) return false;
            }
            else {
                if (mpp.find(c) != mpp.end() && mpp[c] != temp) return false;
                mpp[c] = temp;
                store.insert(temp);
            } t++;
        }
        return true;
    }
};
