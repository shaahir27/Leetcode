// Last updated: 8/17/2026, 11:31:12 PM
1class Solution {
2public:
3    string largestOddNumber(string num) {
4        string result = "";
5        int n = num.length();
6
7        int i = n-1;
8
9        while(!num.empty() && (num[i]-'0')%2 == 0){
10            num.pop_back();
11            i--;
12        }
13
14        return num;
15    }
16};