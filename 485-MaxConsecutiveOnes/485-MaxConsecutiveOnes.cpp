// Last updated: 8/3/2026, 11:22:11 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int prevCount = 0;
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                count += 1;
            }
            else{
                prevCount = max(prevCount, count);
                count = 0;
            }
        }

        return max(prevCount, count);
    }
};