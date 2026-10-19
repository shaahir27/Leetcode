// Last updated: 10/19/2026, 11:59:21 PM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        vector<int> result;
5        unordered_map<int, int> mpp;
6        int n = nums2.size();
7
8        stack<int> st;
9
10        for(int i=n-1; i>=0; i--){
11            if(st.empty()){
12                mpp[nums2[i]] = -1;
13                st.push(nums2[i]);
14                continue;
15            }
16
17            while(!st.empty() && nums2[i]>st.top()){
18                st.pop();
19            }
20
21            if(st.empty()){
22                mpp[nums2[i]] = -1;
23            }
24            else{
25                mpp[nums2[i]] = st.top();
26            }
27
28            st.push(nums2[i]);
29        }
30
31        for(int num: nums1){
32            result.push_back(mpp[num]);
33        }
34
35        return result;
36    }    
37};