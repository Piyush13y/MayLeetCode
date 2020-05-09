/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/

class Solution {
public:
    bool isPerfectSquare(uint num) {
        if (num == 1)
            return true;
        int mod = num % 10;
        if(mod == 3 || mod == 7)
            return false;
        for(uint i = 0; i <= num / 2; i++){
            long sq = i * i;
            if(sq > INT_MAX)
                return false;
            if(sq == num)
                return true;
        }
        
        return false;
    }
};
