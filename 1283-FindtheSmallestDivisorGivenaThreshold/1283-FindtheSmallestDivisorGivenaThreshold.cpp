// Last updated: 8/10/2026, 10:49:48 PM
class Solution {
public:
    bool sum(vector<int>& nums, int threshold, int x) {
        int sum_s = 0;
        for (int &it : nums) {
            sum_s += (it + x - 1) / x;
        }
        if (sum_s <= threshold) {
            return true;
        }

        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sum(nums, threshold, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};