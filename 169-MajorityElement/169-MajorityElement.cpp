// Last updated: 8/3/2026, 11:36:58 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;
        int el;

        for(int i=0; i<n; i++){
            if(count == 0){
                el = nums[i];
                count = 1;
            }

            else if(nums[i] == el){
                count++;
            }

            else{
                count--;
            }
        }

        count = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == el){
                count++;
            }
        }

        if(count > n/2){
            return el;
        }

        return -1;
    }
};