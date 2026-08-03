// Last updated: 8/3/2026, 11:36:51 PM
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
    ListNode* reverseList(ListNode* head) {
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
};