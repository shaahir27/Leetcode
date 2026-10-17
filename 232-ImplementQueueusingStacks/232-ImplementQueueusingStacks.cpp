// Last updated: 10/17/2026, 10:42:09 PM
1class MyQueue {
2public:
3    MyQueue() {
4        
5    }
6
7    stack<int> st_main;
8    stack<int> st_alt;
9    
10    void push(int x) {
11        if(st_main.empty()){
12            st_main.push(x);
13            return;
14        }
15
16        while(!st_main.empty()){
17            st_alt.push(st_main.top());
18            st_main.pop();
19        }
20
21        st_main.push(x);
22
23        while(!st_alt.empty()){
24            st_main.push(st_alt.top());
25            st_alt.pop();
26        }
27    }
28    
29    int pop() {
30        int val = st_main.top();
31        st_main.pop();
32        return val;
33    }
34    
35    int peek() {
36        return st_main.top();
37    }
38    
39    bool empty() {
40        return st_main.empty();
41    }
42};
43
44/**
45 * Your MyQueue object will be instantiated and called as such:
46 * MyQueue* obj = new MyQueue();
47 * obj->push(x);
48 * int param_2 = obj->pop();
49 * int param_3 = obj->peek();
50 * bool param_4 = obj->empty();
51 */