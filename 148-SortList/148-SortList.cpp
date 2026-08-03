// Last updated: 8/3/2026, 11:37:10 PM
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
    ListNode* findMiddle(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){  // points to first middle node
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeList(ListNode* left, ListNode* right){

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(left && right){
            if(left->val < right->val){
                temp->next = left;
                temp = left;
                left = left->next;

            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        if(left) temp->next = left;
        else temp->next = right;


        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

        ListNode* middle = findMiddle(head);
        
        ListNode* rightHead = middle->next;
        middle->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return mergeList(left, right);
    }
};