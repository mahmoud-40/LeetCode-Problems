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
    // O(n)
    // O(n) : call stack. o(1) if ignoring
    int goodNodes(TreeNode* root) {
        int _goodNodes = countGood(root, root->val);
        return _goodNodes;
    }

    int countGood(TreeNode* node, int mxValue){  
        if(!node){
            return 0;
        }

        int right = 0; 
        int left = 0;

        if(mxValue <= node->val){
            right = countGood(node->right, node->val) + 1;  
            left = countGood(node->left, node->val);  
        }
        else{
            right = countGood(node->right, mxValue);  
            left = countGood(node->left, mxValue);
        }

        return (right + left);  
    }
};