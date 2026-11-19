// Last updated: 11/19/2026, 11:53:24 PM
class Solution {
public:
    TreeNode* build(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);
        root->left = build(head);
        root->right = build(slow->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return build(head);
    }
};