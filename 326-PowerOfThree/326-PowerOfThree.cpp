// Last updated: 8/3/2026, 11:36:31 PM
class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n<=0) return false;
        
        while(n%3 == 0 && n>0)
        {
            n /= 3;
        }
        if ( n == 1) return true;
        else return false;
    }
};