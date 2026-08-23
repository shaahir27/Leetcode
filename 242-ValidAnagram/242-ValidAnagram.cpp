// Last updated: 8/23/2026, 11:05:52 PM
1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        if(s.length() != t.length()) return false;
5
6        int frequency[26] = {0};
7
8        for(int i=0; i<s.length(); i++){
9            frequency[s[i] - 'a']++;
10            frequency[t[i] - 'a']--;
11        }
12
13        for(int i=0; i<26; i++){
14            if(frequency[i] != 0) return false;
15        }
16
17        return true;
18
19        /*
20        sort(s.begin(), s.end());
21        sort(t.begin(), t.end());
22
23        if(s == t) return true;
24        else return false;
25        */
26    }
27};