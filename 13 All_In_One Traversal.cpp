// link - dne
// Time Complexity - O(3*N)
// Space Complexity - O(3*N)

typedef pair<Node*,int> pi;
    
    void solve(Node* root,vector<int> &preorder,vector<int> &inorder,vector<int> &postorder){
        stack<pi> st;
        if(root==NULL)
            return;
        st.push({root,1});
        
        
        while(st.empty()==0){
            pi it = st.top();
            st.pop();
            
            int num = it.second;
            Node* node = it.first;
            
            if(it.second==1){
                preorder.push_back(node->data);
                st.push({node,num+1});
                if(node->left)
                    st.push({node->left,num});
            }
            else if(it.second==2){
                inorder.push_back(node->data);
                st.push({node,it.second+1});
                if(node->right)
                    st.push({node->right,num});
            }
            else{
                postorder.push_back(node->data);
            }
        }
        
        return;
    }
