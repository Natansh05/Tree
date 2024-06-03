// link - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
// Time Complexity - O(N)
// Space Complexity - O(N)


// get line aur string stream k bare me padhna hai

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // we will use level order traversal to make our string
        string ans = "";

        queue<TreeNode*> q;
        q.push(root);

        while(q.empty()==0){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL)
                ans+= "x,";
            else
                ans += to_string(temp->val) + ',';
            if(temp){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        string str;
        getline(s,str,',');
        if(str=="x")
            return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==0){
            TreeNode* temp = q.front();
            q.pop();

            getline(s,str,',');
            if(str!="x"){
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }
            getline(s,str,',');
            if(str!="x"){
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }
        }
        return root;
        
    }
};
