// link - O(logN)
// Time Complexity - O(logN)
// Space Complexity - O(1)

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderPredecessor(Node *root, Node *x)
    {
        Node* ans = NULL;
        while(root){
            if(x->data <= root->data){
                root = root->left;
            }
            else{
                ans = root;
                root = root->right;
            }
        }
        return ans;
    }
};

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* ans = NULL;
        while(root){
            if(x->data >= root->data){
                root = root->right;
            }
            else{
                ans = root;
                root = root->left;
            }
        }
        return ans;
    }
};
