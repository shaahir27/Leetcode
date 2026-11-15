// Last updated: 11/15/2026, 10:51:24 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13private:
14    void inorder(TreeNode* root, vector<int>& result){
15        if(root == NULL) return;
16        
17        inorder(root->left, result);
18        result.push_back(root->val);
19        inorder(root->right, result);
20    }
21public:
22    vector<int> inorderTraversal(TreeNode* root) {
23        vector<int> result;
24        inorder(root, result);
25
26        return result;
27    }
28};