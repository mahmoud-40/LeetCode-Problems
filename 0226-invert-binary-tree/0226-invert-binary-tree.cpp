/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode* node){
        if(!node){
            return;
        }

        TreeNode* temp1 = node->left;
        TreeNode* temp2 = node->right;

        node->right = temp1;
        node->left = temp2;

        dfs(node->right);
        dfs(node->left);
    }
};