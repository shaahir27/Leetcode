// Last updated: 8/3/2026, 11:38:10 PM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};