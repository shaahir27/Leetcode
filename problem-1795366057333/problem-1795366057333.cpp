// Last updated: 11/22/2026, 10:17:37 PM
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
13    ListNode* reverseList(ListNode* head){
14        if(head == NULL || head->next == NULL) return head;
15        ListNode* result = new ListNode(-1);
16        ListNode* temp = head;
17
18        while(temp != NULL){
19            ListNode* node = temp;
20            temp = temp->next;
21            node->next =  result->next;
22            result->next = node;
23        }
24
25        return result->next;
26    }
27public:
28    vector<int> nextLargerNodes(ListNode* head) {
29        vector<int> answer;
30        stack<ListNode> st;
31
32        head = reverseList(head);
33        ListNode* temp = head;
34
35        while(temp != NULL){
36
37            while(!st.empty() && st.top().val <= temp->val){
38                st.pop();
39            }
40
41            if(!st.empty()) answer.push_back(st.top().val);
42            else answer.push_back(0);
43
44            st.push(*temp);
45
46            temp = temp->next;
47        }
48        
49        reverse(answer.begin(), answer.end());
50
51        return answer;
52    }
53};