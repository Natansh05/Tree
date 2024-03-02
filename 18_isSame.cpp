//link - https://leetcode.com/problems/same-tree/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(0);
        if(p==NULL && q==NULL) return true;
        else if(p!=NULL && q==NULL) return false;
        else if(p==NULL && q!=NULL) return false;

        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        bool value = p->val == q->val;
        
        if(left && right && value) return 1;
        else return 0;
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return 1;
        if(p==NULL || q==NULL)
            return 0;
        if(p->val==q->val)
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        return false;
    }
};
