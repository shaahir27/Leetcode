// Last updated: 8/18/2026, 10:37:35 PM
1class Solution {
2public:
3    string longestCommonPrefix(vector<string>& strs) {
4        int n = strs.size();
5        string result = "";
6
7        sort(strs.begin(), strs.end());
8
9        int i = 0;
10
11        while(strs[0][i] && strs[n-1][i]){
12            if(strs[0][i] == strs[n-1][i]){
13                result += strs[0][i];
14                i++;
15                continue;
16            }
17            break;
18        }
19
20        return result;
21    }
22};