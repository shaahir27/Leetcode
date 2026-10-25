// Last updated: 10/25/2026, 3:29:34 PM
1class StockSpanner {
2public:
3    StockSpanner() {
4    }
5    stack<pair<int, int>> st;
6    
7    int next(int price) {
8        int span = 1;
9
10        while(!st.empty() && st.top().first <= price){
11            span += st.top().second;
12            st.pop();
13        }
14
15        st.push({price, span});
16        return span;
17    }
18};
19
20/**
21 * Your StockSpanner object will be instantiated and called as such:
22 * StockSpanner* obj = new StockSpanner();
23 * int param_1 = obj->next(price);
24 */