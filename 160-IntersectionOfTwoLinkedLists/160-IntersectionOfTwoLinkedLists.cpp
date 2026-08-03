// Last updated: 8/3/2026, 11:37:01 PM
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == NULL || headB == NULL) return NULL;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(true){
            if(temp1 == temp2) return temp1;

            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 == NULL && temp2 == NULL) return NULL;
            
            if(temp1 == NULL) temp1 = headB;
            if(temp2 == NULL) temp2 = headA;
        }      
    }
};