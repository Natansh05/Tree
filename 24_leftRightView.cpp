// link - https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

void f(Node* root,int level,vector<int> &ans){
    if(root==NULL)
        return;
    if(level==ans.size())
        ans.push_back(root->data);
    f(root->left,level+1,ans);
    f(root->right,level+1,ans); // reverse for rightView
    return;
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    f(root,0,ans);
    return ans;
}
