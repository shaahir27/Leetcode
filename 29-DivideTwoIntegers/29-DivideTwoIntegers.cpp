// Last updated: 10/16/2026, 10:26:39 PM
1class Solution {
2public:
3    int divide(int dividend, int divisor) {
4        if(dividend == divisor) return 1;
5
6        bool sign = true;
7        if(
8            (dividend < 0 && divisor >= 0)
9            ||
10            (dividend >= 0 && divisor < 0)
11        ) sign = false;
12
13        long n = abs((long)dividend);
14        long d = abs((long)divisor);
15
16        long ans = 0;
17
18        while(n >= d){
19            int count = 0;
20            while(
21                n >= (d << ( count + 1 ) )
22            ) count++;
23
24            ans += (1 << count);
25            n -= d << count;
26
27        }
28
29        if(ans == (1 << 31) && sign){
30            return INT_MAX;
31        }
32        if(ans == (1 << 31) && !sign){
33            return INT_MIN;
34        }
35
36        return sign ? ans : -ans;
37    }
38};