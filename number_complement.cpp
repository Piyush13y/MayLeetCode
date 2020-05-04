/*Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 

Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Note:

The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

*/

int x = [](){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int findComplement(int num) {
        vector<int> A;
        
        while(num > 0){
            A.push_back(num % 2);
            num /= 2;
        }
        int l = A.size();
        for(int i = 0; i < l; i++){
            A[i] = (A[i] == 0) ? 1 : 0;
        }
        int sum = 0, j = 0;
        while(j < l){
            sum += A[j] * pow(2,j);
            j++;
        }
        return sum;
    }
    
};

//runtime = 0ms; mem: 6.5mb
