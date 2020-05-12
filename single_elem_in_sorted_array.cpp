/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/

int x = [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, n = nums.size();
        if(n == 1)
            return nums[0];
        if(nums[0] != nums[1])
            return nums[0];
        if(nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                return nums[mid];
            
            if(mid % 2 == 0){
                if(nums[mid] != nums[mid + 1])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else{
                if(nums[mid] != nums[mid - 1])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return 0;
    }
};
