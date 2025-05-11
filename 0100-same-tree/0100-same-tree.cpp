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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> t1;
        vector<int> t2;

        dfs(p, t1);
        dfs(q, t2);

        if(t1.size() != t2.size())
            return false;

        for(int i = 0; i < max(t1.size(), t2.size()); i++){
            if(t1[i] != t2[i]){
                return false;
            }
        }
        
        return true;
    }

    void dfs(TreeNode* node, vector<int>& nodes){
        if(!node){
            nodes.push_back(INT_MIN);
            return;
        }
        
        nodes.push_back(node->val);
        dfs(node->left, nodes);
        dfs(node->right, nodes);
    }
};