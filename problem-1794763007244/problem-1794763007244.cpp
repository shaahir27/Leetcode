// Last updated: 11/15/2026, 10:46:47 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11
12 class Solution {
13public:
14    ListNode* partition(ListNode* head, int x) {
15        ListNode* small = new ListNode(0);
16        ListNode* large = new ListNode(0);
17
18        ListNode* smallTail = small;
19        ListNode* largeTail = large;
20
21        while(head != NULL){
22            if(head->val < x){
23                smallTail->next = head;
24                smallTail = smallTail->next;
25            }
26            else{
27                largeTail->next = head;
28                largeTail = largeTail->next;
29            }
30
31            head = head->next;
32        }
33
34        largeTail->next = NULL;
35        smallTail->next = large->next;
36
37        return small->next;
38    }
39};
40
41 /*
42
43 My Approach - i didnt complete it coz it doesnt seems  to be satisfying the ost conditons... requires vatious if loops to tackle those
44
45
46class Solution {
47public:
48    ListNode* partition(ListNode* head, int x) {
49        if(head == NULL) return head;
50        ListNode* prev = NULL;
51        ListNode* target = head;
52
53        while (target->next != NULL && target->next->val < x) {
54            prev = target;
55            target = target->next;
56        }
57        
58        if(prev == NULL){
59            target = head;
60        }
61
62        ListNode* temp = target;
63      
64        while(temp->next != NULL){
65            if(temp->next->val < x){
66                ListNode* node = temp->next;
67                temp->next = temp->next->next;
68                node->next = prev->next;
69                prev->next = node;
70                prev = prev->next;
71            }
72
73            temp = temp->next;
74        }
75
76        return head;
77    }
78};
79
80*/