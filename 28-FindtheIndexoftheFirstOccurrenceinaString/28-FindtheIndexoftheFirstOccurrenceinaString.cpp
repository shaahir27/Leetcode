// Last updated: 10/5/2026, 9:49:27 PM
1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        if(haystack.length() < needle.length()) return -1;
5        
6
7        for(int i=0; i<haystack.length(); i++){
8            if(haystack[i] == needle[0]){
9                int x = i+1;
10                int j = 1;
11                while(j<needle.length()){
12                    if(haystack[x] != needle[j]) break;
13                    x++;
14                    j++;
15                }
16
17                if(j == needle.length()) return (x - j);
18            }
19        }
20
21        return -1;
22    }
23};