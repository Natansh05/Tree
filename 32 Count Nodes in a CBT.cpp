// link - https://leetcode.com/problems/count-complete-tree-nodes/description/

// Time Complexity - O(log(n^2))
// Space Complexity - O(H)

 
class Solution {
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        int ls = leftheight(root);
        int rs = rightheight(root);

        if(ls == rs)
            return (1<<ls) - 1;
        else
            return 1 + solve(root->left) + solve(root->right);
    }

    int leftheight(TreeNode* root){
        int cnt =0;
        while(root){
            cnt++;
            root = root->left;
        }
        return cnt;
    }

    int rightheight(TreeNode* root){
        int cnt = 0;
        while(root){
            ++cnt;
            root = root->right;
        }
        return cnt;
    }
public:
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};
