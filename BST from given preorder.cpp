// link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
    TreeNode* solve(vector<int> &nums,int &i,int bound){
        if(i==nums.size()|| nums[i]>bound)
            return NULL;
        TreeNode* root = new TreeNode(nums[i++]);
        root->left = solve(nums,i,root->val);
        root->right = solve(nums,i,bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& nums) {
        int i = 0,n = nums.size();
        return solve(nums,i,INT_MAX);
    }
};
