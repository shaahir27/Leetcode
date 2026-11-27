// Last updated: 11/27/2026, 12:02:31 PM
1
2class MyCircularQueue {
3private:
4    vector<int> q;
5    int front;
6    int rear;
7    int size;
8    int capacity;
9
10public:
11    MyCircularQueue(int k) {
12        q.resize(k);
13        front = 0;
14        rear = -1;
15        size = 0;
16        capacity = k;
17    }
18
19    bool enQueue(int value) {
20        if (isFull()) return false;
21
22        rear = (rear + 1) % capacity;
23        q[rear] = value;
24        size++;
25        return true;
26    }
27
28    bool deQueue() {
29        if (isEmpty()) return false;
30
31        front = (front + 1) % capacity;
32        size--;
33        return true;
34    }
35
36    int Front() {
37        if (isEmpty()) return -1;
38        return q[front];
39    }
40
41    int Rear() {
42        if (isEmpty()) return -1;
43        return q[rear];
44    }
45
46    bool isEmpty() {
47        return size == 0;
48    }
49
50    bool isFull() {
51        return size == capacity;
52    }
53};