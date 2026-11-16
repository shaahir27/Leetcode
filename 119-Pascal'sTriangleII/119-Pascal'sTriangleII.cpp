// Last updated: 11/16/2026, 9:29:12 PM
1class Solution {
2public:
3    vector<int> getRow(int rowIndex) {
4        vector<int> result;
5        result.push_back(1);
6
7        long long ans = 1;
8
9        for(int i=1; i<=rowIndex; i++){
10            ans = ans * (rowIndex+1 - i)/i;
11            result.push_back(static_cast<int>(ans));
12        }
13
14        return result;
15    }
16};