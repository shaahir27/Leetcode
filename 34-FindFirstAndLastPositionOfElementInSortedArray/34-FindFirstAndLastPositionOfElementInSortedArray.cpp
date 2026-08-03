// Last updated: 8/3/2026, 11:38:00 PM
class Solution {
private:
    int findFirst(vector<int>& nums, int target){
        int n = nums.size();
        int firstIndex = -1;

        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] >= target){
                firstIndex = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        if(firstIndex != -1 && nums[firstIndex] == target) return firstIndex;
        else return -1;
    }

    int findSecond(vector<int>& nums, int target){
        int n = nums.size();
        int nextElement = -1;

        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid] > target){
                nextElement = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        if(nextElement != -1 && nums[nextElement-1] == target) return nextElement-1;
        else if(nextElement == -1 && n>0 && nums[n-1] == target) return n-1;
        else return -1; 
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIndex = findFirst(nums, target);

        if(firstIndex == -1)
            return {-1, -1};

        int secondIndex = findSecond(nums, target);
        return {firstIndex, secondIndex};
    }
};