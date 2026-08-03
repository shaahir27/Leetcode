// Last updated: 8/3/2026, 11:37:56 PM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        
        int low = 0;
        int high = n-1;

        int ans = n;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;

        /*
        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] < target){
                if(mid < n-1 && nums[mid+1] > target) return mid+1;
                if(mid == n-1 && nums[mid] < target) return mid+1;
                low = mid+1;
            }
            else if(nums[mid] > target){
                if(mid > 0 && nums[mid-1] < target) return mid;
                high = mid-1;
            }
            else{
                return mid;
            }
        }

        return 0;
        */
    }
};