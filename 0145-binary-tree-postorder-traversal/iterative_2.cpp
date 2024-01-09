class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left)
                st1.push(root->left);
            if(root->right)
                st1.push(root->right);
        }
        while(!st2.empty()){
            root = st2.top();
            st2.pop();
            ans.push_back(root->val);
        }
        return ans;
    }
};
