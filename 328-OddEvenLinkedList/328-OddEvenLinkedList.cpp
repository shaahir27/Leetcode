// Last updated: 8/3/2026, 11:36:29 PM
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
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* temp = even->next;

        int count = 3;

        while(temp){
            if(count%2 == 1){
                ListNode* node = temp;
                temp = temp->next;
                node->next = odd->next;
                odd->next = node;
                even->next = temp;
                odd = node;
                
            }
            else if(count%2 == 0){
                even = temp;
                temp = temp->next;
            }
            count++;
        }
        return head;
    }
};