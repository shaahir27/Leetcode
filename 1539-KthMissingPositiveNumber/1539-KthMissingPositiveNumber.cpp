// Last updated: 8/12/2026, 10:46:41 PM
1class Solution {
2public:
3    int findKthPositive(vector<int>& arr, int k) {
4        
5        for(int i=0; i<arr.size(); i++){
6            if(arr[i] <= k) k++;
7            else break;
8        }
9
10        return k;
11    }
12};