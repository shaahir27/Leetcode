// Last updated: 8/3/2026, 11:38:28 PM
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int dup = x;
        long long int revn = 0;
        while(x>0)
        {
            auto ld = x%10;
            x = x/10;
            revn = (revn * 10) + ld;
        }
        if (revn == dup) return true;
        else return false;
    }
};