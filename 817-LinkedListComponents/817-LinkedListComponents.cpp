// Last updated: 11/21/2026, 11:34:34 PM
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
13    int numComponents(ListNode* head, vector<int>& nums) {
14        unordered_map<int, int> mpp;
15        int n = nums.size();
16        int count = 0;
17
18        for(int i=0; i<n; i++){
19            mpp[nums[i]] = 1;
20        }
21
22        ListNode* temp = head;
23
24        while(temp != NULL){
25
26            int element = temp->val;
27            if(mpp[element]){
28                count++;
29                if(temp->next == NULL) return count;
30
31                while(temp->next != NULL && mpp[temp->next->val]){
32                    temp = temp->next;
33                }
34            }
35
36            temp = temp->next;
37        }
38
39        return count;
40    }
41};
42
43
44/*
45Approach using set instead of map
46
47Advantages:
48    - Cleaner syntax with range initialization from nums
49    - Stores unique keys only without dummy mapped values
50    - Lower memory overhead per element than an unordered map
51    - Avoids inserting missing keys during lookups via count or find
52    - Simpler single pass logic with clear component entry and exit tracking
53
54class Solution {
55public:
56    int numComponents(ListNode* head, vector<int>& nums) {
57        unordered_set<int> st(nums.begin(), nums.end());
58        int count = 0;
59        bool inComponent = false;
60        while (head != NULL) {
61            if (st.count(head->val)) {
62                if (!inComponent) {
63                    count++;
64                    inComponent = true;
65                }
66            } 
67            else {
68                inComponent = false;
69            }
70            head = head->next;
71        }
72        return count;
73    }
74};
75*/