// Last updated: 8/3/2026, 11:36:46 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {

        for (int i = 0; i<31; i++)
        {
            int ans = pow(2, i);
            if ( ans == n ) return true;
        }
        return false;
    }
};