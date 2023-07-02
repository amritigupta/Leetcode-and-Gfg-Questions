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
class Solution {
    int findheight(TreeNode* root){
        if(root==NULL) return 0;
        
        int lh = findheight(root->left);
        int rh = findheight(root->right);
        
        return 1+max(lh,rh);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL){
            return true;
        }
        
        int lh = findheight(root->left);
        int rh = findheight(root->right);
        
        if (abs(lh-rh)>1){
            return false;
        }
        
        if (!isBalanced(root->left) || !isBalanced(root->right)){ //if either left or right is unbalanced
            return false;
        }
        
        return true;
    }
};