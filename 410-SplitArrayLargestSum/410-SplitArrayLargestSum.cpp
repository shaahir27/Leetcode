// Last updated: 8/29/2026, 11:29:54 PM
1class Solution {
2private:
3    bool canSplit(int target, vector<int>& nums, int k){
4        int count = 1;
5        int sum = 0;
6
7        for(int i = 0; i < nums.size(); i++){
8
9            if(sum + nums[i] > target){
10                sum = nums[i];
11                count++;
12            }
13            else{
14                sum += nums[i];
15            }
16
17            if(count > k)
18                return false;
19        }
20
21        return true;
22    }
23
24public:
25    int splitArray(vector<int>& nums, int k) {
26
27        int low = *max_element(nums.begin(), nums.end());
28        int high = accumulate(nums.begin(), nums.end(), 0);
29
30        while(low <= high){
31
32            int mid = low + (high - low) / 2;
33
34            if(canSplit(mid, nums, k)){
35                high = mid - 1;
36            }
37            else{
38                low = mid + 1;
39            }
40        }
41
42        return low;
43    }
44};