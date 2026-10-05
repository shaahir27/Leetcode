// Last updated: 10/5/2026, 9:53:24 PM
1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        if(haystack.length() < needle.length()) return -1;
5
6        int n = haystack.length();
7        int m = needle.length();
8        
9
10        for(int i=0; i<(n-m+1); i++){
11            int j = 0;
12            while(j<m && haystack[i+j] == needle[j]){
13                j++;
14            }
15
16            if(j == m) return i;
17        }
18
19        return -1;
20    }
21};