// Last updated: 9/24/2026, 10:50:59 AM
1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        int carry = 1;
5
6        for(int i=digits.size()-1; i>=0; i--){
7            if(digits[i] < 9){
8                digits[i]++;
9                return digits;
10            }
11
12            digits[i] = 0;
13        }
14
15        if(carry > 0){
16            digits.insert(digits.begin(), 1);
17        }
18
19        return digits;
20    }
21};