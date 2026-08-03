// Last updated: 8/3/2026, 11:37:17 PM
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
    bool hasCycle(ListNode *head) {

        ListNode* one = head;
        ListNode* two = head;

        while(two != NULL && two->next != NULL){
            one = one->next;
            two = two->next->next;

            if(one == two) return true;
        }

        return false;
    }
};