// Last updated: 8/3/2026, 11:37:33 PM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target) return true;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            // left half is sorted
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && nums[mid] > target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }

            // right half is sorted
            else{
                if(nums[high] >= target && nums[mid] < target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }

        return false;
    }
};