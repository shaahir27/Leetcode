// Last updated: 9/24/2026, 11:00:54 AM
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
13    ListNode* deleteDuplicates(ListNode* head) {
14
15        if(head == NULL || head->next == NULL)
16            return head;
17
18        ListNode* temp = head;
19        ListNode* dummy = new ListNode(-1);
20        ListNode* current = dummy;
21
22        int count = 0;
23
24        while(temp){
25            if(temp->next != NULL && temp->val == temp->next->val){
26                int val = temp->val;
27
28                while(temp != NULL && temp->val == val){
29                    temp = temp->next;
30                }
31
32                continue;
33            }
34
35            current->next = temp;
36            current = current->next;
37            temp = temp->next;
38        }
39
40        current->next = NULL;
41
42        return dummy->next;
43    }
44};