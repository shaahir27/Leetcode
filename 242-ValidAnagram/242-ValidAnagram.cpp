// Last updated: 8/20/2026, 11:04:30 PM
1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        sort(s.begin(), s.end());
5        sort(t.begin(), t.end());
6
7        if(s == t) return true;
8        else return false;
9    }
10};