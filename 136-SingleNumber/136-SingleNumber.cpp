// Last updated: 8/3/2026, 11:37:19 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            ans = ans^nums[i];
        }

        return ans;
    }
};