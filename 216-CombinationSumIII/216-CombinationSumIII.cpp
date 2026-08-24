// Last updated: 8/24/2026, 10:26:42 PM
1class Solution {
2private:
3    void findCombination(vector<int>& candidates, int target, vector<vector<int>>& Combinations, int starting, int n, vector<int>& result){
4
5        if(target == 0){
6            Combinations.push_back(result);
7            return;
8        }
9
10        if(starting == n){
11            if(target == 0){
12                Combinations.push_back(result);
13            }
14            return;
15        }
16
17        if(candidates[starting] <= target){
18            result.push_back(candidates[starting]);
19            findCombination(candidates, target - candidates[starting], Combinations, starting, n, result);
20            result.pop_back();
21        }
22
23        findCombination(candidates, target, Combinations, starting + 1, n, result);
24    }
25
26public:
27    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
28        vector<vector<int>> Combinations;
29        vector<int> result;
30
31        int n = candidates.size();
32        
33        findCombination(candidates, target, Combinations, 0, n, result);
34
35        return Combinations;
36    }
37};