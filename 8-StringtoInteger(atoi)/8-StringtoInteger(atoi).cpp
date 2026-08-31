// Last updated: 8/31/2026, 10:50:18 PM
1class Solution {
2public:
3    int myAtoi(string s) {
4        long long result = 0;
5        int sign = 1;
6        bool started = false;
7
8        for(int i=0; i<s.length(); i++){
9            if(s[i] == ' '){
10                if(started) break;
11                continue;
12            }
13            else if(s[i] == '+'){
14                if(started) break;
15                started = true;
16                continue;
17            }
18            else if(s[i] == '-'){
19                if(started) break;
20                sign = -1;
21                started = true;
22            }
23            else if(isdigit(s[i])){
24                int digit = s[i] - '0';
25
26                if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)){
27                    return sign == 1 ? INT_MAX : INT_MIN;
28                }
29
30                result = result * 10 + digit;
31                started = true;
32            }
33            else{
34                break;
35            }
36        }
37
38        return result * sign;
39    }
40};