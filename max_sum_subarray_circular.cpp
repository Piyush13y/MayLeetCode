/*
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
*/
int x = [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int n = 0;
    int maxSubarraySumCircular(vector<int>& a) {
        // Case 1: get the maximum sum using standard kadane'  
    // s algorithm  
        n = a.size();
        int allNeg = 1, maxi = INT_MIN;
    for (int i = 0; i < n; i++)  
    {  
            //max_wrap += a[i]; // Calculate array-sum  
            //a[i] = -a[i]; // invert the array (change sign)  
        maxi = max(a[i], maxi);
        if(a[i] >= 0){
            allNeg = 0;
            break;
        }
    }  
        
        if(allNeg)
            return maxi;
    int max_kadane = kadane(a, n);  
      
    // Case 2: Now find the maximum sum that includes  
    // corner elements.  
    int max_wrap = 0, i;  
    for (i = 0; i < n; i++)  
    {  
            max_wrap += a[i]; // Calculate array-sum  
            a[i] = -a[i]; // invert the array (change sign)  
    }  
      
    // max sum with corner elements will be:  
    // array-sum - (-max subarray sum of inverted array)  
    max_wrap = max_wrap + kadane(a, n);  
      
    // The maximum circular sum will be maximum of two sums  
    return (max_wrap > max_kadane)? max_wrap: max_kadane;  
}  
  
// Standard Kadane's algorithm to find maximum subarray sum  
// See https://www.geeksforgeeks.org/archives/576 for details  
int kadane(vector<int> a, int n)  
{  
    int max_so_far = 0, max_ending_here = 0;  
    int i;  
    for (i = 0; i < n; i++)  
    {  
        max_ending_here = max_ending_here + a[i];  
        if (max_ending_here < 0)  
            max_ending_here = 0;  
        if (max_so_far < max_ending_here)  
            max_so_far = max_ending_here;  
    }  
    return max_so_far;  
}  

   // }
};
