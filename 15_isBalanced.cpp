
//used pair to store previous value
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

// Time Complexity - o(N^2)
// Space Complexity - O(N^2)
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
