// Last updated: 10/29/2026, 11:13:07 PM
1class Solution {
2public:
3    int lengthOfLastWord(string s) {
4        int n = s.length();
5        int length = 0;
6
7        for(int i=n-1; i>=0; i--){
8            if(i==n-1 && s[i] == ' '){
9                i--;
10                while(i>=0 && s[i] == ' '){
11                    i--;
12                }
13                length++;
14                continue;
15            }
16
17            if(s[i] == ' ') break;
18            length++;
19        }
20
21        return length;
22    }
23};