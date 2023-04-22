/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// DIAMETER = LONGEST PATH BETWEEN 2 NODES
// PATH DOESNT NEED TO PASS THROUGH ROOT NECESSARILY

class Solution {
    int findheight(TreeNode* root){
        if (root == NULL) return 0;
        
        return 1+max(findheight(root->left), findheight(root->right));
    }
public:
    int maxi=0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        int lh = findheight(root->left);
        
        int rh = findheight(root->right);
        
        maxi = max(maxi, lh+rh);
        
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return maxi;
        
    }
};