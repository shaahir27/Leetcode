// Last updated: 9/16/2026, 10:49:50 PM
1class Solution {
2private:
3    double calculatePow(double x, long long int n){
4        if(n == 0) return 1.0;
5        else if(n == 1) return x;
6
7        if(n%2 == 0){
8            return calculatePow(x*x, n/2);
9        }
10        else{
11            return x * calculatePow(x, n-1);
12        }
13    }
14public:
15    double myPow(double x, int n) {
16        if(n<0){
17            return 1.0 / calculatePow(x, -1LL * n);
18        }
19
20        return calculatePow(x, n);
21    }
22};