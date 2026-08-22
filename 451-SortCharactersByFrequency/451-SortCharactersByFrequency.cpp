// Last updated: 8/22/2026, 11:00:51 PM
1class Solution {
2public:
3    string frequencySort(string s) {
4        int frequency[256] = {0};
5
6        for(int i=0; i<s.length(); i++){
7            frequency[s[i]]++;
8        }
9
10        vector<pair<int, char>> vec;
11        for (int i = 0; i < 256; i++) {
12            if (frequency[i] > 0) {
13                vec.push_back({frequency[i], (char)i});
14            }
15        }
16
17        sort(vec.rbegin(), vec.rend());
18
19        string result = "";
20        for(auto& it : vec){
21            result.append(it.first, it.second);
22        }
23
24        return result;
25    }
26};