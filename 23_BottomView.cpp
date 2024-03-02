// link - https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// same concept for recursive approach as top view

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
            
        queue<pair<Node*,int>> q;
        map<int,int> nodes;
        q.push({root,0});
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int level = node.second;
            Node* p = node.first;
            
            nodes[level]=p->data;
            if(p->left)
                q.push({p->left,level-1});
            if(p->right)
                q.push({p->right,level+1});
        }
        for(auto it : nodes){
            ans.push_back(it.second);
        }
        return ans;
    }
    
    // Time Complexity - NLogN
    // Space Complexity - N
};
