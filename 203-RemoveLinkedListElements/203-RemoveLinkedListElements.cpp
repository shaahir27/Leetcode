// Last updated: 9/18/2026, 10:25:30 PM
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
13    ListNode* removeElements(ListNode* head, int val) {
14        ListNode* temp = head;
15        ListNode* prev = NULL;
16
17        while(temp != NULL){
18
19            if(temp->val == val){
20                if(temp == head){
21                    head = head->next;
22                    delete temp;
23                    temp = head;
24                }
25                else{
26                    prev->next = temp->next;
27                    delete temp;
28                    temp = prev->next;
29                }
30            }
31            else{
32                prev = temp;
33                temp = temp->next;
34            }
35        }
36
37        return head;
38    }
39};