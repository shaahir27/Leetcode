// Last updated: 10/7/2026, 12:03:39 AM
1class Solution {
2public:
3    int minAddToMakeValid(string s) {
4        int open = 0;
5        int count = 0;
6
7        for(int i=0; i<s.length(); i++){
8            if(s[i] == '('){
9                open++;
10                count++;
11            }
12            else{
13                if(open > 0){
14                    open--;
15                    count--;
16                }
17                else{
18                    count++;
19                }
20            }
21        }
22
23        return count;
24    }
25};