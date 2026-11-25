// Last updated: 11/25/2026, 4:01:14 PM
1class LRUCache {
2private:
3    struct ListNode{
4        int key;
5        int val;
6        ListNode* next;
7        ListNode* prev;
8
9        ListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
10    };
11
12    unordered_map<int, ListNode*> cache;
13    ListNode* head = new ListNode(-1, -1);
14    ListNode* tail = new ListNode(-1, -1);
15    int capacity_;
16    int size = 0;
17
18    void deleteNode(ListNode* node){
19        ListNode* prevNode = node->prev;
20        ListNode* nextNode = node->next;
21
22        prevNode->next = nextNode;
23        nextNode->prev = prevNode;
24    }
25
26    void insertAtHead(ListNode* node){
27        ListNode* afterHead = head->next;
28        head->next = node;
29        node->prev = head;
30        node->next = afterHead;
31        afterHead->prev = node;
32    }
33
34public:
35    LRUCache(int capacity) {
36        capacity_ = capacity;
37        head->next = tail;
38        tail->prev = head;
39    }
40    
41    int get(int key) {
42        if(cache.find(key) == cache.end()) return -1;
43        
44        ListNode* node = cache[key];
45        deleteNode(node);
46        insertAtHead(node);
47
48        return node->val;
49    }
50    
51    void put(int key, int value) {
52        if(cache.find(key) != cache.end()){
53            cache[key]->val = value;
54
55            ListNode* node = cache[key];
56            deleteNode(node);
57            insertAtHead(node);
58            return;
59        }
60
61        if(capacity_ == size){
62            ListNode* last = tail->prev;
63            deleteNode(last);
64            cache.erase(last->key);
65            size--;
66        }
67
68        ListNode* node = new ListNode(key, value);
69        cache[key] = node;
70
71        insertAtHead(node);
72        size++;
73        return;
74    }
75};
76
77/**
78 * Your LRUCache object will be instantiated and called as such:
79 * LRUCache* obj = new LRUCache(capacity);
80 * int param_1 = obj->get(key);
81 * obj->put(key,value);
82 */