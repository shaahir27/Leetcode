// Last updated: 8/3/2026, 11:22:14 PM
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        while(n%4 == 0 && n>0)
        {
            n /= 4;
        }
        if ( n ==1 ) return  true;
        else return false;
    }
};