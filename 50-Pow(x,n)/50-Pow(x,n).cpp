// Last updated: 9/16/2026, 10:58:45 PM
1class Solution{
2public:
3    double myPow(double x, int n){
4        if(n == 0) return 1.0;
5        else if(n == 1) return x;
6
7        long long int num = n;
8        
9        if(n<0){
10            num = -num;
11        }
12
13        double ans = 1.0;
14
15        while(num>=0){
16            if(num == 0) break;
17
18            //Even
19            if(num%2 == 0){
20                x = x*x;
21                num = num/2;
22            }
23
24            //Odd
25            else{
26                ans = ans * x;
27                num = num-1;
28            }
29        }
30
31        if(n<0) return 1/ans;
32        return ans;
33    }
34};
35
36
37/*
38
39Recursion Based solution, above is a Normal while loop solution
40
41class Solution {
42private:
43    double calculatePow(double x, long long int n){
44        if(n == 0) return 1.0;
45        else if(n == 1) return x;
46
47        if(n%2 == 0){
48            return calculatePow(x*x, n/2);
49        }
50        else{
51            return x * calculatePow(x, n-1);
52        }
53    }
54
55public:
56    double myPow(double x, int n) {
57        if(n<0){
58            return 1.0 / calculatePow(x, -1LL * n);
59        }
60
61        return calculatePow(x, n);
62    }
63};
64
65*/