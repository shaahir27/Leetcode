// Last updated: 8/3/2026, 11:37:47 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;

        int maxi = INT_MIN;

        for(int i=0; i<nums.size(); i++){

            sum += nums[i];

            maxi = max(sum, maxi);

            if(sum < 0){
                sum = 0;
                continue;
            }
                    
        }

        return maxi;
    }
};