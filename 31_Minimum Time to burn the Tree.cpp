// link - https://www.geeksforgeeks.org/problems/burning-tree/1
// Time Complexity - O(N)
// Space Complexity - O(N)


class Solution {
    int ans=0;
    private:
    //mapping banayega ye function aur target ka node return kar dega
    Node* parent(Node* root,int data,unordered_map<Node*,Node*> &map){
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front->data==data)
                res = front;
            if(front->left){
                map[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                map[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    int burnTree(Node* node,unordered_map<Node*,Node*> &map){
        unordered_map<Node*,bool> vis;
        queue<Node*> q;
        q.push(node);
        vis[node]=1;

        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i=0;i<size;++i){
                Node* root = q.front();
                q.pop();
                if(root->left && vis[root->left]==0){
                    q.push(root->left);
                    flag = 1;
                    vis[root->left]=1;
                }
                if(root->right && vis[root->right]==0){
                    flag = 1;
                    q.push(root->right);
                    vis[root->right]=1;
                }
                if(map[root] && vis[map[root]]==0){
                    flag = 1;
                    q.push(map[root]);
                    vis[map[root]]=1;
                }
                
            }
            if(flag)
                ++ans;

        }
        return ans;
    }
  public:
    int minTime(Node* root, int target){
        unordered_map<Node*,Node*> map;
        Node* node = parent(root,target,map);
        return burnTree(node,map);
    }
};
