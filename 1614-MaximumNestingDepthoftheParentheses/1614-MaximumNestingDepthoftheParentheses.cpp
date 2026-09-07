// Last updated: 9/7/2026, 11:11:46 PM
1class Solution {
2public:
3    int maxDepth(string s) {
4        
5        int count = 0;
6        int maxCount = INT_MIN;
7
8        for(int i=0; i<s.length(); i++){
9            if(s[i] == '('){
10                count ++;
11            }
12            else if(s[i] == ')'){
13                count--;
14            }
15            else{
16                continue;
17            }
18
19            maxCount = max(maxCount, count);
20        }
21
22        if(maxCount == INT_MIN) maxCount = 0;
23        
24        return maxCount;
25    }
26};