// Last updated: 11/13/2026, 9:40:54 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        int n = s.length();
5        if(n==0) return 0;
6        int freq[256] = {0};
7        int maxi = INT_MIN;
8
9        for(int i=0; i<n; i++){
10            freq[s[i]]++;
11            int count = 1;
12
13            int j = i+1;
14            while(j<n && freq[s[j]] == 0){
15                freq[s[j]]++;
16                count++;
17                j++;
18            }
19
20            maxi = max(maxi, count);
21
22            fill(freq, freq+256, 0);
23        }
24
25        return maxi;
26    }
27};