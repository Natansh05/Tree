class Solution {
    private:
    int height(TreeNode *root){
        if(root==NULL)
            return 0;
        int left = height(root->left);
        if(left==-1)
            return -1;
        int right = height(root->right);
        if(right == -1)
            return -1;
        int diff = abs(left-right);
        if(diff>1)
            return -1;
        return max(left,right)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        return height(root)!=-1;
    }
};
