//link - https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* curr = root;
        Node* ans = NULL;
        
        while(curr){
            if(curr->data > x->data){
                ans = curr;
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
                
        }
        return ans;
    }
};
