// link - https://www.geeksforgeeks.org/problems/floor-in-bst/1
// Time Complexity - O(logN)
// Space Complexity - O(1)

class Solution{

public:
    int floor(Node* root, int x) {
        int ans = -1;
        while(root){
            if(root->data<=x){
                ans = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return ans;
    }
};
