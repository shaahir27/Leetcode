// Last updated: 8/3/2026, 11:38:37 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int>mpp;

        for(int i=0; i<nums.size(); i++){
            int rem = target - nums[i];

            if(mpp.find(rem) != mpp.end()){

                return {mpp[rem], i};
            }

            mpp[nums[i]] = i;
        }

        return {};
    }
};