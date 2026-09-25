// Last updated: 9/25/2026, 10:45:39 PM
1class Solution {
2private:
3    ListNode* reverseList(ListNode* start, ListNode* end){
4
5        ListNode* reverse = new ListNode(-1);
6
7        ListNode* current = start;
8        ListNode* temp = start;
9        
10        ListNode* afterEnd = end->next;
11
12        while(temp != afterEnd){
13
14            current = current->next;
15
16            temp->next = reverse->next;
17            reverse->next = temp;
18
19            temp = current;
20        }
21
22        return reverse->next;
23    }
24
25public:
26    ListNode* reverseBetween(ListNode* head, int left, int right) {
27
28        if(head == NULL || left == right)
29            return head;
30
31        ListNode* temp = head;
32        ListNode* leftNode = NULL;
33        ListNode* rightNode = NULL;
34        ListNode* beforeLeft = NULL;
35
36        int pos = 1;
37
38        while(temp != NULL){
39
40            if(pos == left){
41                leftNode = temp;
42            }
43
44            if(pos == right){
45                rightNode = temp;
46                break;
47            }
48
49            if(pos == left - 1){
50                beforeLeft = temp;
51            }
52
53            temp = temp->next;
54            pos++;
55        }
56
57        ListNode* afterRight = rightNode->next;
58
59        reverseList(leftNode, rightNode);
60
61        if(beforeLeft != NULL)
62            beforeLeft->next = rightNode;
63        else
64            head = rightNode;
65
66        leftNode->next = afterRight;
67
68        return head;
69    }
70};