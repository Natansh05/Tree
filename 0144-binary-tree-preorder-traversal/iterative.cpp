class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *temp;
        if(root == NULL)
            return ans;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right)
                st.push(root->right);
            if(root->left)
                st.push(root->left);
        }
        return ans;
    }
};
