// link - https://leetcode.com/problems/diameter-of-binary-tree/

// Time Complexity - O(N) 
// Space Complexity - O(N) 

class Solution {
    private:
    int height(TreeNode *root,int &maxi){
        if(root==NULL)
            return 0;
        int lh = height(root->left,maxi);
        int rh = height(root->right,maxi);
        maxi = max(maxi,lh+rh);
        return 1  + max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        int max = 0;
        height(root,max);
        return max;
    }
};
