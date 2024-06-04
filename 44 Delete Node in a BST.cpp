// link - https://leetcode.com/problems/delete-node-in-a-bst/description/

// Time Complexity - O(logN)
// Space Complexity - O(1)

class Solution {
    TreeNode* min(TreeNode* &root){
        TreeNode* temp = root;
        while(temp->left!= NULL){
            temp = temp->left;
        }
        // cout<<"Minimum element of this BST is : "<<temp->val<<endl;
        return temp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int d) {
        if(root==NULL) return root;

        else if(root->val ==d){
            // 0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            //1 child
            if(root->left!=NULL && root->right == NULL){
                TreeNode* temp = (root->left);
                delete root;
                return temp;
            }

            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp = (root->right);
                delete root;
                return temp;
            }


            //2child
            if(root->left!=NULL && root->right!=NULL){
                int mini = min(root->right)->val;
                root->val = mini;
                root->right = deleteNode(root->right,mini);
                return root; 
            }


        }

        else if(root->val >d){
            //left part me jao 
            root->left = deleteNode(root->left, d);
            return root;
        }

        else{
            root->right = deleteNode(root->right,d);
            return root; 
        }
        return root;
    }
};
