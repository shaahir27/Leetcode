// Last updated: 11/3/2026, 11:06:14 PM
1class Solution {
2public:
3    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
4        int n = pushed.size();
5        int current = 0;
6        stack<int> st;
7
8        for(int i=0; i<n; i++){
9            if(pushed[i] == popped[current]){
10                current++;
11
12                while(current < n){
13                    if(st.empty() || st.top() != popped[current]) break;
14                    st.pop();
15                    current++;
16                }
17
18                continue;
19            }
20
21            st.push(pushed[i]);
22        }
23
24        if(current != n) return false;
25        else return true;
26    }
27};