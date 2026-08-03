// Last updated: 8/3/2026, 11:36:44 PM
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

private:
    ListNode* reverse(ListNode* head) {
        ListNode* reverse = new ListNode(-1);

        ListNode* current = head;
        ListNode* temp = head;

        while(temp){
            current = current->next;

            temp->next = reverse->next;
            reverse->next = temp;
            temp = current;
        }

        return reverse->next;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revHead = reverse(slow->next);
        ListNode* temp = head;

        while(revHead){
            if(temp->val != revHead->val) return false;
            revHead = revHead->next;
            temp = temp->next;
        }

        reverse(slow->next);
        return true;
    }
};