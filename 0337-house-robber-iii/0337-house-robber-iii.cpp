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
    unordered_map<TreeNode*, int> dp;

    int rob(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* node){ // 3
        if(node == nullptr){
            return 0;
        }

        if(dp.count(node)){ 
            return dp[node];
        }

        int take = node->val; // 3  -> 4   5
        
        if(node->right != nullptr)
            take += dfs(node->right->right) + dfs(node->right->left); // 1 
        
        if(node->left != nullptr)
            take += dfs(node->left->right) + dfs(node->left->left); // 1 3 

        int leave = dfs(node->left) + dfs(node->right); // 4 + 5

        return dp[node] = max(take, leave); // 8 , 9  => dp[node] = 9
    }
};