/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

int x = [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    
    string frequencySort(string s) {
        int freq[256] = {0};
        for(auto itr : s){
            freq[itr]++;
        }
        
        vector<pair<int,char>> freq1;
        for(int i = 0; i < 256; i++){
            if(freq[i] != 0)
                freq1.push_back({freq[i], i});
        }
        
        sort(freq1.rbegin(), freq1.rend());//, sortVal);
        string ans;
        for(auto itr : freq1){
                ans = ans + string(itr.first, itr.second);
        }
        return ans;
    }
};
