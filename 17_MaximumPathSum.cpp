// problem link - https://leetcode.com/problems/binary-tree-maximum-path-sum/
//Difficulty - Hard

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
    private:
    int solve(TreeNode* root,int &maxi){
        if(root==NULL)
            return 0;
        int left = max(0,solve(root->left,maxi));
        int right = max(0,solve(root->right,maxi));
        maxi = max(maxi,left+right+root->val);
        return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        int max = INT_MIN;
        solve(root,max);
        return max;
    }
};
