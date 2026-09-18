// Last updated: 9/18/2026, 9:55:00 PM
1class Solution {
2public:
3    int beautySum(string s) {
4        int sum = 0;
5
6        for(int i=0; i<s.length(); i++){
7            int frequency[26] = {0};
8
9            for(int j=i; j<s.length(); j++){
10                frequency[s[j] - 'a']++;
11
12                int maxElement = *max_element(frequency, frequency + 26);
13                int minElement = INT_MAX;
14
15                for(int k=0; k<26; k++){
16                    if(frequency[k] != 0){
17                        if(minElement > frequency[k]){
18                            minElement = frequency[k];
19                        }
20                    }
21                }
22
23                sum += maxElement - minElement;
24            }
25        }
26
27        return sum;
28    }
29};