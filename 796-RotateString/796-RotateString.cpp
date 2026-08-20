// Last updated: 8/20/2026, 11:00:35 PM
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4
5        if(s.length() != goal.length()) return false;
6        
7        string result = goal + goal;
8
9        if(result.find(s) != string::npos) return true;
10        else return false;
11
12        /*
13        int n = s.length();
14        int m = goal.length();
15
16        if(n != m) return false;
17
18        int start = -1;
19
20        for(int i=0; i<m; i++){
21            if(s[n-1] == goal[i]){
22                start = i;
23                break;
24            }
25        }
26
27        if(start == -1) return false;
28
29        for(int i = n-1; i<n*2-2; i++){
30            if(s[i % n] == goal[start % m]){
31                start++;
32                continue;
33            }
34            
35            return false;
36        }
37
38        return true;
39
40        */
41    }
42};