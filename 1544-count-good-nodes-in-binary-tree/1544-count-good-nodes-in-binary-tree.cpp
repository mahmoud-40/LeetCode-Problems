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
    int goodNodes(TreeNode* root) {
        int _goodNodes = countGood(root, root->val);
        return _goodNodes / 2;
    }

    int countGood(TreeNode* node, int mxValue){ // 3 3 4 2
        if(!node){
            return 0;
        }

        int right = 0; 
        int left = 0;

        if(mxValue <= node->val){
            right = countGood(node->right, node->val) + 1; // 0 
            left = countGood(node->left, node->val) + 1; // 3 4
        }
        else{
            right = countGood(node->right, mxValue); // 2
            left = countGood(node->left, mxValue);
        }

        return (right + left); // 1 2 3
    }
};