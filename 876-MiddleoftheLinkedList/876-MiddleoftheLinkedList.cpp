// Last updated: 9/21/2026, 10:31:25 PM
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
12private:
13    ListNode* reverse(ListNode* head) {
14
15        ListNode* prev = NULL;
16        ListNode* curr = head;
17
18        while (curr != NULL) {
19            ListNode* next = curr->next;
20            curr->next = prev;
21            prev = curr;
22            curr = next;
23        }
24
25        return prev;
26    }
27
28public:
29    ListNode* removeNodes(ListNode* head) {
30
31        head = reverse(head);
32
33        ListNode* curr = head;
34        ListNode* maxNode = head;
35
36        while (curr != NULL && curr->next != NULL) {
37
38            if (curr->next->val < maxNode->val) {
39                // Remove curr->next
40                curr->next = curr->next->next;
41            }
42            else {
43                // New maximum
44                curr = curr->next;
45                maxNode = curr;
46            }
47        }
48
49        // Reverse back
50        return reverse(head);
51    }
52};