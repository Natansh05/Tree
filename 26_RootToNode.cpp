// link - https://www.interviewbit.com/problems/path-to-given-node/

bool getPath(TreeNode* root,int x,vector<int> &ans){
    if(root==NULL)
        return 0;
    ans.push_back(root->val);
    if(root->val==x)
        return 1;
    
    if(getPath(root->left,x,ans) || getPath(root->right,x,ans))
        return true;
    ans.pop_back();
    return 0;
} 

vector<int> Solution::solve(TreeNode* root, int x) {
    vector<int> ans;
    getPath(root,x,ans);
    return ans;
}
