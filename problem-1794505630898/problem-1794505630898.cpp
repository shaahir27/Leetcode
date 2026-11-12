// Last updated: 11/12/2026, 11:17:10 PM
class Solution {
public:
    void backtrack(vector<int>& nums, int startIndex,
                   vector<vector<int>>& permutations) {
        if (startIndex == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        for (int i = startIndex; i < nums.size(); i++) {
            swap(nums[i], nums[startIndex]);
            backtrack(nums, startIndex + 1, permutations);
            swap(nums[i], nums[startIndex]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        backtrack(nums, 0, permutations);
        return permutations;
    }
};