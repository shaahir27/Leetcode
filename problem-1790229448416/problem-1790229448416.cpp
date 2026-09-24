// Last updated: 9/24/2026, 11:27:28 AM
1class Solution {
2private:
3    ListNode* reverseList(ListNode* start, ListNode* end) {
4
5        ListNode* prev = NULL;
6        ListNode* temp = start;
7        ListNode* afterEnd = end->next;
8
9        while(temp != afterEnd){
10            ListNode* next = temp->next;
11            temp->next = prev;
12            prev = temp;
13            temp = next;
14        }
15
16        return prev;
17    }
18
19public:
20    ListNode* reverseBetween(ListNode* head, int left, int right) {
21
22        if(head == NULL || left == right)
23            return head;
24
25        ListNode* temp = head;
26        ListNode* leftNode = NULL;
27        ListNode* rightNode = NULL;
28        ListNode* beforeLeft = NULL;
29
30        int pos = 1;
31
32        while(temp != NULL){
33
34            if(pos == left){
35                leftNode = temp;
36            }
37
38            if(pos == right){
39                rightNode = temp;
40                break;
41            }
42
43            if(pos == left - 1){
44                beforeLeft = temp;
45            }
46
47            temp = temp->next;
48            pos++;
49        }
50
51        ListNode* afterRight = rightNode->next;
52
53        reverseList(leftNode, rightNode);
54
55        if(beforeLeft != NULL)
56            beforeLeft->next = rightNode;
57        else
58            head = rightNode;
59
60        leftNode->next = afterRight;
61
62        return head;
63    }
64};