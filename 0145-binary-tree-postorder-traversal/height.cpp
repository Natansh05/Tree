class Solution {
public:
    int maxDepth(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        if(root==NULL)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right)+1;
    }
};
