//Link to striver's notes - https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree/
//Link to striver's video - https://youtu.be/EoAsWbO7sqg

//T.C. - O(N)
//S.C. - O(N)


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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL)
            return ans;
    
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;++i){
                TreeNode* top = q.front();
                q.pop();
                
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
                level.push_back(top->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
