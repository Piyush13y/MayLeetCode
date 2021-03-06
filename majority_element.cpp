/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

int x = [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0, ansYet = 0;
        for(auto itr : nums){
            if(count == 0){
                ansYet = itr;
            }
            if(itr == ansYet)
                count++;
            else
                count--;
        }
        return ansYet;
    }
};
