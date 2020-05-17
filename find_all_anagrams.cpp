/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

int x =  [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    
    vector<int> findAnagrams(string s, string p) {
        
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
                ans.push_back(i - patSize);
            
            countW[s[i - patSize] - 'a']--;
            countW[s[i] - 'a']++;
            
        }
        
        if(compareCount(countP, countW))
            ans.push_back(winSize - patSize);
        return ans;
    }
    int compareCount(char a[], char b[]){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i])
                return 0;
        }
        return 1;
    }
};
