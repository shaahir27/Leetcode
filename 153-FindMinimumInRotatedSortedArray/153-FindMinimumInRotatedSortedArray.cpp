// Last updated: 8/3/2026, 11:37:04 PM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int ans = INT_MAX;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;            
    }
};

/*
 while (low < high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] <= nums[high]) {
        high = mid;
    } else {
        low = mid + 1;
    }
}

return nums[low];
*/