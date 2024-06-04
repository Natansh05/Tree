// link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
// Three Approaches


// ----------------------------1st Approach Recursivse------------------------------
// Time Complexity - O(N)
// Space Complexity - O(N)
class Solution {
public:

    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->right);
        flatten(root->left);

        root->right =prev;
        root->left = NULL;
        prev = root;
        return;
    }

};







// ------------------------2nd Approach using Stack-----------------------------
// Time Complexity - O(N)
// Space Complexity - O(N)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        stack<TreeNode*> st;
        st.push(root);
        while(st.empty()==0){
            TreeNode* curr = st.top();
            st.pop();

            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);

            if(st.empty()==0)
                curr->right = st.top();
            curr->left = NULL;
        }
    }
};


// ------------------------3rd Approach using Morris Traversal-----------------------------
// Time Complexity - O(N)
// Space Complexity - O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while(curr!=NULL){
            if(curr->left!=NULL){
                prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
