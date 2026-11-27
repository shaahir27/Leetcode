// Last updated: 11/27/2026, 12:01:11 PM
1class MyCircularQueue {
2private:
3    vector<int> queue;
4
5    int front = 0;
6    int capacity = 0;
7    int size = 0;
8public:
9    MyCircularQueue(int k) {
10        capacity = k;
11        queue.resize(k);
12    }
13    
14    bool enQueue(int value) {
15        if(isFull()) return false;
16
17        int rearIdx = (front + size) % capacity;
18        queue[rearIdx] = value;
19        size++;
20        
21        return true;
22    }
23    
24    bool deQueue() {
25        if(isEmpty()) return false;
26        
27        front = (front + 1) % capacity;
28        size--;
29        return true;
30    }
31    
32    int Front() {
33        if(isEmpty()) return -1;
34        else return queue[front];
35    }
36    
37    int Rear() {
38        if(isEmpty()) return -1;
39        
40        int rearIdx = (front + size - 1) % capacity;
41        return queue[rearIdx];
42    }
43    
44    bool isEmpty() {
45        if(size == 0) return true;
46        else return false;
47    }
48    
49    bool isFull() {
50        if(size == capacity) return true;
51        else return false;
52    }
53};
54
55/**
56 * Your MyCircularQueue object will be instantiated and called as such:
57 * MyCircularQueue* obj = new MyCircularQueue(k);
58 * bool param_1 = obj->enQueue(value);
59 * bool param_2 = obj->deQueue();
60 * int param_3 = obj->Front();
61 * int param_4 = obj->Rear();
62 * bool param_5 = obj->isEmpty();
63 * bool param_6 = obj->isFull();
64 */