// link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

// Time Complexity - O(N)
// Space Complexity - O(N) (recursive stack space)

class Solution {
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(0);
        if(root==NULL)
            return NULL;
        if(root==p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        else
            return root;
    }
};
