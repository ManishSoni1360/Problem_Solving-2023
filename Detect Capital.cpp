Problem:
We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:

Input: word = "USA"
Output: true

Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.

Solution:

class Solution {
public:
    bool checkCondition(string word) {
        int len = word.length();
        for(int i = 1; i < len; i++) {
            if(int(word[i]) < 97) return false;
        }
        return true;
    }
    
    bool detectCapitalUse(string word) {
        if(int(word[0]) >= 97)  return checkCondition(word);
        
        if(word[1] >= 97) return checkCondition(word);
        
        if(word[1] < 97) {
            for(char i : word) {
                if(int(i) >= 97) return false;
            }
            return true;
        }
        return false;
    }
};
