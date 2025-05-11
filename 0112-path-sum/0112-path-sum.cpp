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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        return dfs(root, 0, targetSum);
    }

    bool dfs(TreeNode* node, int sum, int &targetSum){
        if (!node) return false;

        sum += node->val;

        if (!node->left && !node->right) {
            return sum == targetSum;
        }

        return dfs(node->left, sum, targetSum) || dfs(node->right, sum, targetSum);
    }
};