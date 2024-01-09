class Solution {
public:
    vector<int> postorderTraversal(TreeNode* curr) {
        ios_base::sync_with_stdio(0);
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode * temp=NULL;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                temp = st.top()->right;
                if(temp==NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
};
