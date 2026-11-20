// Last updated: 11/21/2026, 12:18:30 AM
1class MyLinkedList {
2private:
3    struct ListNode{
4        int val;
5        ListNode *next;
6        ListNode() : val(0), next(nullptr) {}
7        ListNode(int x) : val(x), next(nullptr) {}
8        ListNode(int x, ListNode *next) : val(x), next(next) {}
9    };
10
11    ListNode* head = NULL;
12    ListNode* tail = NULL;
13    int size = 0;
14public:
15    MyLinkedList() {
16    }
17    
18    int get(int index) {
19        if(index<0 || index>=size || head == NULL) return -1;
20
21        ListNode* temp = head;
22        while(temp != NULL && index>0){
23            temp = temp->next;
24            index--;
25        }
26
27        if(temp == NULL) return -1;
28        return temp->val;
29    }
30    
31    void addAtHead(int val) {
32        ListNode* node = new ListNode(val);
33
34        if(head == NULL){
35            head = tail = node;
36            size++;
37            return;
38        }
39
40        node->next = head;
41        head = node;
42        size++;
43        return;
44    }
45    
46    void addAtTail(int val) {
47        ListNode* node = new ListNode(val);
48
49        if(tail == NULL){
50            head = tail = node;
51            size++;
52            return;
53        }
54
55        tail->next = node;
56        tail = node;
57        size++;
58        return;
59    } 
60    
61    void addAtIndex(int index, int val) {
62        if (index < 0 || index > size) return;
63
64        if (index == 0) {
65            addAtHead(val);
66            return;
67        }
68        if (index == size) {
69            addAtTail(val);
70            return;
71        }
72
73        ListNode* prev = head;
74        for (int i = 0; i < index - 1; i++) {
75            prev = prev->next;
76        }
77
78        ListNode* node = new ListNode(val);
79        node->next = prev->next;
80        prev->next = node;
81        size++;
82    }
83    
84    void deleteAtIndex(int index) {
85        if (index < 0 || index >= size || head == NULL) return;
86
87        if (index == 0) {
88            ListNode* del = head;
89            head = head->next;
90            if (head == NULL) {
91                tail = NULL;
92            }
93            delete del;
94            size--;
95            return;
96        }
97
98        ListNode* prev = head;
99        for (int i = 0; i < index - 1; i++) {
100            prev = prev->next;
101        }
102
103        ListNode* del = prev->next;
104        prev->next = del->next;
105        if (del == tail) {
106            tail = prev;
107        }
108        delete del;
109        size--;
110    }
111};
112
113/**
114 * Your MyLinkedList object will be instantiated and called as such:
115 * MyLinkedList* obj = new MyLinkedList();
116 * int param_1 = obj->get(index);
117 * obj->addAtHead(val);
118 * obj->addAtTail(val);
119 * obj->addAtIndex(index,val);
120 * obj->deleteAtIndex(index);
121 */