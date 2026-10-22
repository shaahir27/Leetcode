// Last updated: 10/22/2026, 11:19:37 PM
1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        stack<int> st;
5        int n = asteroids.size();
6
7        vector<int> result;
8
9        int i = 0;
10        for(int a: asteroids){
11            bool destroyed = false;
12
13            while(!st.empty() && st.top()>0 && a<0){
14                if(st.top() > -a){
15                    destroyed = true;
16                    break;
17                }
18                else if(st.top() == -a){
19                    st.pop();
20                    destroyed = true;
21                    break;
22                }
23                else{
24                    st.pop();
25                }
26            }
27
28            if(!destroyed) st.push(a);
29        }
30
31        while(!st.empty()){
32            result.insert(result.begin(), st.top());
33            st.pop();
34        }
35
36        return result;
37    }
38};