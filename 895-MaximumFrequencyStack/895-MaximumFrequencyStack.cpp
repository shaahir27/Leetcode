// Last updated: 11/26/2026, 6:15:20 PM
1class FreqStack {
2private:
3    unordered_map<int, int> freq;
4    unordered_map<int, stack<int>> group;
5    int maxFreq = 0;
6
7public:
8    FreqStack() {}
9
10    void push(int val) {
11        freq[val]++;
12        int currentFreq = freq[val];
13
14        if (currentFreq > maxFreq) {
15            maxFreq = currentFreq;
16        }
17        
18        group[currentFreq].push(val);
19    }
20
21    int pop() {
22        int topVal = group[maxFreq].top();
23        group[maxFreq].pop();
24        freq[topVal]--;
25        if (group[maxFreq].empty()) {
26            maxFreq--;
27        }
28        return topVal;
29    }
30};