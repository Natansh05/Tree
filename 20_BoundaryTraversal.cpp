//link - https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/

// Time , Space Complexity - O(N)
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
