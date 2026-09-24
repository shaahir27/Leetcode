// Last updated: 9/24/2026, 10:48:49 AM
1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        int carry = 1;
5
6        for(int i=digits.size()-1; i>=0; i--){
7            int sum = digits[i] + carry;
8            carry = sum/10;
9
10            if(carry > 0){
11                digits[i] = sum%10;
12            }
13            else{
14                digits[i] = sum;
15            }
16        }
17
18        if(carry > 0){
19            digits.insert(digits.begin(), 1);
20        }
21
22        return digits;
23    }
24};