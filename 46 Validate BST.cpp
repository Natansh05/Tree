// link - https://leetcode.com/problems/validate-binary-search-tree/description/
// Time Complexity - O(N)
// Space Complexity - O(N)---recrusion stack space

class Solution {
    bool check(TreeNode* root,long low,long high){
        if(root==NULL)
            return 1;
        return (root->val >= low && root->val <= high) && check(root->left,low,1LL*root->val-1) && check(root->right,1LL*root->val+1,high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root,INT_MIN,INT_MAX);
    }
};
