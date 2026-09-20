// Last updated: 9/20/2026, 10:55:46 PM
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
11class Solution {
12public:
13    ListNode* rotateRight(ListNode* head, int k) {
14
15        if (head == NULL || head->next == NULL || k == 0)
16            return head;
17
18        ListNode* dummy = new ListNode(-1);
19        ListNode* temp = head;
20        ListNode* current = dummy;
21
22        int length = 0;
23
24        while(temp){
25            length++;
26            temp = temp->next;
27        }
28
29        k = k%length;
30
31        if(k==0){
32            return head;
33        }
34        
35        int remaining = length - k;
36        temp = head;
37
38        while(remaining>0){
39            current->next = temp;
40            temp = temp->next;
41            current = current->next;
42            remaining--;
43        }
44
45        current->next = NULL;
46        current = dummy;
47
48        while(temp){
49            ListNode* node = temp;
50            temp = temp->next;
51            node->next = current->next;
52            current->next = node;
53            current = node;
54        }
55
56        return dummy->next;
57    }
58};