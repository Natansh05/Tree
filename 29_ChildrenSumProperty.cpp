// Time Complexity - O(N)
// Space Complexity - (N)

// link - DNE

void changeTree(Node* root){
  if(root==NULL)
      return;
  int child = 0;
  if(root->left)
      child+=root->left->data;
  if(root->right)
      child+=root->right->data;

  if(child>root->data)
    root->data = child;
  else{
    if(root->left)
      root->left->data = root->data;
    if(root->right)
      root->right->data = root->data;
  }

  changeTree(root->left);
  chanegTree(root->right);
  int tot = 0;
  if(root->left)
      tot+=root->left->data;
  if(root->right)
      tot+=root->right->data;

  if(tot > root->data)
      root->data = tot;
  
  
}
