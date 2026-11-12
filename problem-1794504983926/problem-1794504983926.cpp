// Last updated: 11/12/2026, 11:06:23 PM
1class Solution {
2private:
3    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, vector<bool>& used, int n){
4        if(nums.size() == temp.size()){
5            ans.push_back(temp);
6            return;
7        }
8
9        for(int i=0; i<n; i++){
10            if(used[i]) continue;
11    
12            used[i] = true;
13
14            temp.push_back(nums[i]);
15            solve(nums, temp, ans, used, n);
16
17            temp.pop_back();
18            used[i] = false;
19        }
20    }
21public:
22    vector<vector<int>> permute(vector<int>& nums) {
23        int n = nums.size();
24
25        vector<vector<int>> ans;
26        vector<int> temp;
27        vector<bool> used(n, false);
28
29        solve(nums, temp, ans, used, n);
30
31        return ans;
32    }
33};