// link - https://leetcode.com/problems/symmetric-tree/description/

class Solution {
public:

    bool isMirror(TreeNode* n1,TreeNode* n2){
        if(n1==NULL && n2 ==NULL) return true;
        if(n1==NULL || n2 ==NULL) return false;
        return n1->val == n2->val && isMirror(n1->right,n2->left) && isMirror   (n1->left,n2->right);
    }

    bool isSymmetric(TreeNode* root) {
            return isMirror(root,root);
    }
};
