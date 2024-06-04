// link - https://leetcode.com/problems/binary-tree-inorder-traversal/description/
// linnk2 - https://leetcode.com/problems/binary-tree-preorder-traversal/description/

// Time Complexity - O(N)
// Space Complexity - O(1)--------------MORRIS TRAVERSAL

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> inorder;
        while(curr){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev= prev->right;
                }

                if(prev->right==NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};




class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> preorder;
        while(curr){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr){
                    prev= prev->right;
                }

                if(prev->right==NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right=NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};

// 
