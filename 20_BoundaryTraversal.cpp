//link - https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/

//brute force
class Solution {
    vector<int> left,right,leaf;
    private:
    void left_fn(Node* root){
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return;
        left.push_back(root->data);
        if(root->left!=NULL)
            left_fn(root->left);
        else
            left_fn(root->right);
        return;
    }
    
    void right_fn(Node* root){
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return;
        right.push_back(root->data);
        if(root->right)
            right_fn(root->right);
        else
            right_fn(root->left);
        return;
    }
    
    void inorder(Node* root){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->data);
            return;
        }
        inorder(root->left);
        inorder(root->right);
        return;
    }
    
public:
    vector <int> boundary(Node *root){
        left_fn(root);
        inorder(root);
        right_fn(root->right);
        
        vector<int> ans;
        
        merge(left.begin(),left.end(),leaf.begin(),leaf.end(),ans.begin());
        reverse(right.begin(),right.end());
        merge(ans.begin(),ans.end(),right.begin(),right.end(),ans.begin());
        
        return ans;
    }
};


//optimal approach
class Solution {
public:

    void leftNode(Node *root, vector<int> &ans) {
      if (!root)
        return;
    
      if (!(root->left == NULL && root->right == NULL))
            ans.push_back(root->data);
      
      if (!root->left)
        leftNode(root->right, ans);
        
      else
        leftNode(root->left, ans);
    }
    
    void rightNode(Node *root, stack<int> &st) {
      if (!root)
        return;
    
      if (!(root->left == NULL && root->right == NULL))
        st.push(root->data);
      
      if (!root->right)
        rightNode(root->left, st);
      else
        rightNode(root->right, st);
        
    }
    
    void inorder(Node *root, vector<int> &ans) {
      if (!root)
        return;
      inorder(root->left, ans);
      
      if (root->left == NULL && root->right == NULL)
        ans.push_back(root->data);
        
      inorder(root->right, ans);
    }
    
    vector <int> boundary(Node *root){
        //Your code here
      vector<int> ans;
      if(!root) return ans;
      ans.push_back(root->data);

      if (root->left == NULL && root->right == NULL) {
        return ans;
      }
      
      
      leftNode(root->left, ans);  // to get left nodes
      
      inorder(root, ans); // to get all leaf nodes
    
      stack<int> st;
      rightNode(root->right, st);  // to get right nodes in reverse order
    
      while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
      }
    
      return ans;
    }
};
