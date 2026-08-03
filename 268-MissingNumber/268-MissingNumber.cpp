// Last updated: 8/3/2026, 11:36:36 PM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int actualSum = n*(n+1)/2;

        int sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        return actualSum - sum;
    }
};