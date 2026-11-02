// Last updated: 11/2/2026, 11:19:57 PM
1class MinStack {
2public:
3    MinStack() {}
4
5    stack<pair<int, int>>st;
6    
7    void push(int value) {
8        if(st.empty()){
9            st.push({value, value});
10            return;
11        }
12
13        int minVal = min(value, st.top().second);
14        st.push({value, minVal});
15        return;
16    }
17    
18    void pop() {
19       st.pop();
20    }
21    
22    int top() {
23        return st.top().first;
24    }
25    
26    int getMin() {
27       return st.top().second; 
28    }
29};
30
31/**
32 * Your MinStack object will be instantiated and called as such:
33 * MinStack* obj = new MinStack();
34 * obj->push(value);
35 * obj->pop();
36 * int param_3 = obj->top();
37 * int param_4 = obj->getMin();
38 */