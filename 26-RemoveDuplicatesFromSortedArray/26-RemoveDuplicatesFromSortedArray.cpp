// Last updated: 8/3/2026, 11:38:11 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        for(int i = 1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};