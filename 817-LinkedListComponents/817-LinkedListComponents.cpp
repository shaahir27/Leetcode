// Last updated: 11/21/2026, 11:29:31 PM
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
31                while(temp->next != NULL && mpp[temp->next->val])
32                    temp = temp->next;
33            }
34
35            temp = temp->next;
36        }
37
38        return count;
39    }
40};