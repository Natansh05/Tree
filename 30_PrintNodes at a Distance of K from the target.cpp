// link - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
// Time Complexity - O(N)
// Space Complexity - O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    map<TreeNode*,TreeNode*> mp;
    void markParents(TreeNode* root){
        if(root==NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==0){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root);
        int curr_level = 0;
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = 1;

        while(q.empty()==0){
            int size = q.size();
            if(curr_level ++ ==k)
                break;
            for(int i=0;i<size;++i){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && vis[curr->left]==0){
                    q.push(curr->left);
                    vis[curr->left] = 1;
                }
                if(curr->right && vis[curr->right]==0){
                    q.push(curr->right);
                    vis[curr->right] = 1;
                }
                if( mp[curr] && vis[mp[curr]]==0){
                    q.push(mp[curr]);
                    vis[mp[curr]]=1;
                }
            }
        }
        vector<int> ans;

        while(q.empty()==0){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
