// Last updated: 8/3/2026, 11:36:42 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        int currentData = node->val;
        ListNode* nextNode = node->next;

        node->val = nextNode->val;
        nextNode->val = currentData;

        node->next = node->next->next;

        delete nextNode;

        /*
        New Approach

        ListNode* next = node->next;
        *node = *next;

        */
        
    }
};