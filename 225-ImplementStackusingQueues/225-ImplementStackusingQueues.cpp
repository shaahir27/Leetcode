// Last updated: 10/17/2026, 10:08:13 PM
1class MyStack {
2public:
3    MyStack() {
4    }
5
6    queue<int> q;
7    
8    void push(int x) {
9        int size = q.size();
10
11        if(size == 0){
12            q.push(x);
13            return;
14        }
15
16        q.push(x);
17
18        for(int i=0; i<size; i++){
19            q.push(q.front());
20            q.pop();
21        }
22    }
23    
24    int pop() {
25        int val = q.front();
26        q.pop();
27        return val;
28    }
29    
30    int top() {
31        return q.front();
32    }
33    
34    bool empty() {
35        return q.empty();
36    }
37};
38
39/**
40 * Your MyStack object will be instantiated and called as such:
41 * MyStack* obj = new MyStack();
42 * obj->push(x);
43 * int param_2 = obj->pop();
44 * int param_3 = obj->top();
45 * bool param_4 = obj->empty();
46 */