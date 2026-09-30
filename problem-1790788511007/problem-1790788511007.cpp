// Last updated: 9/30/2026, 10:45:11 PM
1class Solution {
2public:
3    int jump(vector<int>& nums) {
4        int maxReach = 0;
5        int count = 0;
6        int end = 0;
7
8        int n = nums.size();
9        if(n == 1) return 0;
10
11        for(int i=0; i<n; i++){
12            maxReach = max(maxReach, i + nums[i]);
13
14            if(i == end){
15                count++;
16                end = maxReach;
17            }
18
19            if(end == n-1) return count;
20        }
21
22        return count;
23    }
24};