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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>nums;
        
        inorder(root,nums);

        priority_queue<int> pq;

        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top(); 
    }

    void inorder(TreeNode* root,vector<int>&nums){
        if(!root) return;

        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
};