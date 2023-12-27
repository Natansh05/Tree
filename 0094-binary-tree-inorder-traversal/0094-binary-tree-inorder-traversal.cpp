/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//T.C. - O(N)
//S.C. - O(N)

//striver's vid link - https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=11


class Solution {
public:
    //recursive approach
    vector<int> ans;
    void inorder(TreeNode* root){
        if(root==NULL) 
            return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        inorder(root);
        return ans;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        //iterative version;
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> ans;
        while(1){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty())
                    break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;    
    }
};
