// link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
// Time Complexity - O(N)
// Space Complexity - O(N)
// Morris Traversal


class Solution {
    int inorder(TreeNode* root,int k) {
        TreeNode* curr = root;
        int ans = 0;
        vector<int> inorder;
        while(curr){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                if(inorder.size()==k){
                    ans = curr->val;
                }
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
                    if(inorder.size()==k){
                        ans =  curr->val;
                        return ans;
                    }
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = inorder(root,k);
        return ans;
    }
};
