//T.C. - O(N);
//S.C. - O(N)  RECURSION STACK SPACE
//striver's link - https://www.youtube.com/watch?v=Bfqd8BsPVuw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=10

class Solution {
public:
    vector<int> ans;
    void preorder(TreeNode* root){
        if(root==NULL)
            return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        preorder(root);
        return ans;
    }
};
