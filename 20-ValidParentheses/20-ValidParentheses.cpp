// Last updated: 10/18/2026, 10:16:36 PM
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5
6        for(int i=0; i<s.length(); i++){
7            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
8                st.push(s[i]);
9            }
10            else{
11                if(st.empty()) return false;
12
13                if(s[i] == ')' && st.top() != '(') return false;
14                if(s[i] == '}' && st.top() != '{') return false;
15                if(s[i] == ']' && st.top() != '[') return false;
16
17                st.pop();
18            }
19        }
20
21        if(st.empty()) return true;
22        else return false;
23    }
24};