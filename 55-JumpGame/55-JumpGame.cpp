// Last updated: 9/29/2026, 10:43:19 PM
1class Solution {
2public:
3    bool canJump(vector<int>& nums) {
4        int maxReach = 0;
5        for(int i=0; i<nums.size(); i++){
6
7            if(i > maxReach) return false;
8
9            maxReach = max(maxReach, i + nums[i]);
10
11            if(nums.size() == -1) return true;
12        }
13
14        return true;
15    }
16};