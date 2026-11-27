// Last updated: 11/27/2026, 1:10:18 PM
1class MyCircularDeque {
2private:
3    vector<int> dq;
4
5    int front;
6    int rear;
7    int size;
8    int capacity;
9public:
10    MyCircularDeque(int k) {
11        dq.resize(k);
12
13        capacity = k;
14        size = 0;
15        rear = -1;
16        front = -1;
17    }
18    
19    bool insertFront(int value) {
20        if(isFull()) return false;
21
22        if(front == -1) {
23            front = rear = 0;
24        }
25        else if(front == 0) {
26            front = capacity - 1;
27        }
28        else {
29            front--;
30        }
31        
32        dq[front] = value;
33        size++;
34
35        return true;
36    }
37    
38    bool insertLast(int value) {
39        if(isFull()) return false;
40
41        if(front == -1) {
42            rear = front = 0;
43        }
44        else if(rear == capacity-1) {
45            rear = 0;
46        }
47        else {
48            rear = (rear + 1) % capacity;
49        }
50
51        dq[rear] = value;
52        size++;
53
54        return true;
55    }
56    
57    bool deleteFront() {
58        if (isEmpty()) return false;
59        if (size == 1) {
60            front = rear = -1;
61        } else {
62            front = (front + 1) % capacity;
63        }
64        size--;
65        return true;
66    }
67
68    bool deleteLast() {
69        if (isEmpty()) return false;
70        if (size == 1) {
71            front = rear = -1;
72        } else {
73            rear = (rear - 1 + capacity) % capacity;
74        }
75        size--;
76        return true;
77    }
78    
79    int getFront() {
80        if(isEmpty()) return -1;
81        else return dq[front];
82    }
83    
84    int getRear() {
85        if(isEmpty()) return -1;
86        else return dq[rear];
87    }
88    
89    bool isEmpty() {
90        if(size == 0) return true;
91        else return false;
92    }
93    
94    bool isFull() {
95        if(size == capacity) return true;
96        else return false;
97    }
98};
99
100/**
101 * Your MyCircularDeque object will be instantiated and called as such:
102 * MyCircularDeque* obj = new MyCircularDeque(k);
103 * bool param_1 = obj->insertFront(value);
104 * bool param_2 = obj->insertLast(value);
105 * bool param_3 = obj->deleteFront();
106 * bool param_4 = obj->deleteLast();
107 * int param_5 = obj->getFront();
108 * int param_6 = obj->getRear();
109 * bool param_7 = obj->isEmpty();
110 * bool param_8 = obj->isFull();
111 */