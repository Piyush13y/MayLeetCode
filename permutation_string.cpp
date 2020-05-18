/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    bool checkInclusion(string p, string s) {
        if(p.size() == 0 || s.size() == 0 || p.size() > s.size())
            return {};
        int patSize = p.size();
        int winSize = s.size();
        vector<int> ans;
        char countP[26] = {0}, countW[26] = {0};
        for(int i = 0; i < patSize; i++){
            countP[p[i] - 'a']++;
            countW[s[i] - 'a']++;
        }
        int i = 0;
        for(i = patSize; i < winSize; i++){
            
            if(compareCount(countP, countW))
                return true;
            
            countW[s[i - patSize] - 'a']--;
            countW[s[i] - 'a']++;
            
        }
        
        if(compareCount(countP, countW))
            return true;
        return false;
    }
    int compareCount(char a[], char b[]){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i])
                return 0;
        }
        return 1;
    }
    
};
