// Last updated: 9/23/2026, 10:58:15 PM
1class Solution {
2public:
3    vector<int> transformArray(vector<int>& nums) {
4        int n = nums.size();
5
6        for(int i=0; i<n; i++){
7            if(nums[i]%2 == 0){
8                nums[i] = 0;
9            }
10            else{
11                nums[i] = 1;
12            }
13        }
14        sort(nums.begin(), nums.end());
15        return nums;
16    }
17};