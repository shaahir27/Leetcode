// Last updated: 10/12/2026, 2:34:49 PM
1class Solution {
2public:
3    int minBitFlips(int start, int goal) {
4        
5        int ans = start ^ goal;
6        int count = 0;
7
8        int i = 0;
9        for(int i=0; i<31; i++){
10            if(ans & (1<<i)) count++;
11        }
12
13        return count;
14    }
15};
16
17/*
18Normal and best approach
19
20int ans = start ^ goal;
21int count = 0;
22
23while(ans > 0){
24    if(ans%2 == 1) count++;
25    ans /= 2;
26}
27
28return count;
29
30*/