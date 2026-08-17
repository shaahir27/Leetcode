// Last updated: 8/17/2026, 11:32:45 PM
1class Solution {
2public:
3    string largestOddNumber(string num) {
4
5        int ans = -1;
6        for(int i=0; i<num.length(); i++){
7            if((num[i]-'0')%2!=0) ans = i;
8        }
9        return num.substr(0,ans+1);
10        
11        /*
12        
13        string result = "";
14        int n = num.length();
15
16        int i = n-1;
17
18        while(!num.empty() && (num[i]-'0')%2 == 0){
19            num.pop_back();
20            i--;
21        }
22
23        return num;
24
25        */
26    }
27};