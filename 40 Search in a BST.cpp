// link - https://leetcode.com/problems/search-in-a-binary-search-tree/description/
// Time Complexity - O(logN)
// Space Complexity - O(1)

class Solution {
public:
    TreeNode* searchBST(TreeNode* temp, int x) {
        while(temp != NULL)
        {
            if(temp->val == x)
                return temp;
            else if(temp->val < x)
                temp = temp->right;
            else
                temp = temp->left;
        }
        return temp;
        
    }
};
