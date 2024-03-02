
// link - https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root){
        vector<int> ans;
        if(root==NULL)
            return ans;
            
            map<int,int> nodes; //level->value
            queue<pair<Node*,int>> q; //Node->level
            q.push({root,0});
            while(!q.empty()){
                auto it = q.front();
                Node* front = it.first;
                int level = it.second;
                q.pop();
                
                if(nodes.find(level)==nodes.end())
                    nodes[level]=front->data;
                
                if(front->left)
                    q.push({front->left,level-1});
                
                if(front->right)
                    q.push({front->right,level+1});
        }
        
        for(auto it : nodes){
            ans.push_back(it.second);
        }
        return ans;
        
        
        //TIME COMPLEXITY - NlogN
        //SPACE COMPLEXITY - N
            
    }

};
