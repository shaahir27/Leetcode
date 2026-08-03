// Last updated: 8/3/2026, 11:36:32 PM
class Solution {
public:
    bool canWinNim(int n) {
        if(n%4 == 0){
            return false;
        }
        return true;
    }
};