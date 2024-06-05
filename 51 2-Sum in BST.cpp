// link - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
// Time Complexity - o(N)
// Space Complexity - O(H)

class BSTIterator{
    stack<TreeNode*>st;
    // reverse->true->> before
    // reverse->false->>next
    bool reverse=true;
public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse=isReverse;
        partialInorder(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    void partialInorder(TreeNode* root){
        while(root!=NULL){
            st.push(root);
            if(reverse){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
    int next(){
        TreeNode* node=st.top();
        st.pop();
        if(reverse){
            partialInorder(node->left);
        }
        else{
            partialInorder(node->right);
        }
        return node->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        // for next
        BSTIterator l(root, false);
        // for before
        BSTIterator r(root, true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k){
                i=l.next();
            }
            else{
                j=r.next();
            }
        }
        return false;
    }
};
