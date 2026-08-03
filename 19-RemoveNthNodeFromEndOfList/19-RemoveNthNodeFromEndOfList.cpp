// Last updated: 8/3/2026, 11:38:17 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(n==1 && head->next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(n>0){
            fast = fast->next;
            n--;
        }

        if(fast == NULL){
            ListNode* temp = head;
            head = head->next;
            delete(temp);

            return head;
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* del = slow->next;

        slow->next = del->next;
        delete(del);

        return head;
    }
};