// Last updated: 11/16/2026, 9:56:53 PM
1class CustomStack {
2private:
3    vector<int> data;
4    int size;
5public:
6    CustomStack(int maxSize) {
7        size = maxSize;
8        data.reserve(size);
9    }
10    
11    void push(int x) {
12        if(data.size() == size) return;
13        data.push_back(x);
14    }
15    
16    int pop() {
17        int n = data.size();
18
19        if(n == 0) return -1;
20        int val = data.back();
21        data.pop_back();
22
23        return val;
24    }
25    
26    void increment(int k, int val) {
27        int n = min(k, (int)data.size());
28
29        for(int i=0; i<n; i++){
30            data[i] += val;
31        }
32    }
33};
34
35/**
36 * Your CustomStack object will be instantiated and called as such:
37 * CustomStack* obj = new CustomStack(maxSize);
38 * obj->push(x);
39 * int param_2 = obj->pop();
40 * obj->increment(k,val);
41 */