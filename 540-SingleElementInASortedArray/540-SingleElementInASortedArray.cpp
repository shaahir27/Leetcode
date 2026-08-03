// Last updated: 8/3/2026, 11:22:02 PM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(mid%2 == 0){
                if(mid < n-1 && nums[mid] == nums[mid+1]) low = mid + 1;
                else high = mid - 1;
            }
            else{
                if(mid > 0 && nums[mid] == nums[mid-1]) low = mid + 1;
                else high = mid -1; 
            }
        }

        return nums[low];
    }
};