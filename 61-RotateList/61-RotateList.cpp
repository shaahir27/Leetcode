// Last updated: 9/23/2026, 10:50:48 PM
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
13    vector<ListNode*> splitListToParts(ListNode* head, int k) {
14        ListNode* temp = head;
15        int count = 0;
16
17        vector<ListNode*> arr;
18
19        while(temp){
20            count++;
21            temp = temp->next;
22        }
23
24        int nodes = count/k;
25        int extra = count%k;
26
27        temp = head;
28
29        while(k > 0){
30            if(temp == NULL){
31                arr.push_back(nullptr);
32                k--;
33                continue;
34            }
35
36            int x = nodes;
37
38            if(extra > 0){
39                x++;
40                extra--;
41            }
42
43            ListNode* list = new ListNode(-1);
44            ListNode* current = list;
45
46            while(x > 0){   
47                current->next = temp;
48                current = temp;
49                temp = temp->next;
50                current->next = NULL;
51                x--;
52            }
53
54            arr.push_back(list->next);
55
56            k--;
57        }
58
59        return arr;
60    }
61};