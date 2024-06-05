// link - https://leetcode.com/problems/binary-search-tree-iterator/description/
// Time Complexity - O(1) for has next and O(1) for next (in average case)
// Space Complexity - o(h)

class BSTIterator {
    stack<TreeNode*> st;
    private:
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return (st.empty()==0);
    }
};
