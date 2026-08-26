// Last updated: 8/26/2026, 11:29:40 PM
1class Solution {
2private:
3    void findCombinations(vector<int>& candidates, int target, vector<vector<int>>& Combinations, vector<int>& result, int starting, int n){
4
5        if(target == 0){
6            Combinations.push_back(result);
7            return;
8        }
9
10        if(starting == n){
11            return;
12        }
13
14        if(candidates[starting] <= target){
15            result.push_back(candidates[starting]);
16            findCombinations(candidates, target - candidates[starting], Combinations, result, starting + 1, n);
17            
18            result.pop_back();
19        }
20
21        int next = starting + 1;
22
23        while(next < n && candidates[next] == candidates[starting]){
24            next++;
25        }
26
27        findCombinations(candidates, target, Combinations, result, next, n);
28    }
29
30public:
31    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
32        vector<vector<int>> Combinations;
33        vector<int> result;
34
35        sort(candidates.begin(), candidates.end());
36
37        int n = candidates.size();
38
39        findCombinations(candidates, target, Combinations, result, 0, n);
40
41        sort(Combinations.begin(), Combinations.end());
42
43        Combinations.erase(
44            unique(Combinations.begin(), Combinations.end()),
45            Combinations.end()
46        );
47
48        return Combinations;
49    }
50};