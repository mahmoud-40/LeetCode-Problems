class Solution {
public:
    unordered_map<TreeNode*, int> dp;

    int rob(TreeNode* root) {
        return sol(root);
    }

    int sol(TreeNode* node){ // 3
        if(!node) return 0;
	int &ret = dp[node];
	if(ret) return ret;
	// take
int ch1 = node->val;
if(node->right) ch1 += sol(node->right->right) + sol(node->right->left);
if(node->left) ch1 += sol(node->left->right) + sol(node->left->left);
// leave
	int ch2 = sol(node -> right) + sol(node->left);
	return ret = max(ch1, ch2);

    }
};