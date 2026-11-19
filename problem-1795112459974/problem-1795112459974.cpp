// Last updated: 11/19/2026, 11:50:59 PM
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
11/**
12 * Definition for a binary tree node.
13 * struct TreeNode {
14 *     int val;
15 *     TreeNode *left;
16 *     TreeNode *right;
17 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
18 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
19 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
20 * };
21 */
22
23 class Solution {
24public:
25    TreeNode* sortedListToBST(ListNode* head) {
26        if(head == NULL) return NULL;
27        if(head->next == NULL) return new TreeNode(head->val);
28
29        ListNode* prev = NULL;
30        ListNode* slow = head;
31        ListNode* fast = head;
32
33        while(fast != NULL && fast->next != NULL){
34            prev = slow;
35            slow = slow->next;
36            fast = fast->next->next;
37        }
38
39        if(prev != NULL){
40            prev->next = NULL;
41        }
42
43        ListNode* rightHalf = slow->next;
44        slow->next = NULL;
45
46        TreeNode* node = new TreeNode(slow->val);
47        node->left = sortedListToBST(head);
48        node->right = sortedListToBST(rightHalf);
49
50        return node;
51    }
52};
53
54 /*
55My Approach (Failed)
56class Solution {
57private:
58    TreeNode* insertNode(TreeNode* root, int val){
59        if(root == NULL){
60            TreeNode* node = new TreeNode(val);
61            return node;
62        }
63        
64        if(root->val > val){
65            root->left = insertNode(root->left, val);
66        }
67        else{
68            root->right = insertNode(root->right, val);
69        }
70        return root;
71    }
72public:
73    TreeNode* sortedListToBST(ListNode* head) {
74        if(head == NULL) return NULL;
75        
76        ListNode* fast = head;
77        ListNode* slow = head;
78
79        while (fast != NULL && fast->next != NULL){
80            slow = slow->next;
81            fast = fast->next->next;
82        }
83
84        ListNode* middle = slow;
85        ListNode* temp = head;
86        
87        TreeNode* node = new TreeNode(slow->val);
88        slow = slow->next;
89
90        while(slow != NULL){
91            node = insertNode(node, slow->val);
92            node = insertNode(node, temp->val);
93
94            slow = slow->next;
95            temp = temp->next;
96        }
97
98        while(temp != middle){
99            node = insertNode(node, temp->val);
100            temp = temp->next;
101        }
102
103        return node;
104    }
105};
106*/