// Last updated: 8/3/2026, 11:21:21 PM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector <int> ans(n);

        int pos_index = 0;
        int neg_index = 1;

        for(int i=0; i<n; i++){

            if(nums[i] > 0){
                ans[pos_index] = nums[i];
                pos_index += 2;
            }
            else{
                ans[neg_index] = nums[i];
                neg_index += 2;
            }
        }

        return ans;
    }
};