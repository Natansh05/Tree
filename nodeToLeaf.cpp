// link - https://leetcode.com/problems/binary-tree-paths/description/

// Time Complexity - O(n*k); // k is the time for appending string for line 11
// Space Complexity - O(n) // recursion stack space


class Solution {
    void getPath(TreeNode* root,string str,vector<string> &ans){
        if(root==NULL)
            return;
        str += to_string(root->val);
        str+="->";
        if(root->left==NULL && root->right == NULL){
            str.pop_back();
            str.pop_back();
            ans.push_back(str);

            return;
        }
        getPath(root->left,str,ans);
        getPath(root->right,str,ans);
        str.pop_back();
        str.pop_back();
        str.pop_back();
        return;
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        vector<string> ans;
        if(root==NULL)
            return ans;
        string str = "";
        getPath(root,str,ans);
        return ans;
    }
};
