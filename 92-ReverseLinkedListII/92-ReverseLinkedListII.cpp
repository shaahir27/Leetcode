// Last updated: 9/26/2026, 10:58:27 PM
1class Solution {
2public:
3    bool isMonotonic(vector<int>& nums) {
4        int n = nums.size();
5        if(n == 1) return true;
6
7        if(nums[0] <= nums[n-1]){
8            // condition i<=j
9            for(int i=1; i<n; i++){
10                if(nums[i] < nums[i-1]) break;
11                if(i == n-1) return true;
12            }
13        }
14        else{
15            //condition i>=j
16            for(int i=1; i<n; i++){
17                if(nums[i] > nums[i-1]) break;
18                if(i == n-1) return true;
19            }
20        }
21
22        return false;
23    }
24};