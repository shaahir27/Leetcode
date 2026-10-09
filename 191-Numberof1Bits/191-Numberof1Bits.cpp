// Last updated: 10/9/2026, 11:26:44 PM
1class Solution {
2public:
3    // Bit Manipulation Technique
4    
5    int hammingWeight(int n){
6        int count = 0;
7
8        int i = 0;
9        while(n != 0){
10            if(n & 1) count++;
11            i++;
12
13            n>>= 1;
14        }
15
16        return count;
17    }
18};
19/*
20
21public:
22    int hammingWeight(int n) {    
23        int x = n;
24        int count = 0;
25
26        while(x > 0){
27            if(x%2 == 1){
28                count++;
29            }
30
31            x /= 2;
32        }
33
34        return count;
35    }
36};
37
38*/