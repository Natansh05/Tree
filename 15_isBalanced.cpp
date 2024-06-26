// link - https://leetcode.com/problems/balanced-binary-tree/description/


//used pair to store previous value
// Time Complexity - O(N)
// Space Complexity - O(N) --- (only recursion stack space for given function )
// alag se height calculate karne nai ja rahe apan to no use for another recursion stack space
class Solution {
public:

    pair<bool,int> IsBalancedFast(TreeNode* &root){
        if(root==NULL){
        pair<bool,int> p = make_pair(true,0);
            return p;
        }

        pair<bool,int> left = IsBalancedFast(root->left);
        pair<bool,int> right = IsBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second)<=1;
        pair<bool,int> ans;
        ans.second = max(left.second , right.second) +1;

        if(leftAns && rightAns && diff) {
            ans.first = true;
        }
        else {
            ans.first = false;
        }
        return ans;

    }

    bool isBalanced(TreeNode* root) {
        return IsBalancedFast(root).first;
    }
};



//recursive approach

// Time Complexity - o(N)
// Space Complexity - O(NlogN)
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
