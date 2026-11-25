// Last updated: 11/25/2026, 5:18:52 PM
1class LFUCache {
2private:
3    struct ListNode {
4        int key;
5        int val;
6        int freq = 1;
7        ListNode* next;
8        ListNode* prev;
9
10        ListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
11    };
12
13    struct DoublyLinkedList {
14        int size = 0;
15        ListNode* head;
16        ListNode* tail;
17
18        DoublyLinkedList() {
19            head = new ListNode(-1, -1);
20            tail = new ListNode(-1, -1);
21            head->next = tail;
22            tail->prev = head;
23        }
24
25        void insertAtHead(ListNode* node) {
26            ListNode* nextHead = head->next;
27            node->next = nextHead;
28            node->prev = head;
29            head->next = node;
30            nextHead->prev = node;
31            size++;
32        }
33
34        void deleteNode(ListNode* node) {
35            ListNode* prevNode = node->prev;
36            ListNode* nextNode = node->next;
37            prevNode->next = nextNode;
38            nextNode->prev = prevNode;
39            size--;
40        }
41    };
42
43    unordered_map<int, ListNode*> cache;
44    unordered_map<int, DoublyLinkedList*> freq;
45    int capacity_;
46    int minFreq = 0;
47
48    void updateFrequency(ListNode* node) {
49        int currentFreq = node->freq;
50        freq[currentFreq]->deleteNode(node);
51
52        if (currentFreq == minFreq && freq[currentFreq]->size == 0) {
53            minFreq++;
54        }
55
56        node->freq++;
57        int newFreq = node->freq;
58
59        if (freq.find(newFreq) == freq.end()) {
60            freq[newFreq] = new DoublyLinkedList();
61        }
62        freq[newFreq]->insertAtHead(node);
63    }
64
65public:
66    LFUCache(int capacity) {
67        capacity_ = capacity;
68    }
69
70    int get(int key) {
71        if (cache.find(key) == cache.end()) return -1;
72
73        ListNode* node = cache[key];
74        updateFrequency(node);
75        return node->val;
76    }
77
78    void put(int key, int value) {
79        if (capacity_ == 0) return;
80
81        if (cache.find(key) != cache.end()) {
82            ListNode* node = cache[key];
83            node->val = value;
84            updateFrequency(node);
85            return;
86        }
87
88        if (cache.size() == capacity_) {
89            DoublyLinkedList* minList = freq[minFreq];
90            ListNode* lruNode = minList->tail->prev;
91            cache.erase(lruNode->key);
92            minList->deleteNode(lruNode);
93            delete lruNode;
94        }
95
96        minFreq = 1;
97        if (freq.find(minFreq) == freq.end()) {
98            freq[minFreq] = new DoublyLinkedList();
99        }
100
101        ListNode* newNode = new ListNode(key, value);
102        freq[minFreq]->insertAtHead(newNode);
103        cache[key] = newNode;
104    }
105};
106
107/**
108 * Your LFUCache object will be instantiated and called as such:
109 * LFUCache* obj = new LFUCache(capacity);
110 * int param_1 = obj->get(key);
111 * obj->put(key,value);
112 */