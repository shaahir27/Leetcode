// Last updated: 10/30/2026, 11:02:08 PM
1class Solution {
2public:
3    int climbStairs(int n) {
4        if (n <= 1) return 1;
5        
6        int prev2 = 1;
7        int prev1 = 2;
8        
9        for (int i = 3; i <= n; i++) {
10            int current = prev1 + prev2;
11            
12            prev2 = prev1;
13            prev1 = current;
14        }
15        
16        return prev1; 
17    }
18};
19
20/*
21here we use an array inorder to reduce the recursion again for the same numbers
22
23for example... the valuse of getValue(20) may havve calculated before but calculating it again increases time complexity so we get time exceed limit error
24
25#include <vector>
26
27class Solution {
28private:
29    int getValue(int n, std::vector<int>& memo) {
30        if (n <= 1) return 1;
31        
32        if (memo[n] != -1) return memo[n];
33
34        memo[n] = getValue(n - 1, memo) + getValue(n - 2, memo);
35        return memo[n];
36    }
37    
38public:
39    int climbStairs(int n) {
40
41        std::vector<int> memo(n + 1, -1);
42        return getValue(n, memo);
43    }
44};
45
46*/