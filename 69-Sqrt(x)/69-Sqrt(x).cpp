// Last updated: 11/23/2026, 10:51:26 PM
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = 0;

        while(low <= high){
            long long mid = low + (high - low)/2;
            long long sq = mid*mid;
            if(sq == x){
                return mid;
            }
            else if(sq < x){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }  
};